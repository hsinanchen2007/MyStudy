### 解题思路
参照了其他大佬的思路然后改掉了我看不懂为什么的地方（捂脸）
先把speed和efficiency结对 按照efficiency降序排序
然后我们用一下神奇的priority_queue
![捕获.PNG](https://pic.leetcode-cn.com/d0ee8b3188d6d97f7a55d3927deaa4a09062a871b8be695fdca725de0e187baa-%E6%8D%95%E8%8E%B7.PNG)
因为我们之前已经做了一次排序 所以我们从左到右扫描一遍 把扫描到人的speed丢进这个优先队列
如果队列内的元素比k多 那就把最小的那个speed踢出去
然后我们尝试下当前换了一个人进来的组合算出的结果会不会比之前得到的答案大 如果更大就把答案更新
（因为新加进来的这个人的efficiency肯定是当前挑的人里面最小的 所以直接乘就好 ）
最后返回的时候再取余
要用long long，int会炸

### 代码

```cpp
class Solution {
    struct people{
        long long first,second;
    };
public:
    static bool cam(people a,people b){
        return a.first>b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<people> logs(n+1);
        for(int i=0;i<n;++i){
            logs[i].first=efficiency[i];
            logs[i].second=speed[i];
        }
        sort(logs.begin(),logs.end(),cam);
        priority_queue<long long,vector<long long>,greater<long long> > q;
        long long sum=0,ans=0;
        for(int i=0;i<n;++i){
            //cout<<logs[i].second<<endl;
            sum+=logs[i].second;
            q.push(logs[i].second);
            if(q.size()>k){
                sum-=q.top();
                q.pop();
            }
            ans=max(ans,sum*logs[i].first);
        }
        return ans%1000000007;
    }
};
