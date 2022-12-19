### 解题思路
想请教各位大神，为什么加的这个assert会出问题  换成while也不行
 还有就是这个排序过程执行用时以及内存消耗不理想 感觉很垃圾
执行用时 :
20 ms
, 在所有 C++ 提交中击败了
49.48%
的用户
内存消耗 :
10 MB
, 在所有 C++ 提交中击败了
6.01%
的用户
### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //assert(k>=1 && k<=nums.size())
        //while(k>=1&&k<=nums.size());
        sort(nums.begin(),nums.end());//排序一下，按索引逆向找第k大
        return nums[nums.size()-k]; //

    }
};
```