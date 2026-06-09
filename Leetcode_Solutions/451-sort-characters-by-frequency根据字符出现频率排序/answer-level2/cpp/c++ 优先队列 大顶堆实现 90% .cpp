```
//优先队列 大顶堆实现 90% 
class Solution {
public:
    typedef pair<char,int> my_pair;
    struct cmp
    {
        bool operator() (my_pair &a,my_pair &b)
        {
            return a.second<b.second;
        }
    };
    string frequencySort(string s) {
        map<char,int> hash;
        priority_queue<my_pair,vector<my_pair>,cmp> que;
        int len=s.length();
        for(int i=0;i<len;i++)
            hash[s[i]]++;
        for(auto item:hash)
            que.push(make_pair(item.first,item.second));
        string res="";
        while(!que.empty())
        {
            auto p=que.top();
            que.pop();
            for(int i=0;i<p.second;i++)
                res+=p.first;
        }
        return res;
    }
};
```
