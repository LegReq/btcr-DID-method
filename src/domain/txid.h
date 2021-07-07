#ifndef BTCR_DID_TXID_H
#define BTCR_DID_TXID_H


#include "blockHeight.h"
#include "../bitcoinRPCFacade.h"
#include "transactionIndex.h"
#include <memory>
#include <string>

/**
 * This class represents a TXID (transaction ID)
 */
class Txid {

public:

    /**
     * Construct a Txid from the txid string. Use BitcoinRPCFacade to
     * validate its existence.
     * @param inTxidStr the hexadecimal txid string
     * @param btc the BitcoinRPCFacade
     */
    Txid(const std::string & inTxidStr, const BitcoinRPCFacade & btc);

    /**
     * Get this Txid as a string
     * @return this Txid as a string
     */
    std::string asString() const;

    /**
     * Is this Txid in bitcoin mainnet or testnet?
     * @return true if Txid is in bitcoin testnet
     */
    bool isTestnet() const;

    std::shared_ptr<BlockHeight> blockHeight() const;

    std::shared_ptr<TransactionIndex> transactionIndex() const;

    bool operator==(const Txid &rhs) const;

    bool operator!=(const Txid &rhs) const;

private:

    /**
     * Checks the validity of the txid string.
     *
     * Validity means: must be 64 lowercase hexadecimal characters.
     *
     * @param inTxidStr the txid string to check
     * @return true if valid
     */
    bool isInputStringValid(const std::string & inTxidStr) const;

    /**
     * Checks if the txid really exists in the bitcoin network
     *
     * @param inTxidStr the txid string to check
     * @param btc the BitcoinRPCFacade
     * @return true if exists
     */
    bool existsInNetwork(const std::string & inTxidStr, const BitcoinRPCFacade & btc) const;

    /**
     * Get full transaction data from bitcoin network and initialize other class members
     *
     * @param inTxidStr the txid string
     * @param btc the BitcoinRPCFacade
     */
    void extractTransactionDetails(const std::string & inTxidStr, const BitcoinRPCFacade &btc);


    std::shared_ptr<BlockHeight> pBlockHeight;
    std::shared_ptr<TransactionIndex> pTransactionIndex;

    bool testnet;
    std::string txidStr;

};


#endif //BTCR_DID_TXID_H
