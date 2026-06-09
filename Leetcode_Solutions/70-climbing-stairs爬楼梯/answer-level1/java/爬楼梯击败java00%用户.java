### 解题思路
1.每一层楼梯的方法数至于上层、上上层有关，故只要记录上层、上上层的方法数即可算出。
2.省去了数组存储，利用两个变量记录之前计算的值。

### 代码

```java
class Solution {
    public int climbStairs(int n) {
        if(n<=2) return n;
        int pre2=1,pre1=2;
        int cur=0;
        for(int i=3;i<=n;i++){
            cur=pre2+pre1;
            pre2=pre1;
            pre1=cur;
        }
        return pre1;
    }
}
```