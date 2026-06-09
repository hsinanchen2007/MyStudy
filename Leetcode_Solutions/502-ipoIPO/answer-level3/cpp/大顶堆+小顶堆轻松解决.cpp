首先观察题意，题目要求假设我们是CEO的情况下， 为了尽量的赚到更多的钱，我们应该怎么做呢？
思考下，我们应该选择当前在自己资产许可的情况下尽可能的接到钱多的项目。
题目中给定了接项目不花钱（空手套白狼）。
那么贪心算法，我们在已知W的情况下，
应该去做的是选择Cpaital[i]<=W,并且Profits[i]为当前未选择的项目中给的钱最多的。


那么问题就很简单了，首先我们可以通过暴力法解决，每次在费用<W的范围内遍历找到最大的盈利额，每一次找到一个，然后将这个最大的删除。
这样代码写起来也很简单，不再写了。时间复杂度较高为O(N^2)。

思考下，我们要做的是什么呢
我认为分为两点
1.在<=W中找到价值最大的项目并实施，W增长
2.继续开拓新项目，因为W增长了，我们可以接一些所需资金更多的项目了，但是所需资金多，给的钱也不一定多，这时候又回到了第一点。

那么针对以上两个，我们可以建立两个优先队列来去解决这个问题
对于问题1，我们建立一个大顶堆（建立的基础是盈利的多少）A里面存放的每一个元素都是可以选择的项目。
对于问题2.然后我们再去建立另一个小顶堆，这个堆内放的每一个元素都是当前由于资金问题暂时无法开展的项目。那么小顶堆的建立基础是资金的多少。

我们针对之前提出的两个问题
1.找出大顶堆A的堆顶（可接的给钱最多的项目），开展项目，W增加。
2.W增加了小顶堆中B之前不可接的项目可以接了。

我们不断地将堆B可接的项目放入堆A，来回操作，直到满足要求。
代码如下：
```
class Solution {
public:
    struct cmp1
    {
        bool operator ()(pair<int,int>a,pair<int,int>b)
        {
            return a.second<b.second;
        }
    };
     struct cmp2
    {
        bool operator ()(pair<int,int>a,pair<int,int>b)
        {
            return a.first>b.first;
        }
    };
    /*每次尽可能的选择在自己的薪资范围内的商品来进行购买*/
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp1> max_heap;//建立大顶堆，表示可接的项目，堆顶为利润最高的
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp2> min_heap;//建立小顶堆，表示不可解的项目，堆顶为所需资本最低的
        int len=Profits.size();
        for(int i=0;i<len;i++)
        {
            if(Capital[i]<=W)//该项目可以接受
                max_heap.push({Capital[i],Profits[i]});//初始化大顶堆A
            else
                min_heap.push({Capital[i],Profits[i]});//暂时不可接受，放入B堆
        }
        int index=0;
        while(!max_heap.empty()&&index++!=k)//如果大顶堆为空，表示没有项目可以接受。
        {
            pair<int,int>tmp=max_heap.top();//找到利润最高的项目
            W+=tmp.second;//增大利润
            max_heap.pop();//删除该项目
            while(!min_heap.empty())//去小顶堆中找W增加后可接的项目
            {
                tmp=min_heap.top();
                if(tmp.first<=W)//如果堆顶项目可接
                {
                    max_heap.push(tmp);//放入大顶堆中
                    min_heap.pop();
                }
                else
                    break;//表示此时已经划分好大顶堆和小顶堆了
            }
        }
        return W;
    }
};
```

最重要的一点是想到建立一个以利润为关键点的大顶堆A，和一个以资本为关键点的小顶堆。
代码结果还不错：
![捕获.JPG](https://pic.leetcode-cn.com/cfca9ce15e6b6468c0acdb2c01d8256c74e41be2df287317a0c537ced70b63ac-%E6%8D%95%E8%8E%B7.JPG)
