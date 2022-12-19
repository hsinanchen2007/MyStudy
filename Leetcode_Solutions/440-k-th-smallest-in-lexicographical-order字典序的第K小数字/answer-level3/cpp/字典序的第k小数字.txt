参考https://www.cnblogs.com/grandyang/p/6031787.html的答案实现。
该题目可以看做十叉链表的先序遍历实现（需要注意n的范围），因此要求到在n中第k个元素，因此我们的设计思路如下：
在n的范围内对当前十叉树进行遍历，直到大于n，此时step可能大于等于k或者小于k，分别对应于在当前树中和不在当前树中。

在求解step的时候，需要用min((long long)n+1,last)-first,这里选用n+1的原因是因为如果用n的话会少计算以为，因此需要设置为n+1。
1）step>k，则在当前十叉树中，那我们从上往下依次查找。
2)step<=k，则不在当前十叉树中，则跳出该十叉树，进行下一个十叉树的遍历。
最终找到。
```
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur=1;
        --k;
        while(k>0){
            long long first=cur,last=cur+1,step=0;
            while(first<=n){
                step+=min((long long)n+1,last)-first;
                first*=10;
                last*=10;
            }
            if(step<=k){
                k-=step;
                cur++;
            }else{
                k--;
                cur*=10;
            }
        }
        return cur;
    }
};
```
