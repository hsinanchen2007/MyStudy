```java []
class Solution {
    public int removeElement(int[] nums, int val) {
        int i=0;
        for(int j=0; j<nums.length; ++j){
            if(nums[j] != val){
                nums[i++] = nums[j];
            }
        }
        return i;
    }
}
```
```python []
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        for j in range(nums.__len__()):
            if nums[j] != val:
                nums[i] = nums[j]
                i+=1

        return i
```
```c++ []
// STL模板
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};

// 双指针
// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int i = 0;
//         for(int j=0; j<nums.size(); ++j){
//             if(nums[j] != val){
//                 nums[i++] = nums[j];
//             }
//         }
//         return i;
//     }
// };
```
