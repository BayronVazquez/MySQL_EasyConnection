#include "ConexionMySQL.h"

ConexionMySQL::ConexionMySQL()
{
    //Default Port and Protocol
    this->PORT  = "3306";
    this->PROTO = "tcp";
    this->IP_SERVER = "127.0.0.1";
}

string ConexionMySQL::getIP_SERVER() const
{
    return IP_SERVER;
}

void ConexionMySQL::setIP_SERVER(const string &value)
{
    IP_SERVER = value;
}

string ConexionMySQL::getDATABASE() const
{
    return DATABASE;
}

void ConexionMySQL::setDATABASE(const string &value)
{
    DATABASE = value;
}

string ConexionMySQL::getPASSWORD() const
{
    return PASSWORD;
}

void ConexionMySQL::setPASSWORD(const string &value)
{
    PASSWORD = value;
}

string ConexionMySQL::getUSERNAME() const
{
    return USERNAME;
}

void ConexionMySQL::setUSERNAME(const string &value)
{
    USERNAME = value;
}

string ConexionMySQL::getPROTO() const
{
    return PROTO;
}

void ConexionMySQL::setPROTO(const string &value)
{
    PROTO = value;
}

string ConexionMySQL::getPORT() const
{
    return PORT;
}

void ConexionMySQL::setPORT(const string &value)
{
    PORT = value;
}

int ConexionMySQL::connectServer()
{
    try {
        this->driver = get_driver_instance();
        this->connection = this->driver->connect( PROTO+"://"+IP_SERVER+":"+PORT, this->USERNAME, this->PASSWORD );

        //Seleccion de la DB
        connection->setSchema(this->DATABASE);

        //Parte del consulta
        this->stmt = this->connection->createStatement();

    } catch (sql::SQLException &e) {
        cout << "ERROR: " << e.what() << endl;
        cout << "MySQL error code: " << e.getErrorCode() << endl;
        cout << "SQLState: " << e.getSQLState() << endl;
    }
    return EXIT_SUCCESS;
}

sql::ResultSet* ConexionMySQL::executeQuery(const string &value)
{
    return this->resultset = this->stmt->executeQuery(value);
}

void ConexionMySQL::executeCommand(const string &value){
    this->stmt->execute(value);
}

ConexionMySQL::~ConexionMySQL()
{
    delete stmt;
    delete resultset;
    delete connection;
}
