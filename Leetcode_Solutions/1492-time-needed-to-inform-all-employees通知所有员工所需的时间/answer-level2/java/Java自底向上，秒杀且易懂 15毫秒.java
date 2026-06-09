![image.png](https://pic.leetcode-cn.com/a2e430163228284f5d9031fd800367961d26674c04aa06c8cdc0555fa1c5b39a-image.png)


```
class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int[] arr=new int[n];
        int ans=0;
        // 从0开始遍历
        for(int i=0;i<n;i++){
            int index=i;
            int sum=0;
            if(informTime[index]==0)    //表明是叶子节点
                while((index=manager[index])!=-1){  //循环往上找，直到头结点
                    sum+=informTime[index];         //记录每次的和
                    if(sum<=arr[index]) break;      //如果某个叶结点走到这个结点时和小于之前一个叶结点走到这里的和，那么接下来不用走了，因为肯定比之前的小（why? 因为这个类似相交链表，他们后面一段路都是一样的。都是同一个manager）
                    arr[index]=sum;                 //否则就更新这个值
                    ans=Math.max(sum,ans);          //记录这个数组的最大值
                }
        }
        return ans;
    }
}
```
