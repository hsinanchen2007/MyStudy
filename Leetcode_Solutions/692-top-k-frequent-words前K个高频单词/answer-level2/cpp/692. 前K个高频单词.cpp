### 解题思路
先用map统计下单词数量
再用sort排下序

### 代码

```cpp
class Solution {
public:
    struct node{
        string s;
        int cnt;
    };
    static bool cmp(const node &a,const node &b){
        if(a.cnt==b.cnt) return a.s<b.s;
        return a.cnt>b.cnt;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(auto e:words){
            mp[e]++;
        }
        node tmp;
        vector<node>v;
        for(auto e:mp){
            tmp.s=e.first;
            tmp.cnt=e.second;
            v.emplace_back(tmp);
        }
        sort(v.begin(),v.end(),cmp);
        vector<string>res;
        for(int i=0;i<k;i++){
            res.push_back(v[i].s);
        }
        return res;
    }
};
```