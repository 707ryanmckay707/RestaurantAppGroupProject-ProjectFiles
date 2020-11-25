//
// Created by Admin on 11/08/2020.
//

#include <fstream>
#include <cstdio>
#include "PartyDMA.hpp"


PartyDMA::PartyDMA() {
    setFilePath("../restaurant-cs370/JSON_files/waitlist.txt");
    fileDownload("http://localhost:3000/api/party/1");
    for(auto i: *ListOfParties()){
        i->_name();
    }
}

bool PartyDMA::addParty(std::string name, int id, int size) {
    PartyDMO *party = new PartyDMO;
    party->name = name;
    party->id = id;
    party->size = size;
    //add to database
    std::vector<QString> url;
    url.push_back("party");
    url.push_back("1");                         // rest id
    url.push_back(QString::fromStdString(name));
    url.push_back(QString::number(size));
    //fileDownload();

    ListOfParties()->push_back(party);
    return true;
}

bool PartyDMA::removeParty(int id) {
    for (auto i : *ListOfParties()) {
        if (i->_id() == id) {
            //ListOfParties()->pop_back(i->_id());
            return true;
        }
        return false;
    }
}
