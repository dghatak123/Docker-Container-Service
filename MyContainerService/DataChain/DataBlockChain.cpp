#include "DataBlockChain.h"

MyDataBlockChain::MyDataBlockChain(){
  const string _l_data0[3] = {"Harrison F","01011975","San Fransisco"};
  _c_chain.emplace_back(MyDataBlock(0,_l_data0));
  _c_difficulty = 3;
}

void 
MyDataBlockChain::addDataBlock(MyDataBlock newBlock) {
  //cout << "Here 1"<<endl;
  newBlock._c_prevDataHash = getLastDataBlock().getHash();
  //cout << "Here 2 Prev Data Hash: "<<newBlock._c_prevDataHash<<endl;
  newBlock.mineDataBlock(_c_difficulty);
  //cout << "Here 3"<<endl;
  _c_chain.push_back(newBlock);
  //cout << "Here 4"<<endl;
}

MyDataBlock MyDataBlockChain::getLastDataBlock() const {
  return _c_chain.back();
}

