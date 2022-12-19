本题思路比较简单，就是加了一个判定条件，如果是偶数，则激活偶数函数输出，如果是奇数，则激活奇数函数输出。这里要注意的一点是，在接受n的函数内，接收到以后因为要先输出0，其他偶数和奇数这个时候和输出零的函数是并列的，所以要对偶数和奇数函数加锁，不然会按照函数书写的顺序顺序执行。
class ZeroEvenOdd {
private:
    int n;
    std::mutex e,o,z;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        o.lock();
        e.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++){
            z.lock();
            printNumber(0);
            if(i%2==1){
                o.unlock();
            }else{
                e.unlock();
            }    
          
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i=i+2){
            e.lock();
            printNumber(i);
            z.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i=i+2){
            o.lock();
            printNumber(i);
            z.unlock();
        }
      
    }
};