#include <ctime>
#include <vector>

using namespace std;


struct Transaction{
		double amount;
		string senderKey;
		string recieveKey;
		time_t timestamp;
};

class Block
{
private:
	int index;
	size_t blockHash;
	size_t previousHash;
	size_t generatehash();

public:
	//constructor
	Block(int idx, TransactionData d, size_t prevHash);

	size_t getHash();
	size_t getPreviousHash();
	TransactionData data;
	bool isHashValid();
};

class Blockchain
{
	private:
		Block createGenesisBlock();
		
	public:
		vector<Block> chain;

		Blockchain();

		void addBlock(TransactionData data);
		void isChainValid();

		Block *getLatestBlock();
};
