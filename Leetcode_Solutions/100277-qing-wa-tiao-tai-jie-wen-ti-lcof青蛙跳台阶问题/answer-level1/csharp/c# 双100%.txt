第二次双100%,有点开心.这道题困扰了我好久,以前学的排列组合都还给老师,百思不得其解.后来终于想出来可以用递归来解决.
假设有4个台阶,每一步都有两种可能,化成树状图如下,左子树都是-1,右子树都是-2,这样每一步的可能都包括进去了.
![image.png](https://pic.leetcode-cn.com/fa2ca4d00ee99a688f7af10974d1e3c75e454ae9154396a1b009d042beabc8b7-image.png)

通过观察这颗树,就能发现这就是"斐波那契数列",那就好办了,f(n)=f(n-1)+f(n-2)
然后用循环代替递归就完事了.
```
public class Solution {
    public int NumWays(int n) {
        if(n==0)
            return 1;
        else if(n<=3){
            return n;
        }
        int pre=2;
        int total=3;
        int tmp=0;
        for(int i=4;i<=n;i++){
            
            tmp=total;
            total+=pre;
            if(total>1000000007 || tmp>1000000007){
                total=total%1000000007;
                pre=tmp%1000000007;
            }else{
                pre=tmp;
            }
           
        }
        return total;
    }
}
```
