```
import java.util.concurrent.*;
public class Foo {
     ConcurrentHashMap<String,String> map = new ConcurrentHashMap();

    public Foo() {
        map.put("flag","null");
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
            
                printFirst.run();    
            map.put("flag","one");
            
            
        
        
    }

    public void second(Runnable printSecond) throws InterruptedException {
        // printSecond.run() outputs "second". Do not change or remove this line.
        while(true){
            if(map.get("flag").contains("one")){
                printSecond.run();
                map.put("flag","onetwo");
                break;
            }
        }
            
        }
        
    

    public void third(Runnable printThird) throws InterruptedException {
        // printThird.run() outputs "third". Do not change or remove this line.
            while(true){
                if(map.get("flag").contains("two")){
                   printThird.run(); 
                     break;
                }
            }
                  
        
    }
}

```

  
