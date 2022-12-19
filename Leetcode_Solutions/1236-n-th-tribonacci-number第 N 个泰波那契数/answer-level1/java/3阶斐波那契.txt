### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int tribonacci(int n) {
        int t0=0,t1=1,t2=1,sum;
        if (n == 0 ){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        for(int i = 2; i<=n; i++){
            sum=t0+t1+t2;
            t0=t1;
            t1=t2;
            t2=sum;
        }
        return t1;
    }
}
```