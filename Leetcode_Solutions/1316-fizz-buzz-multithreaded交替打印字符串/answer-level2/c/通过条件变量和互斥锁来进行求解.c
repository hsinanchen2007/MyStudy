# 运算结果
执行用时 :12 ms, 在所有 c 提交中击败了96.67%的用户
内存消耗 :7.2 MB, 在所有 c 提交中击败了100.00%的用户

# 解题思路
1. 由于每个函数不是打印一次，所以需要用while循环`while(obj->index <= obj->n) {}`
2. 由于是满足一定的条件才能打印，因此调用`pthread_cond_wait`阻塞住当前线程，如果满足条件，才能往下运行
3. 如果当前索引越界了，则停止线程，这一点很重要，不然会**导致超时**
4. 如果索引有效，则打印相关的值，并唤醒其他线程工作
5. 最后唤醒所有的线程，让每个线程结束运行。



# 代码
```c
typedef struct {
    int n;
    int index;
    pthread_mutex_t mutex;
    pthread_cond_t fizzs,buzzs,fizzbuzzs,numbers;
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    obj->index = 1;
    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->fizzs,NULL);
    pthread_cond_init(&obj->buzzs,NULL);
    pthread_cond_init(&obj->fizzbuzzs,NULL);
    pthread_cond_init(&obj->numbers,NULL);
    return obj;
}

void process (FizzBuzz* obj) {

    if (obj->index > obj->n) {
        pthread_cond_signal(&obj->fizzbuzzs);
        pthread_cond_signal(&obj->fizzs);
        pthread_cond_signal(&obj->buzzs);
        pthread_cond_signal(&obj->numbers);
    }

    if (0 == obj->index%3 && 0 == obj->index%5) {
        pthread_cond_signal(&obj->fizzbuzzs);
    } else if (0 == obj->index%3) {
        pthread_cond_signal(&obj->fizzs);
    } else if (0 == obj->index%5) {
        pthread_cond_signal(&obj->buzzs);
    } else {
        pthread_cond_signal(&obj->numbers);
    }
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
    while(obj->index <= obj->n) {

        pthread_mutex_lock(&obj->mutex);

        while (0 != obj->index%3 && obj->index <= obj->n) {
            pthread_cond_wait(&obj->fizzs,&obj->mutex);
        }

        if (obj->index > obj->n) {
            pthread_mutex_unlock(&obj->mutex);
            break;
        } else {
            printFizz();
            obj->index++;

            process(obj);
            
            pthread_mutex_unlock(&obj->mutex);
        }
    }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
    while(obj->index <= obj->n) {

        pthread_mutex_lock(&obj->mutex);

        while (0 != obj->index%5 && obj->index <= obj->n) {
            pthread_cond_wait(&obj->buzzs,&obj->mutex);
        }

        if (obj->index > obj->n) {
            pthread_mutex_unlock(&obj->mutex);
            break;
        } else {
            printBuzz();
            obj->index++;

            process(obj);

            pthread_mutex_unlock(&obj->mutex);
        }
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
    while(obj->index <= obj->n) {

        pthread_mutex_lock(&obj->mutex);

        while (0 != obj->index%5 && 0 != obj->index%3 && obj->index <= obj->n) {
            pthread_cond_wait(&obj->fizzbuzzs,&obj->mutex);
        }

        if (obj->index > obj->n) {
            pthread_mutex_unlock(&obj->mutex);
            break;
        } else {
            printFizzBuzz();
            obj->index++;

            process(obj);

            pthread_mutex_unlock(&obj->mutex);
        }
    }
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    while(obj->index <= obj->n) {

        pthread_mutex_lock(&obj->mutex);

        while((0 == obj->index%3 || 0 == obj->index%5) && obj->index <= obj->n) {
            pthread_cond_wait(&obj->numbers,&obj->mutex);
        }

        if (obj->index > obj->n) {
            pthread_mutex_unlock(&obj->mutex);
            break;
        } else {
            printNumber(obj->index);
            obj->index++;

            process(obj);

            pthread_mutex_unlock(&obj->mutex);
        }
    }
}

void fizzBuzzFree(FizzBuzz* obj) {
    if (NULL != obj) {
        pthread_mutex_destroy(&obj->mutex);
        pthread_cond_destroy(&obj->fizzs);
        pthread_cond_destroy(&obj->buzzs);
        pthread_cond_destroy(&obj->fizzbuzzs);
        pthread_cond_destroy(&obj->numbers);
    }
}
```

# 另外一种解法
也可以只用互斥锁mutex来求解，也就是多定义几个mutex，一个线程加锁，另外一个线程解锁。

