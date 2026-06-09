### 解题思路
关注他一起学习数据结构和算法
https://www.zhihu.com/people/god-jiang

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        if(n==2){
            return 1;
        }else if(n==3){
            return 2;
        }
        long res=1;
        while(n>4){
            n-=3;
            res=(res*3)%1000000007;
        }
        return (int)((res*n)%1000000007);
    }
}
```