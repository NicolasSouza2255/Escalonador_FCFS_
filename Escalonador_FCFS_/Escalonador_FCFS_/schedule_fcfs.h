#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// add a task to the list 
void addTask(struct node** head, struct task* newTask);

// invoke the scheduler
void schedule(struct node* head);
