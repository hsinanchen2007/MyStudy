### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> mp;
        int min1=INT_MAX;
        for(int i=0;i<deck.size();i++){
            mp[deck[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            min1=min(min1,it->second);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second%min1!=0){
                min1=gcd(min1,it->second);
            }
        }
        if(min1<2)return false;
        return true;
    }
    int gcd(int a,int b){
        while(b%a!=0){
            int t=b%a;
            b=a;
            a=t;
        }
        return a;
    }
};
```