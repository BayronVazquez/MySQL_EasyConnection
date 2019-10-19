#include <iostream>
#include "ConexionMySQL.h"

using namespace std;

int main()
{

    // Ejemplo de Conexion con MySQL
    ConexionMySQL con;
    sql::ResultSet *result;

    con.setDATABASE("MyDatabase");
    con.setUSERNAME("MyUser");
    con.setPASSWORD("MyPasssword");
    con.connectServer();

    result = con.executeQuery("SELECT * FROM MyTable");

    while(result->next()){
        //Se pueden seleccionar los campos por indice o por nombre
        cout << result->getInt(1) << "\t"<< result->getString("ID_Persona") << endl;
    }
    
    return 0;
}
