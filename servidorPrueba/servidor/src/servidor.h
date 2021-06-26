/*
 * servidor.h
 *
 *  Created on: 25 jun. 2021
 *      Author: utnso
 */

#ifndef SRC_SERVIDOR_H_
#define SRC_SERVIDOR_H_


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <semaphore.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>
#include <commons/collections/queue.h>
#include <string.h>

void iniciar_conexion();

void queue_sync_push(t_queue *, void *element);
void *queue_sync_pop(t_queue *);


#endif /* SRC_SERVIDOR_H_ */
