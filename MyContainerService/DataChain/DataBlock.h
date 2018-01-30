#include <cstdint>
#include <iostream>

using namespace std;

class MyDataBlock {
public:
  string _c_prevDataHash;
  MyDataBlock (uint32_t _l_indexIn, const string *_l_dataIn);
  string getHash();
  void mineDataBlock(uint32_t _l_difficulty);

private:
  uint32_t _c_index;
  int64_t   _c_Nonce;
  string    _c_data[3] = { "\0","\0","\0"};
  string    _c_hash;
  time_t    _c_time;

  string calculateHash() const;
};
