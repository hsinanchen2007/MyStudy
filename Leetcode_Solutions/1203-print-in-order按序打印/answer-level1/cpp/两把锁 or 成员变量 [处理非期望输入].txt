## 互斥锁
由于需要`two()`在`one()`之前执行，所以`two()`必须等待`one()`执行后的某个条件达成，使用锁来实现同步。  
```c++
class Foo {
public:
    mutex smx;
    mutex tmx;
    Foo() {
     smx.lock();
     tmx.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        smx.unlock();
    }

    void second(function<void()> printSecond) {
        lock_guard<mutex> lg(smx);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        tmx.unlock();
    }

    void third(function<void()> printThird) {
        lock_guard<mutex> lg(tmx);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
```
可以这么理解，每个线程相当于一个人，执行代码相当于需要进到房间，执行`one()`这个人A房间对他不设防，可以直接进去，而执行`two()`的这个人B需要打开`smx`这个锁才能进去，而执行`three()`的这个人C需要打开两把锁才能进入。一开始门上是有两把锁的，所以一开始只有A能进入，出来之后想让B可以进入C不能进去，怎么办呢？可以让A出来之前把`smx`锁打开，然后B就可以进去了，C不能进去，然后B出来之前把`smx`和`tmx`都打开，然后C才能进去。

要注意的是，C尝试获得锁的时候顺序一定要是先获得`tmx`这个锁再获得`smx`这个锁，因为`smx`这个锁同时被B和C需要，否则A在打开了`smx`锁后立刻被C获得了后，由于没有B给C打开`tmx`这个锁，C会挂在`lock(tmx)`上，而后到来的B因为不能获得`smx`锁，会挂在`lock(smx)`上，于是就发生了死锁。
## 成员变量
用一个全局变量flag，标示当前是什么状态，状态1只能执行`one()`，状态2只能执行`two()`，状态3执行`three()`，然后到每个函数下改变状态即可。
```c++
class Foo {
public:
    volatile int flag;
    Foo() {
     flag = 1;
    }

    void first(function<void()> printFirst) {
        while (flag != 1);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag = 2;
    }

    void second(function<void()> printSecond) {
        while (flag != 2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag = 3;
    }

    void third(function<void()> printThird) {
        while(flag != 3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
```
## 成员变量-处理非期望输入

由于上面的使用成员变量作为状态标记的方法只适用于输入是`[1,2,3]`的全排列的情况，一旦输入出现**重复数字**的情况（如`[1,2,1,3]`），那么就会死循环。

和使用`mutex`的方法对比我们可以找出原因，使用`mutex`时，A出去之后“门”允许A和B都能进入，因为“门”不会因为A进去之后而改变A的访问权限，；而使用状态表示时，A进入之后就不能再进去了，因为状态变成了*只能B才能进入*，而根据题意显然**进入过“门”的“人”可以再次进入**。造成如此的原因是`!=`符号只能确定**一个状态**，而不能确定**一个集合的状态**，我们需要记录的状态是**此时“哪些人”可以进入“门”**而不是**此时“哪个人”可以进入“门”**。

我们可以使用`set<int>`记录谁被允许访问，通过在每个函数返回前加入下一个被允许进入的“人”。当然这个题直接用`<`作为`set.count()`的简化版本，使用`++`替代`set.add(next_id)`。

要注意的是，`thrid(...)`函数最后是否复原状态（就是`set.clear()`或`flag = 0`）决定了在A、B、C每个人都经过一次之后**是重新开始按1、2、3的顺序打印**还是**按线程调度的先后顺序*打印*。
```c++
class Foo {
public:
    volatile int flag;
    Foo() {
     flag = 1;
    }

    void first(function<void()> printFirst) {
        while (flag < 1);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag = 2;
    }

    void second(function<void()> printSecond) {
        while (flag < 2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag = 3;
    }

    void third(function<void()> printThird) {
        while(flag < 3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
```