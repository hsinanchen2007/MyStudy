### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    struct cmp{
        bool operator()(pair<int,string>& a,pair<int,string>& b){
            if(a.first == b.first){
                return a.second>b.second;
            }else return a.first<b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hash;
        for(int i = 0;i<words.size();i++){
            hash[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> Q;
        for(auto it = hash.begin();it != hash.end();it++){
            Q.push({it->second,it->first});
        }
        vector<string> res;
        while(k){
            auto temp = Q.top();
            Q.pop();
            res.push_back(temp.second);
            k--;
        }
        return res;
    }
};
```