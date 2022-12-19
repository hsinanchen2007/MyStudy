### 解题思路
对于每个index,将nums[index]设为负值，第二次为负值时，则返回当前index
为避免0的问题，先+1

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            nums[i] += 1;
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0)
                return index;
            nums[index] = -abs(nums[index]);
        }
        return -1;
    }
};
![image.png](https://pic.leetcode-cn.com/1e3f2baa22a080323fbf5d9344b50aa5ec0eeaee45f19c15faa0c840d5967f04-image.png)

```