### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    struct RepIndex{
        int reptime;
        int startindex;
        RepIndex(){
            reptime = 0;
            startindex = -1;
        }
    };
    int findShortestSubArray(vector<int>& nums) {
        int maxlen = 0;
        int minsublen = nums.size();
        unordered_map<int,RepIndex> SearMap;
        for(int i=0;i<nums.size();i++){
            SearMap[nums[i]].reptime++;
            if(SearMap[nums[i]].startindex<0)SearMap[nums[i]].startindex=i;

            if(maxlen < SearMap[nums[i]].reptime){
                maxlen = SearMap[nums[i]].reptime;
                minsublen = i - SearMap[nums[i]].startindex + 1;
            } else if(maxlen == SearMap[nums[i]].reptime){
                minsublen = min(minsublen,i - SearMap[nums[i]].startindex + 1);
            }
        }
        return minsublen;
    }
};
```