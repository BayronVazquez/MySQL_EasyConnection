#ifndef ConexionMySQL_H
#define ConexionMySQL_H

#include <string>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

class ConexionMySQL
{
private:
    string USERNAME;
    string PASSWORD;
    string DATABASE;
    string IP_SERVER;
    string PROTO;
    string PORT;

    sql::Driver * driver;
    sql::Connection * connection;
    sql::Statement * stmt;
    sql::ResultSet * resultset;
public:
    ConexionMySQL();

    string getIP_SERVER() const;
    void setIP_SERVER(const string &value);

    string getDATABASE() const;
    void setDATABASE(const string &value);

    string getPASSWORD() const;
    void setPASSWORD(const string &value);

    string getUSERNAME() const;
    void setUSERNAME(const string &value);

    string getPROTO() const;
    void setPROTO(const string &value);

    string getPORT() const;
    void setPORT(const string &value);

    int connectServer();
    sql::ResultSet* executeQuery(const string &value);
    void executeCommand(const string &value);


    ~ConexionMySQL();
};

#endif // ConexionMySQL_H
