```java []
class Solution {
    // 使用双指针法
    public int removeDuplicates(int[] nums) {
        if(nums.length == 0)
            return 0;
        int index = 0;
        for(int i=0; i<nums.length; ++i){
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index+1;
    }
}
```
```python []
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if nums.__len__() == 0:
            return 0
        index = 0;
        for i in range(nums.__len__()):
            if nums[index] != nums[i]:
                index += 1
                nums[index] = nums[i]
        return index+1
```
```c++ []
class Solution {
public:
    // STL + 模板函数 + upper_bound()  底层实现为二分搜索
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        return distance(nums.begin(), removeDup(nums.begin(), nums.end(), nums.begin()));
    }

private:
    template<typename InIter, typename OutIter>
    OutIter removeDup(InIter first, InIter end, OutIter out){
        while(first != end){
            *out++ = *first;
            first = upper_bound(first, end, *first);
        }
        return out;
    }
};


// 使用STL unique()函数
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if(nums.empty())
//             return 0;
//         return distance(nums.begin(), unique(nums.begin(), nums.end()));
//     }
// };


// 常规遍历
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if(nums.size() == 0)
//             return 0;
//         int index = 0;
//         for(int i=0; i<nums.size();++i){
//             if(nums[index] != nums[i])
//                 nums[++index] = nums[i];
//         }
//         return index+1;
//     }
// };
```
