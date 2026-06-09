典型的斐波拉切数列函数，可由递归和非递归两种方式实现。
```
      1               n=1
f(n)= 2               n=2
      f(n-1) + f(n-2) n>=3
```
#### 分治法递归
> 缺陷，耗时长，当n=44时即超出时间限制；

```java
class Solution {
    public int climbStairs(int n) {
        if(n<=0){
            throw new IllegalArgumentException("value error");
        }
        return upFloor(n);
    }
    
    private int upFloor(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        return upFloor(n-1)+upFloor(n-2);
    }
}
```
#### 非递归实现
```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2) return n;
        int pre=1;
        int now=2;
        for(int i=3;i<=n;i++){
            int temp=now;
            now+=pre;
            pre=temp;
        }
        return now;
    }
};
```