```
class Foo {
    mutex mtx;
    condition_variable cv;
    int lala;
public:
    Foo():lala(0) {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lck(mtx);
        lala=1;
        printFirst();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lck(mtx);
        while(lala!=1&&lala!=2){
            cv.wait(lck);
        }
        lala=2;
        printSecond();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lck(mtx);
        while(lala!=2&&lala!=3){
            cv.wait(lck);
        }
        lala=3;
        printThird();
    }
};
```
