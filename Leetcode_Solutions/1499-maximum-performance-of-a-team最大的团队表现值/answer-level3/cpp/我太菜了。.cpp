### 算法思想
我们每一次都找到包含编号i而且i的效率是最低的团队的最大值。那么显然，首先特殊点说，如果这个人一人一个团队，那我们为了增大这个什么团队值，我们肯定要选那些效率比这个人要高的人加入，这样肯定可以使团队值变大。最多可以加入k-1个人对吧。
然后，我们是否枚举完全了呢？不管你选择什么团队，最小团队肯定是有一个人最小效率值的，我们的全局最大值肯定是从以上这些团队值里面寻找的。
### 具体实现
通过以上分析，我们明确了，就是枚举呗，如何线性枚举呢，根据我们上面的贪心分析，在选定i了之后，我们要找到效率比i要大的最多k-1个人对吧，那我们就排序呗，按照效率从小到大，i的右边的效率都不小于i。然后我们要从右边最多挑出k-1个人，这个k-1个人的速度和要最大，我就卡在了这里，指导交卷的那一刻才恍然大悟。这个问题其实就是对后缀区间求k-1个数最大和的问题。稍微想一下，只要我们从右往左遍历，维护一个最小堆，对于j，堆里面要放着j右边的最多k-1个数而且是最大的k-1个数，那max_k_sum[j]=sum(q),这里我们也要维护q中元素的和。
循环不变式如下：
入口：
q_sum=0;
迭代：
max_k_sum[j]=q_sum;
此时的维护性质：
```
q.push(speed[j]);
q_sum+=speed[j];
if(q.size()>k-1)
{
    q_sum-=q.top();
    q.pop();
}
```
所以通过以上操作，我们就可以计算出每一个排序后，每一个j右边k-1个数的最大和。
### 我的误区
不知道为什么，我怀疑是我这几天没怎么做力扣，一直在刷***导致我脑子迟钝了好多。其实以上算法并不难想得到，可我还是卡了好久，我一度陷入了用BIT也就是树状数组来求最大k-1和的地步，我想着，我对speed额外再排序，然后很明显，后面那k-1个数不就是我要找的和吗，这时只要在维护一个后缀和就行了。然鹅，我发现，实现起来很困难，因为这个按照speed排序后的数组和上面那个按照efficiency排序的数组有冲突，就是，你无法保证这后面k-1个数不包含那个j的speed，然后我又想，如果包含的话，那我就再往前取一个呗。可是，后面又有一个问题，怎么维护这个性质呢？你给j找出来了，那j+1咋办，我又在想，BIT有没有可以整体区间移动的操作，这样的话我就可以从speed中删除j了，然而这个，我想了好久，我觉得这样的话，别说再给我两小时，再给我一天我都实现不了，唉，太惨了。

```
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<int>>dict(n);
        int mod=pow(10,9)+7;
        for(int i=0;i<n;i++)
        {
            dict[i]={efficiency[i],speed[i]};
        }
        sort(dict.begin(),dict.end(),[](vector<int>l,vector<int>r){return l[0]<r[0];});
        vector<long long>max_k_sum(n);
        priority_queue<long long,vector<long long>,greater<long long>>q;
        long long sum=0;
        for(int i=n-1;i>=0;i--)
        {
            max_k_sum[i]=sum;//这一步就是求i右边的最大k-1和
            sum+=dict[i][1];
            q.push(dict[i][1]);
            if(q.size()>k-1)
            {
                auto top=q.top();
                q.pop();
                sum-=top;
            }
        }
        long long ret=0;
        for(int i=0;i<n;i++)
        {
            auto e=dict[i][0];
            auto s=dict[i][1];
            ret=max(ret,(s+max_k_sum[i])*e);
        }
        return ret%mod;
    }
};
```
