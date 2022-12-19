### 解题思路
第一个哈希表储存每个数字的出现次数，第二个哈希表储存出现次数的出现次数，如果其值大于一，返回false

### 代码

```cpp
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>count1,count2;
        for(auto i:arr){
            count1[i]++;
        }
        for(auto i=count1.begin();i!=count1.end();i++){
            count2[i->second]++;
            if(count2[i->second]==2)return false;
        }
        return true;
    }
};
```