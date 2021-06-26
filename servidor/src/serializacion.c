/*
 * serializacion.c
 *
 *  Created on: 25 jun. 2021
 *      Author: utnso
 */




/*
 * 	Deserializando estructuras dinamicas
 * 	(leer previamente ¿Por que serializacion dinamica? en el comentario de la serializacion)
 *
 * 	De la misma forma que no existe una sola forma de serializar las estructuras, tampoco de serializarlas. En este caso, realizaremos una deserializacion
 * 	a medida que vamos recibiendo el paquete.
 * 	Para esto es necesario conocer lo siguiente: Si el emisor nos envia un paquete con "ABCDE" y uno lee 2 caracteres, en el buffer interno del sistema quedara
 * 	"CDE" para leer. Por lo tanto, la proxima vez que leamos un caracter, obtendremos "C".
 *
 * 	Aprovechamos eso para modelar la siguiente solucion: Recibiremos la cantidad de caracteres a leer previo a los caracteres, por lo tanto, sabremos cuanto es
 * 	el largo de cada uno de los strings que nos enviaron.
 * 	¿Por que no nos enviaron un MAX_SIZE? Porque nos conectamos en red, y no esta bueno leer, por ejemplo, 300 caracteres, para solamente utilizar 15.
 *
 *//*
int recieve_and_deserialize(t_Package *package, int socketCliente){

	int status;
	int buffer_size;
	char *buffer = malloc(buffer_size = sizeof(uint32_t));

	uint32_t username_long;
	status = recv(socketCliente, buffer, sizeof(package->username_long), 0);
	memcpy(&(username_long), buffer, buffer_size);
	if (!status) return 0;

	status = recv(socketCliente, package->username, username_long, 0);
	if (!status) return 0;

	uint32_t message_long;
	status = recv(socketCliente, buffer, sizeof(package->message_long), 0);
	memcpy(&(message_long), buffer, buffer_size);
	if (!status) return 0;

	status = recv(socketCliente, package->message, message_long, 0);
	if (!status) return 0;


	free(buffer);

	return status;
}*/

