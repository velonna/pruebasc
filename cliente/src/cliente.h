/*
 * cliente.h
 *
 *  Created on: 25 jun. 2021
 *      Author: utnso
 */

#ifndef SRC_CLIENTE_H_
#define SRC_CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <semaphore.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <memory.h>
#include <commons/collections/queue.h>

#define MAXUSERNAME 30
#define MAX_MESSAGE_SIZE 300

typedef enum
{
	MENSAJE = 1,
}op_code;

typedef struct
{
	int size;
	void* stream;
} t_buffer;

typedef struct
{
	op_code codigo_operacion;
	t_buffer* buffer;
} t_paquete;

typedef struct _t_Package {
	char* username;
	uint32_t username_long;
	char* message;
	uint32_t message_long;
	uint32_t total_size;			// NOTA: Es calculable. Aca lo tenemos por fines didacticos!
} t_Package;

char* serializarOperandos(t_Package*);
void get_Username(char**);
void fill_package(t_Package*, char**);
void dispose_package(char**);
int serializar(int serverSocket);
void iniciar_conexion();
void comunicarse();
void queue_sync_push(t_queue *, void *element);
void *queue_sync_pop(t_queue *);

#endif /* SRC_CLIENTE_H_ */
