思路分析：
1. 首先，数组长度不是k的整数倍，肯定不行。
2. 分析：
    一个基本上大家都能想到的思路，先把数组排序，然后从首元素开始，假设为`v1`，然后从数组中依次删除`v1, v1+1, ... ,v+k-1`,这个过程中如果找不到这样的元素则直接返错，一直重复这样的过程直至数组为空，则返回true。

思路清新之后就是用哪种数据结构做比较好，如果用vector的话，排序自然是没问题，但是删除元素的操作会变得比较耗时，首先pass掉。

经过思考之后：map是一个比较合适的数据结构，将数组元素作为k，value记录其在数组中出现的次数，c++ map在放入的时候就天然按照key进行了排序。

在每一次，我们都从首迭代器里取出第一个key，如果`map[key] == 0`，则将此项删除，直至找到一个`map[key] != 0`的首迭代器，然后依次将`map[key]--,map[key+1]--,...,map[key+k-1]--`，在这个过程中，只要发现一个key的value为0，则可返回false。

如果能够重复这样的过程直到map为空，则可划分。

```
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> tmpMap;   /* 用来记录每一个数及其出现的次数 */
        int sz = nums.size();
        if (sz == 0 || sz % k != 0) {
            return false;
        }
        
        /* 将每个数出现的次数记录在哈希表 */
        for (int i = 0; i < sz; i++) {
            tmpMap[nums[i]]++;
        } 

        while (1) {
            pair<int,int> start;

            /* 找到value不为0的首迭代器 */
            while(1) {
                if (tmpMap.empty()) {
                    return true;
                }
                start = *tmpMap.begin();
                if (start.second != 0) {
                    break;
                } else {
                    tmpMap.erase(start.first);  /* 所有的删除哈希表都在这里删除 */ 
                }
            }
            
            /* 依次将以首元素起始的k个元素的计数器--,如果发现有计数器为0，则返错 */
            for (int i = 0; i <= k-1; i++) {
                if (tmpMap[start.first + i] != 0) {
                    tmpMap[start.first + i]--;  /* 减1 */
                } else {
                    return false;
                }
            }
        }

        return tmpMap.empty();
    }
};
```