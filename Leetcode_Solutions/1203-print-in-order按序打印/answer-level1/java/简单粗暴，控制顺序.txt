### 
因为 题目要求 不管 调用顺序 怎么样 都是 输出 【one two three】
使用 自旋 已经 全局变量 控制顺序即可，但是 效率不高
### 代码

```java
class Foo {

   
    volatile int flag = 0; 
    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        
        for (;;) {
            if (flag == 0) {
                printFirst.run();
                flag = 1;
                break;
            }
           
        }
              
              
        
      
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
       for (;;) {
            if (flag == 1) {
                 printSecond.run();  
                flag = 2;
                break;
            }
           
        }
        
          
     
      
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
         
           for (;;) {
            if (flag == 2) {
                 printThird.run();
                flag = 3;
                break;
            }
           
        }
                            
                             
        
       
    }
}
```