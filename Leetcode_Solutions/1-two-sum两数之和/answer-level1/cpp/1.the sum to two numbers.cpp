### 解题思路
大一大二学的都还回去了，for循环都写错了
c++:
1.vector新建的语句是vector<int> ne(2,0);2 size and initial 0
2.c++ array length is num.size(),not nums.length
if want to reduce O(n2)，use hash map
java: 
1. Map<Integer, Integer> map = new HashMap<>();  map.put(nums[i], i);
map.containsKey(complement)  map.get(complement)
2.new int[] { i, map.get(complement) }
question?
why containsKey is O(1)?link+redblacktree seek can reduce?
### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ne(2,0);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target)
                {
                    ne[0]=i;ne[1]=j;
                }
            }
        }
        return ne;
    }
};
```