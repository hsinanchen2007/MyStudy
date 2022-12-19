### 解题思路
此题是一个O(n)的解法，思路请看注释 
### 代码

```cpp
/* 
 * 题目中：你不需要考虑数组中超出新长度后面的元素。
 * 说明是要对原数组进行操作的
 */ 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // 别忘记空数组的判断
        int index = 0; 
        for (int i = 0; i < (nums.size() - 1); i++){
            if(nums[i] != nums[i + 1]) { // 一旦发现和前一个不相同，就把num[i+1] 赋值给 nums[++index]
                nums[++index] = nums[i + 1]; // index = 0 的数据一定是不重复的，所以直接 ++index 
            }    
        }
        return index + 1; //别忘了index是从0开始的，所以返回index + 1 
    }
};
``` 
### 求职内推
本人在一线大厂从业多年，在先后就职于腾讯和百度，想要内推（实习/校招/社招）的小伙伴可以通过公众号「代码随想录」 联系到我