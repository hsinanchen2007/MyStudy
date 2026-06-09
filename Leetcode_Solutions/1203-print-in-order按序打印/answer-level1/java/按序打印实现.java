### 解题思路
此处撰写解题思路
1. 乱序执行 -> 顺序执行 = 使用一个共用的顺序标识进行排序
2. 考虑**操作安全性** 使用AtomInteger， 以及题解中是**使用同个对象执行多个不同方法的线程**使用private
3. 为了提高性能，使用 **==** 而非 **！=**
4. 为了提高性能，通过使用**white（true） if (==) {break;}** 保障成功执行一次后即结束

### 代码

```java
class Foo {

    public Foo() {
        
    }

    private AtomicInteger step = new AtomicInteger(0);

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        step.set(1);
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (true) {
            if (step.get() == 1) {
                // printSecond.run() outputs "second". Do not change or remove this line.
                printSecond.run();
                step.set(2);
                break;
            }
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (true) {
            if (step.get() == 2) {
                // printThird.run() outputs "third". Do not change or remove this line.
                printThird.run();
                break;
            }
        }
    }
}
```