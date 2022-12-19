
### 代码

```cpp
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans=-1;
        map<int,int> help;//用来记录数据元素以及出现的次数

        for(int a:arr) help[a]++;
        for(auto h:help)
            if(h.first==h.second) ans=h.first;//利用了map的自动排序功能
        
        return ans;
        
    }
};
```