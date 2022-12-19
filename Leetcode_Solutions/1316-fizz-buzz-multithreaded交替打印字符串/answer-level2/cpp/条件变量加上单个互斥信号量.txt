### 解题思路
单个条件变量 加上单个互斥信号量

### 代码

pthread_cond_t rdy =  PTHREAD_COND_INITIALIZER;
pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
static int cnt = 1;
typedef struct {
    int n;
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    cnt = 1;
    return obj;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {
    while(1)
    {
    pthread_mutex_lock(&mu);
    if(cnt > obj->n)
    {
        pthread_mutex_unlock(&mu);
        pthread_exit(NULL);
    }
    while((cnt %3) || (cnt %5 == 0))
    {

        pthread_cond_wait(&rdy , &mu);
    if(cnt > obj->n)
    {
        pthread_mutex_unlock(&mu);
  pthread_exit(NULL);
    }
    }

    printFizz();
    cnt++;
    pthread_mutex_unlock(&mu);
    pthread_cond_broadcast(&rdy);


    }
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {

        while(1)
    {
    pthread_mutex_lock(&mu);
    if(cnt > obj->n)
    {
        pthread_mutex_unlock(&mu);
  pthread_exit(NULL);
    }
    while((cnt %5) || (cnt %3 == 0))
    {

        pthread_cond_wait(&rdy , &mu);
    if(cnt > obj->n)
    {
        pthread_mutex_unlock(&mu);
  pthread_exit(NULL);
    }
    }

    printBuzz();
    cnt++;
    pthread_mutex_unlock(&mu);
    pthread_cond_broadcast(&rdy);


    }
    
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {
        while(1)
    {
    pthread_mutex_lock(&mu);
    if(cnt > obj->n)
    {
        pthread_mutex_unlock(&mu);
  pthread_exit(NULL);
    }
    while(cnt %5 || cnt %3)
    {
        pthread_cond_wait(&rdy , &mu);
        if(cnt > obj->n)
    {
        pthread_mutex_unlock(&mu);
  pthread_exit(NULL);
    }
    }

    printFizzBuzz();
    cnt++;
    pthread_mutex_unlock(&mu);
    pthread_cond_broadcast(&rdy);


    }  
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    while(1)
    {
    pthread_mutex_lock(&mu);
    if(cnt > obj->n)
    {
        pthread_mutex_unlock(&mu);
  pthread_exit(NULL);
    }
    while((cnt %5 == 0) || (cnt %3 == 0 ))
    {

        pthread_cond_wait(&rdy , &mu);
    if(cnt > obj->n)
    {
        pthread_mutex_unlock(&mu);
  pthread_exit(NULL);
    }
    }

    printNumber(cnt);
    cnt++;
    pthread_mutex_unlock(&mu);
    pthread_cond_broadcast(&rdy);


    }  
}

void fizzBuzzFree(FizzBuzz* obj) {
    free(obj);
}
```