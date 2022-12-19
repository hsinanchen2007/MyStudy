### 解题思路（从后向前）
　　设f(n)为n节台阶共有的跳法，若有1节台阶，则有1种跳法，两节台阶有两种跳法，3节台阶考虑最后一次跳两节，最后一次跳一节，则有f(3)=f(2)+f(1)...则n节台阶也是可分为最后一次跳两节，最后一次跳一节，则有f(n)=f(n-1)f(n-2)
　　可用递归(但时间耗费较大)

### 代码

```java
class Solution {
    public int numWays(int n) {
        //第一级台阶有一种跳法 前两级台阶有两种跳法
        //最后一步跳一步 最后一步跳两步
        if(n==0) return 1;
        if(n==1) return 1;
　　　　 //递归（但在本题时间超时）
        //return numWays(n-1)+numWays(n-2);
        int x=1,y=1,tmp=0;
        for(int i=2;i<=n;i++){
            tmp=(x+y)%1000000007;
            x=y;
            y=tmp;
         }
    return tmp;
    }
}
```
**扩展；**
　　变态跳台阶问题:每次可以跳一节，也可跳上两节......也可跳上n节，问有几种跳法？
**思路:**（从前向后）
　　设f(n)n节台阶的跳法，一节台阶一种跳法，两节台阶两种跳法，3节台阶可考虑为第一次跳一节，第一次跳两节，第一次跳三节，则可用f(3)=f(3-1)+f(3-2)+f(3-3)表示；4节台阶可分为第一次跳一节，第一次跳两节，第一次跳三节，第一次跳四节，f(4)=f(4-1)+f(4-2)+f(4-3);.....;则n节台阶有f(n)=f(n-1)-f(n-2)+f(n-3)+...+f(n-n)
**代码**(递归的思路)
```java
 public int JumpFloorII(int target) {
        int m=0;
        if(target==0) return 1;
        if(target==1) return 1;
        if(target==2) return 2;
        
        for(int i=1;i<=target;i++){
            m+=JumpFloorII(target-i);
        }
        return m;
    }
```
结语：如有不足请多指教