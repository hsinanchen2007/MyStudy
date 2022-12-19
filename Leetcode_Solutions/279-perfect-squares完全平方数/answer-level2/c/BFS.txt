```
#define MAX_NS 500000
typedef struct ns {
	int left;
	int minus;
	int level;
}NS;
NS ns_fifo[MAX_NS];
int ns_fifo_head = 0;
int ns_fifo_tail = 0;
int ns_fifo_size = 0;
bool nsEnQueue(NS *p) {
	int left = 0;
	int minus = 0;
	int level = 0;
	if (ns_fifo_size >= MAX_NS) {
		printf("EnQueue, out of range:%d, %d\n", ns_fifo_size, MAX_NS);
		return false;
	}
	ns_fifo_size++;
	ns_fifo[ns_fifo_tail].left = p->left;
	ns_fifo[ns_fifo_tail].minus = p->minus;
	ns_fifo[ns_fifo_tail].level = p->level;

	//printf("Pro elem: level:%02d, left:%03d, minus:%02d+++++at pos:%02d\n", p->level, p->left, p->minus, ns_fifo_tail);

	ns_fifo_tail++;
	ns_fifo_tail %= MAX_NS;

	return true;
}

bool nsDeQueue(NS *p) {
	int level;
	if (ns_fifo_size <= 0) {
		printf("EnQueue, out of range:%d, %d\n", ns_fifo_size, MAX_NS);
		return false;
	}
	ns_fifo_size--;
	p->left = ns_fifo[ns_fifo_head].left;
	p->minus = ns_fifo[ns_fifo_head].minus;
	p->level = ns_fifo[ns_fifo_head].level;
	
	//printf("Get elem: level:%02d, left:%03d, minus:%02d-----at pos:%02d\n", p->level, p->left, p->minus, ns_fifo_head);

	ns_fifo_head++;
	ns_fifo_head %= MAX_NS;

	return true;
}

int numSquares(int n){
	int left = 0;
	int minus = 0;
	int level = 0;
	int i = 0;
	NS cur = {0, 0, 0};
	NS tmp = {0, 0, 0};
	ns_fifo_head = 0;
	ns_fifo_tail = 0;
	ns_fifo_size = 0;
	minus = (int)sqrt(n);
    printf("input:%d, sqrt:%d\n", n, minus);
	cur.left = n;
	cur.minus = minus;
	cur.level = 0;
	nsEnQueue(&cur);
	while (nsDeQueue(&cur)) {
		for (i = cur.minus; i >= 1 ; i--) {
			left = cur.left - pow(i, 2);
			minus = (int)sqrt(left);
			level = cur.level;
			tmp.left = left;
			tmp.minus = minus;
			tmp.level = level + 1;

			//printf("\tTry elem: level:%02d, left:%03d, minus:%02d\n", tmp.level, tmp.left, tmp.minus);
			if (tmp.left < 0) {
				continue;
			}
			if (tmp.left == 0) {
				//printf("=====Get elem: level:%02d, left:%03d!!!!!\n", tmp.level, tmp.left);
				return tmp.level;
			}
			nsEnQueue(&tmp);
		}
	}
    return 0;
}
```

