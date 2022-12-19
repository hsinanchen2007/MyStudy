### 解题思路
两个条件变量，一个互斥量。
互斥量控制临界资源访问的唯一性， 条件变量控制临界资源访问的时序性。
条件变量一个判空，一个判满。
注意，这里要考虑条件变量的惊群问题，必须在while循环中wait

记住口诀，口诀是现编的。
临界资源必加锁，两个条件互等待
读时循环等判空，写时循环等判满
读完解一满等待，写完解一读等待

下面解释一下条件变量的惊群现象， 当多个线程等待在一个条件变量时，比如当前队列为空，多个读线程在rcond的阻塞队列中。这时如果一个写线程写了数据到队列中，并且发出了一个pthread_cond_signal(&rcond); 直觉上认为是一个读线程被唤醒，但实际上并非如此，pthread_cond_signal也可能激活多个读线程去竞争资源。这就是惊群现象。

那么为什么放在while循环里可以解决惊群问题么？我们要从头捋一下这个加锁和等待条件变量的过程。
以写操作为例
1. 对互斥量加锁，如果当前已经有线程正持有mutex的锁，那么当前读线程会添加到mutex的阻塞队列中，直到对mutex加锁成功。
2. 加锁成功，进入临界区，如果当前队列已满，则等待wcond条件变量，线程添加到wcond的阻塞队列中。
3. 如果有一个读线程释放了signal信号，一批写线程被唤醒，会从wcond的阻塞队列移到mutex的阻塞队列中，继续尝试对mutex加锁来获取访问临界资源的权限。
4. 对mutex加锁成功后，才有权利向队列中写数据。所以这里要循环判断队列是否仍为满，因为有可能其他被唤醒的线程先获取到了锁，对队列做了写操作，此时队列又一次变满，当前写线程再一次等待wcond信号，被放到wcond的阻塞队列中。
试想一下，如果代码中的while是if的话，会出什么情况？
在step3时会有多个写线程被唤醒，从wcond阻塞队列移动到mutex的阻塞队列中，这些在mutex的阻塞队列中的写线程终将会获取到锁，如果不再次判断条件的话，队列的长度会大于max_size;

读操作同理.
### 代码

```cpp
class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        max_size = capacity;
        pthread_mutex_init(&mutex, 0);
        pthread_cond_init(&rcond, 0);
        pthread_cond_init(&wcond, 0);
    }
    
    void enqueue(int element) {
        pthread_mutex_lock(&mutex);
        while (data.size() == max_size) {        // 处理条件变量wcond惊群问题
            pthread_cond_wait(&wcond, &mutex);
        }
        data.push(element);
        pthread_cond_signal(&rcond);
        pthread_mutex_unlock(&mutex);
    }
    
    int dequeue() {
        pthread_mutex_lock(&mutex);
        while (!data.size()) {                    // 处理条件变量rcond惊群问题
            pthread_cond_wait(&rcond, &mutex);
        }
        int val = data.front(); data.pop();
        pthread_cond_signal(&wcond);
        pthread_mutex_unlock(&mutex);
        return val;
    }
    
    int size() {
        return data.size();
    }
private:
    pthread_mutex_t mutex;
    pthread_cond_t rcond;
    pthread_cond_t wcond;
    int max_size;
    queue<int> data;
};
```