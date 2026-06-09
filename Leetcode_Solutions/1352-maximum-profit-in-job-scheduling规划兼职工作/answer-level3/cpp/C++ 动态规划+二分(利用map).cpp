使用map对结构体进行排序，需要注意的是，map的比较函数的运作方式是：
若cmp(a,b)和cmp(b,a)都返回false，则map只保留a,b其中一个。
```cpp
struct Node
{
    int a;
    int b;
    int c;
};
struct cmp
{
    bool operator()(const Node& n1,const Node& n2) const         // 这个成员函数必须修饰成const
    {
        if(n1.b==n2.b) return n1.a==n2.a?(n1.c<n2.c):n1.a<n2.a;
        return n1.b<n2.b;
    }
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        map<Node,int,cmp> m;
        for(int i=0;i<startTime.size();i++)
            m[{startTime[i],endTime[i],profit[i]}]=0;
        for(auto it=m.begin();it!=m.end();it++)
        {
            Node n=it->first;
            if(it==m.begin() || prev(it)->first.b < n.b)
            {
                int t1=it==m.begin()?0:prev(it)->second;
                auto t2=m.upper_bound({INT_MAX,n.a,INT_MAX});
                it->second=max(t1, (t2==m.begin()?0:prev(t2)->second) + n.c );
            }
            else
            {
                auto t=m.upper_bound({INT_MAX,n.a,INT_MAX});
                it->second=max( prev(it)->second , (t==m.begin()?0:prev(t)->second) + n.c);
            }
        }
        return prev(m.end())->second;
    }
};
```
