#include "DataBlock.h"
#include <vector>

class MyDataBlockChain {
  public:
   MyDataBlockChain();
   void addDataBlock(MyDataBlock newBlock);
  private:
   uint32_t _c_difficulty;
   vector<MyDataBlock> _c_chain;
   MyDataBlock getLastDataBlock() const;
};
