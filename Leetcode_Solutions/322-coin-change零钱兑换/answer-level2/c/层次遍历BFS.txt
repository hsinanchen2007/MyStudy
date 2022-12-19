```
#define min(x,y) x<y?x:y
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int coinChange(int* coins, int coinsSize, int amount){
    int i, j, next, curr, size, steps = 0, visited[10000]={0};
	int queue[10000];
	int rear = 0, front = 0;
	if (coinsSize == 0||amount==0)return 0;      
    qsort(coins,coinsSize,sizeof(int),cmpfunc);
    
    int minnum=coins[0];
    
    int maxstep=amount/minnum;
    queue[rear++]=0;
    visited[0]=1;
    while(rear!=front){
        steps++;
		size = rear-front;          //3.根据队列大小，得出该层有多少元素，依次出队，访问
		for (i = 0; i < size; i++) {
			curr = queue[front++];
			for (j = 0; j<coinsSize; j++) {//访问到节点后，做相应操作
				next = curr + coins[j];
				if (next == amount)return steps;
				if (next > amount)break;
				if (visited[next])continue;
			    visited[next] = 1;    //访问记录visited设置为1，并且入队
				queue[rear++] = next;
			}
		}
        if(steps>maxstep)return -1;                             //循环结束后继续回到while判断
	}
	free(queue);
	free(visited);
    
	return steps;

    }
```
