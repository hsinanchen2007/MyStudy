使用ReentrantLock
``` java
package cn.liulichao.leetcode.concurrency;

import cn.liulichao.leetcode.concurrency.util.Foo;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

/**
 * @auther liulichao@my.com
 * @since 2019/8/8
 * 执行结果：通过
 * 显示详情
 * 执行用时 :19 ms, 在所有 Java 提交中击败了82.34%的用户
 * 内存消耗 :35.8 MB, 在所有 Java 提交中击败了100.00%的用户
 */
public class PrintInOrder1114 {
    public static void main(String[] args){
        int[] arr=new int[]{2,3,1};
        print(arr);
    }
    public static void print(int[] arr) {
        Foo foo=new Foo();
        Thread first=new Thread(()->{ //实现Runnable接口
            try{
                foo.first(()->{ // 这里就是执行一个打印 没其他的
                    System.out.println("first");
                });
            }catch (InterruptedException e){
                System.out.println(e.getMessage());
            }

        });
        Thread second=new Thread(()->{
            try{
                foo.second(()->{
                    System.out.println("second");
                });
            }catch (InterruptedException e){
                System.out.println(e.getMessage());
            }

        });
        Thread third=new Thread(()->{
            try{
                foo.third(()->{
                    System.out.println("third");
                });
            }catch (InterruptedException e){
                System.out.println(e.getMessage());
            }

        });
        Map<Integer,Thread> map=new HashMap<Integer,Thread>();
        map.put(1,first);
        map.put(2,second);
        map.put(3,third);
        Arrays.stream(arr).forEach(num ->{
            map.get(num).start();
        });
    }
}
```
``` java
package cn.liulichao.leetcode.concurrency.util;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

/**
 * @auther liulichao@my.com
 * @since 2019/8/8
 */
public class Foo {
    private volatile  int i=0;
    private ReentrantLock lock=new ReentrantLock();
    private Condition condition1=lock.newCondition();
    private Condition condition2=lock.newCondition();
    private Condition condition3=lock.newCondition();
    public Foo() {

    }

    public void first(Runnable printFirst) throws InterruptedException {
        lock.lock();
        if(i!=0){
            condition1.await();
        }
        printFirst.run();
        i=1;
        condition2.signal();
        lock.unlock();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        lock.lock();
        if(i!=1){
            condition2.await();
        }
        printSecond.run();
        i=2;
        condition3.signal();
        lock.unlock();
    }

    public void third(Runnable printThird) throws InterruptedException {
        lock.lock();
        if(i!=2){
            condition3.await();
        }
        printThird.run();
        i=0;
        condition1.signal();
        lock.unlock();
    }
}
```