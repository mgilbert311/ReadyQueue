/* queue.c - enqueue, dequeue, isempty, nonempty, et al. */

#include <xinu.h>
#include <stdlib.h>

/**
 * Prints out contents of a queue
 * @param q	pointer to a queue
 */
void	printqueue(struct queue *q)
{
	//TODO - print all contents from head to tail
	int i;
	kprintf("[");
	for(i=0; i < q->size; i++){
		kprintf("(pid=%d), ", q[i]);
	}
	kprintf("]");
	//TODO - format should be [(pid=p1), (pid=p2), ...]
}

/**
 * Checks whether queue is empty
 * @param q	Pointer to a queue
 * @return TRUE if true, FALSE otherwise
 */
bool8	isempty(struct queue *q)
{
	//TODO
	if(q->head != Null){
		return TRUE;
	}else{
		return FALSE;
	}
}

/**
 * Checks whether queue is nonempty
 * @param q	Pointer to a queue
 * @return TRUE if true, FALSE otherwise
 */
bool8	nonempty(struct queue *q)
{
	//TODO - don't just check q's size because q could be NULL
	if(q->head != NULL){
		return TRUE;
	}
	return FALSE;
	
}


/**
 * Checks whether queue is full
 * @param q	Pointer to a queue
 * @return TRUE if true, FALSE otherwise
 */
bool8	isfull(struct queue *q)
{
	//TODO - check if there are at least NPROC processes in the queue
	if(q->size == NPROC){
		return TRUE;
	}
	return FALSE;
}


/**
 * Insert a process at the tail of a queue
 * @param pid	ID process to insert
 * @param q	Pointer to the queue to use
 *
 * @return pid on success, SYSERR otherwise
 */
pid32 enqueue(pid32 pid, struct queue *q)
{
        //check if queue is full and if pid is illegal, and return SYSERR if either is true
		if(isfull(q) || isbadpid(pid)){
			return SYSERR;
		}
        //TODO - allocate space on heap for a new QEntry
		struct qentry *newEntry;
		newEntry = (struct qentry*)malloc(sizeof(struct qentry));
		//initialize the new QEntry
		newEntry->pid = pid;
		newEntry->prev = q->tail;
		newEntry->next = NULL;
		//insert into tail of queue
		//If the queue is empty, insert as the head
		if(isempty(q)){
			q->head = newEntry;
			q->tail = newEntry;
		}else{
			//Can i do this?
			//Set the pointer of the tail to the new entry
			q->tail->next = newEntry;
			//The new tail is the entry we added
			q->tail = newEntry;
		}

        //return the pid on success
        return pid;
}


/**
 * Remove and return the first process on a list
 * @param q	Pointer to the queue to use
 * @return pid of the process removed, or EMPTY if queue is empty
 */
pid32 dequeue(struct queue *q)
{
        //return EMPTY if queue is empty
		if(isempty(q)){
			return EMPTY;
		}
		
		//get the head entry of the queue
		struct qentry *temp;
		temp = q->head;
		pid32 tempPID = temp->pid;
		//unlink the head entry from the rest
		q->head = q->head->next;
		//free up the space on the heap
		free(temp, sizeof(temp));

        //return the pid on success
        return tempPID;
}


/**
 * Finds a queue entry given pid
 * @param pid	a process ID
 * @param q	a pointer to a queue
 * @return pointer to the entry if found, NULL otherwise
 */
struct qentry *getbypid(pid32 pid, struct queue *q)
{
	//return NULL if queue is empty or if an illegal pid is given
	if(isempty(q) || isbadpid(pid)){
		return NULL;
	}
	struct qentry *temp;
	temp = q->head;
	//find the qentry with the given pid, loop through the size of the queue
	int i;
	for(i=0; i < q->size; i++){
		if(temp->pid == pid){
			//return a pointer to it
			return temp->pid;
		}
		temp = temp->next;
	}
	//If not found
	return NULL;

}

/**
 * Remove a process from the front of a queue (pid assumed valid with no check)
 * @param q	pointer to a queue
 * @return pid on success, EMPTY if queue is empty
 */
pid32	getfirst(struct queue *q)
{
	//return EMPTY if queue is empty
	if(isempty(q)){
		return EMPTY;
	}
	//pid32 tempPID;
	//tempPID = dequeue(q);
	
	//remove process from head of queue and return its pid
	return dequeue(q);
}

/**
 * Remove a process from the end of a queue (pid assumed valid with no check)
 * @param q	Pointer to the queue
 * @return pid on success, EMPTY otherwise
 */
pid32	getlast(struct queue *q)
{
	//return EMPTY if queue is empty
	if(isempty(q)){
		return EMPTY;
	}
	
	//remove process from tail of queue and return its pid
	return dequeue(q->tail);
	
}



/**
 * Remove a process from an arbitrary point in a queue
 * @param pid	ID of process to remove
 * @param q	Pointer to the queue
 * @return pid on success, SYSERR if pid is not found
 */
pid32	remove(pid32 pid, struct queue *q)
{
	//return EMPTY if queue is empty
	if(isempty(q)){
		return EMPTY;
	}
	//return SYSERR if pid is illegal
	if(isbadpid(pid)){
		return SYSERR;
	}
	
	int i;
	//Maybe should be <NPROC?
	for(i=0; i<q->size; i++){
		if(
	}

	//remove process identified by pid parameter from the queue and return its pid

	//TODO - if pid does not exist in the queue, return SYSERR
}
