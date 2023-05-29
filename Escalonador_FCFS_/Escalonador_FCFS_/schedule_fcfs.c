#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "schedule_fcfs.h"
#include "task.h"
#include "CPU.h"

// add a task to the list 
void addTask(struct node** head, struct task* newTask) {
	// Cria��o do novo n�
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Erro: Falha ao alocar mem�ria para o novo n�.\n");
		return;
	}

	newNode->task = newTask;
	newNode->next = NULL;

	// Verifica se a lista est� vazia
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

		// Remove o n� atual da lista
		if (previous != NULL) {
			previous->next = current->next;
		}
		else {
			// Caso seja o primeiro n�, atualiza a cabe�a da lista
			head = current->next;
		}

		// Salva o pr�ximo n� antes de liberar a mem�ria
		struct node* nextNode = current->next;
		free(current);

		// Atualiza o n� atual para o pr�ximo n� da lista
		current = nextNode;
	}

	//error(current->task, 1);
	//current = current->next;  // Avan�a para a pr�xima tarefa

	// Atualiza o n� anterior
	previous = current;
}
