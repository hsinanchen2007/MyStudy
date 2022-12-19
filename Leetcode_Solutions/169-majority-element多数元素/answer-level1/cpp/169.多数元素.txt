### 解题思路
1、哈希表
2、投票算法，遍历数组，当值一样的时候，加1，不一样减一，小于0换一个，最后得到的就是众数。

### 代码

```cpp
#include <map>
class Solution {
private:
    std::map<int,int> counter;
    std::map<int,int>::iterator it;
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0]; 
        }
        for(int i=0;i<size;++i){
            int key = nums[i];
            it = counter.find(key);
            if(it != counter.end()){
                int count = counter.at(key);
                if(count == size/2){
                    return key;
                }
                counter[key] = ++count;
            }else{
                counter[key] = 1;
            }
        }
        return NULL;
    }
};
```