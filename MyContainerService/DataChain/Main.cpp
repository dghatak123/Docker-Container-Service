#include "DataBlockChain.h"
#include <unistd.h>

int main() {
    MyDataBlockChain bChain = MyDataBlockChain();
 
    cout << "Mining block 1..." << endl;
    const string _l_data1[3] = {"John M","01011980","San Antonio"};
    bChain.addDataBlock(MyDataBlock(1, _l_data1));
 
    cout << "Mining block 2..." << endl;
    const string _l_data2[3] = {"David N", "01011985", "San Jose"}; 
    bChain.addDataBlock(MyDataBlock(2, _l_data2));
 
    cout << "Mining block 3..." << endl;
    const string _l_data3[3] = {"Harry P", "01011990", "San Diego"};
    bChain.addDataBlock(MyDataBlock(3, _l_data3));

    sleep(3600);
 
    return 0;
}
