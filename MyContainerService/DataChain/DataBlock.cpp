#include "DataBlock.h"
#include "sha256.h"
#include <sstream>
#include <string.h>

using namespace std;

MyDataBlock::MyDataBlock(uint32_t _l_indexIn, const string *dataIn): _c_index(_l_indexIn)
{
   _c_Nonce = 0;
   _c_time = time(nullptr);
   for (int i=0; i<3; i++) {
      _c_data[i] = dataIn[i];
   }
}

string MyDataBlock::getHash()
{
   return _c_hash;
}

void MyDataBlock::mineDataBlock(uint32_t _l_difficulty) {
  char _l_str[_l_difficulty + 1];
  for (uint32_t i =0; i < _l_difficulty; ++i) {
    _l_str[i] = '0';
  }
  _l_str[_l_difficulty] = '\0';

  string str(_l_str);

  //do {
    _c_Nonce++;
    _c_hash = calculateHash();
    cout << "Hash "<<_c_hash <<endl;
    cout << "str "<<str<<endl;
  //} while ( _c_hash.substr(0,_l_difficulty) != str);
  
  cout << "Block mined " << _c_hash << endl;
}

inline string MyDataBlock::calculateHash() const {
    stringstream ss;
    cout << "Inside calculateHash()"<< endl;
    cout << _c_index << _c_time << endl;
    ss << _c_index << _c_time << _c_data[0] <<_c_data[1] << _c_data[2] << _c_Nonce << _c_prevDataHash;
    //char *s_str = new char[500];
    //strcpy(s_str,ss.str().c_str());
    SHA256 l_sha;
    size_t numBytes = sizeof(ss.str().c_str());
    cout << "String Stream value "<<ss.str().c_str()<<endl;
    cout << "numBytes "<<numBytes << endl;
    //return l_sha.getHash(ss.str().c_str(),numBytes);
    return string(l_sha.getSHA256(ss.str().c_str(),numBytes));
}
