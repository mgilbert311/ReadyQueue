/* queue.h */

/* Queue structure declarations, constants, and inline functions	*/

/* Default # of queue entries: 1 per process plus 2 for ready list plus	*/
/*			2 for sleep list plus 2 per semaphore		*/

#ifndef NQENT
#define NQENT	(NPROC + 4 + NSEM + NSEM)
#endif

#define	EMPTY	(-1)		/* null value for qnext or qprev index	*/


//define queue's data members
struct queue
{
	//pointer to head qentry
	struct qentry *head;
	//pointer to tail qentry
	struct qentry *tail;
	//size of queue
	int32 size;
};


//define a queue entry's data members
struct qentry
{
	// process ID
	pid32 pid;
	// Pointers to next and previous queue entries
	struct qentry *next;
	struct qentry *prev;
	
};


/* Queue function prototypes (don't touch!) */
void    printqueue(struct queue *q);

bool8	isempty(struct queue *q);
bool8	nonempty(struct queue *q);
bool8	isfull(struct queue *q);

pid32	getfirst(struct queue *q);
pid32	getlast(struct queue *q);
pid32	remove(pid32 pid, struct queue *q);
pid32	dequeue(struct queue *q);
pid32	enqueue(pid32 pid, struct queue *q);

struct queue	*newqueue();
struct qentry	*getbypid(pid32 pid, struct queue *q);
