gcc -lstdc++ \
    -o MyDataChain \
    -std=c++11 \
    -x c++ \
    -I /home/holuser/MyContainerService/DataChain \
    Main.cpp DataBlock.cpp DataBlockChain.cpp sha256.cpp
