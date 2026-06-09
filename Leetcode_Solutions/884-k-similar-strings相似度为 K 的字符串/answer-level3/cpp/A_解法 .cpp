### 前言
如果没记错的话，这道题好像是人工智能书里面的习题吧，当时老师还让我们做作业来着，而且就是放在启发式搜索那一章节。然而我好像作业没做，GG。

A*算法原理就不说了，大伙google或者找人工智能那本书看看吧，我说一下我的h函数和状态转移函数吧。
![image.png](https://pic.leetcode-cn.com/0fa1684ac4fa6b71744fbbd67e47b5d57e381d4fb66592e3cc1f974dd1cffa5a-image.png)

### h估计函数
```
    int h(const string &s,const string &end)
    {
        //显然，交换次数肯定不小于不同字母数的一半（上取整）
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            sum+=s[i]!=end[i];
        }
        return (sum+1)/2;
    }
```
### 状态转移
参考的是评论区大神的做法，先找到一个i，对应的字符不相同，然后停下来，从后面找到所有str[j]==B[i]的j，然后交换，我其实不太理解它是否完备，我一开始是直接把凡是不同相同的字符都交换然后获得下一个状态。
```
for(;i<n&&cur_str[i]==B[i];i++);
for(int j=i+1;j<n;j++)
{
    if(cur_str[j]==B[i])
    {
        auto next_str=cur_str;
        swap(next_str[i],next_str[j]);
        if(!close.count(next_str))
        {
            auto next_g=cur_g+1;
            auto next_h=next_g+h(next_str,B);
            if(!dist.count(next_str)||dist[next_str]>next_g)
            {
                dist[next_str]=next_g;
                open.push({{next_h,next_g},next_str});
            }
        }
    }
}
```

### 完整代码
```
class Solution {
public:
    int kSimilarity(string A, string B) {
        if(A==B)
            return 0;
        unordered_set<string>close;
        int n=A.size();
        unordered_map<string,int>dist;
        struct cmp{
            bool operator()(const pair<vector<int>,string>&l,const pair<vector<int>,string>&r)
            {
                return l.first[0]>r.first[0];
            }
        };
        priority_queue<pair<vector<int>,string>,vector<pair<vector<int>,string>>,cmp>open;
        int cur_g=0;
        int cur_h=h(A,B);
        open.push({{cur_g+cur_h,cur_g},A});
        dist[A]=0;
        while(!open.empty())
        {
            auto top=open.top();
            open.pop();
            auto cur_str=top.second;
            auto cur_g=top.first[1];
            if(dist[cur_str]<cur_g)
                continue;
            if(cur_str==B)
                return cur_g;
            //状态转移是不是一定转移那些不同的字符？
            close.insert(cur_str);
            int i=0;
            for(;i<n&&cur_str[i]==B[i];i++);
            for(int j=i+1;j<n;j++)
            {
                if(cur_str[j]==B[i])
                {
                    auto next_str=cur_str;
                    swap(next_str[i],next_str[j]);
                    if(!close.count(next_str))
                    {
                        auto next_g=cur_g+1;
                        auto next_h=next_g+h(next_str,B);
                        if(!dist.count(next_str)||dist[next_str]>next_g)
                        {
                            dist[next_str]=next_g;
                            open.push({{next_h,next_g},next_str});
                        }
                        if(cur_str[i]==B[j])//当找到一个这么特殊的之后，直接就跳出好了。
                            break;
                    }
                }
            }
        }
        return 0;
    }
    int h(const string &s,const string &end)
    {
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            sum+=s[i]!=end[i];
        }
        return (sum+1)/2;
    }
};
```
