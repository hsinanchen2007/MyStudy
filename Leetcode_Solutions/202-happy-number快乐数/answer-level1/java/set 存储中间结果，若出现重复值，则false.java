# 方法 ： set
- 定义一个Set集合，用来存放计算后的平方和;
- 如果该值在Set中已存在，即进入了死循环，则退出，返回 false； 
- 否则，将该值放入Set；
- 若该值等于 1， 则返回true；
- 否则继续计算新的值的平方和，直至找到平方和为1或者进入死循环就退出。


```java []
class Solution {
    public boolean isHappy(int n) {
        Set<Integer> s = new HashSet<>();

        int res = n;
        while(res != 1){
            n = res;
            res = 0;
            
            if(s.contains(n)) return false;
            s.add(n); 
            
            while(n!=0){
                res += (n%10) * (n%10);
                n /= 10;
            }
        }
        
        return true;
    }
}
```

或者

```java []
class Solution {
    public boolean isHappy(int n) {

        Set<Integer> s = new HashSet<>();
        s.add(n);
        
        int res = 0;
        while(true){  
            if(n == 1) return true;
            
            res = 0;
            while(n!=0){
                res += (n%10) * (n%10);
                n /= 10;
            }
            
            if(s.contains(res)) return false;
            s.add(res); 
            n = res;
        }
    }
}
```

