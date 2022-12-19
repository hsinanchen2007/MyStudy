## 问题描述
有一些工作：`difficulty[i]` 表示第i个工作的难度，`profit[i]`表示第`i`个工作的收益。

现在我们有一些工人。`worker[i]`是第`i`个工人的能力，即该工人只能完成难度小于等于`worker[i]`的工作。

每一个工人都最多只能安排一个工作，但是一个工作可以完成多次。

举个例子，如果3个工人都尝试完成一份报酬为1的同样工作，那么总收益为 $3。如果一个工人不能完成任何工作，他的收益为 $0 。

我们能得到的最大收益是多少？

[无效的图片地址](https:liyiping.cn/media/editor/2020-02-23-13-49-39%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE_20200223134956861728.png)

## 解决方法

我们必须要考虑到，低付出高收入的情况。因此我们将难度和收益用捆绑之后按照收益从大到小排序。

再将worker从大到小排序，一旦当前工人不能完成此难度的工作，则需要将工作难度下降，假如下降到diff[index]。这样下一个工人直接从diff[i]直接比较就可以了，不需要再从头比较

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int res=0;
        int size=profit.size();
        vector<pair<int,int>>v(size+1,make_pair(0,0));
        for(int i=0;i<size;i++){
            v[i].first=difficulty[i];
            v[i].second=profit[i];
        }
        sort(v.begin(),v.end(),[](const pair<int,int> &a, const pair<int,int> &b){return a.second>b.second;});
        sort(worker.rbegin(),worker.rend());
        int worker_num=worker.size();
        int index=0;
        for(int i=0;i<worker_num;i++){
            while(v[index].first>worker[i])index++;
            res+=v[index].second;
        }
        return res;

    }
};
```


my site: [https:liyiping.cn](https:liyiping.cn)