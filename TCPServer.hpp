/*
 * TCPstream.h
 *
 *  Created on: 1 Sep 2017
 *      Author: bogdan
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>

using namespace std;
#define MAXPACKETSIZE 4096

#ifndef TCPSERVER_H_
#define TCPSERVER_H_


class TCPServer
{
public:
	int sockfd, newsockfd, n ,pid ;
	struct sockaddr_in serverAddress;
	struct sockaddr_in clientAddress;
	pthread_t serverThread;
	char msg[MAXPACKETSIZE];
	static string Message;


	void setup(int port);
	string receive();
	string getMessage();
	void Send(string msg);
	void detach();
	void clean();

private:
	static void *Task(void* argv);
};

#endif /* TCPSERVER_H_ */
