#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "schedule_fcfs.h"
#include "task.h"
#include "CPU.h"

// add a task to the list 
void addTask(struct node** head, struct task* newTask) {
	// Criação do novo nó
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Erro: Falha ao alocar memória para o novo nó.\n");
		return;
	}

	newNode->task = newTask;
	newNode->next = NULL;

	// Verifica se a lista está vazia
	if (*head == NULL) {
		*head = newNode;
	}
	else {
		struct node* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

// invoke the scheduler
void schedule(struct node* head) {
	struct node* current = head;
	struct node* previous = NULL;

	while (current != NULL) {
		run(current->task, 1);

		// Remove o nó atual da lista
		if (previous != NULL) {
			previous->next = current->next;
		}
		else {
			// Caso seja o primeiro nó, atualiza a cabeça da lista
			head = current->next;
		}

		// Salva o próximo nó antes de liberar a memória
		struct node* nextNode = current->next;
		free(current);

		// Atualiza o nó atual para o próximo nó da lista
		current = nextNode;
	}

	//error(current->task, 1);
	//current = current->next;  // Avança para a próxima tarefa

	// Atualiza o nó anterior
	previous = current;
}
