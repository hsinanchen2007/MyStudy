### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int x=stones[stones.size()-1];
            stones.pop_back();
            int y=stones[stones.size()-1];
            stones.pop_back();
            if(x-y!=0){
                stones.push_back(x-y);
            }
        }
        return stones.size()==0? 0:stones[0];
    }
};
```