```c
int numSquares(int n){ 
    int count = 1; // 所需要的完全平方数的个数，最小为1
    
    if (pow((int)sqrt(n), 2) == n) { // 若n本身就是一个完全平方数
        return count;
    }
    
    int queueSize = 1; // 记录queue的内存大小
    int* queue = (int*)malloc(sizeof(int));
    queue[0] = n; // n入队列
    
    int numOfRemains = 1; // 记录当前深度内的待处理个体数
    int numOfNext = 0; // 记录下一深度待处理个体数
    
    int head = 0, tail = 0; // queue的指针
    while (head <= tail) {
        count++;
        for (int k = numOfRemains; k > 0; --k) {
            
            int t = queue[head];
            head++;

            int upper = (int)sqrt(t); // t中所能包含的最大完全平方数的开方数
            
            queue = (int*)realloc(queue, (queueSize += upper) * sizeof(int)); // 重新分配内存以容纳更多的个体
            
            for (int i = upper; i > 0; --i) {
                int num = t - pow(i, 2);

                if (pow((int)sqrt(num), 2) == num) {
                    free(queue); // 返回count之前，释放内存
                    return count;
                }

                tail++;
                queue[tail] = num;

                numOfNext++;
            }
        }
        numOfRemains = numOfNext;
        numOfNext = 0;
        
    }
    return; // 此处return仅为编译通过，因为返回必然在while之内
}
```
