### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> m;
        int Min=INT_MAX;
        for(int n:deck)
            m[n]++;
        for(auto it:m)Min=min(Min,it.second);
        for(int i=2;i<=Min;i++){
            int flag=0;
            for(auto it:m)
                if(it.second%i!=0){
                    flag=1;
                    break;
                }
            if(!flag)return 1;
        }
        return 0;
    }
};
```