### 解题思路

官方给的题解实际上空间复杂度也是O（n）。
不妨抛弃题目限制。

![image.png](https://pic.leetcode-cn.com/41c2fd8fcba15c818a4e5f84d654fb6eb1ab74f51b3cc53fcf3ecaa92930604b-image.png)

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int buf[10000] = {0};

        //映射
        for(int i = 0; i < len; i++){
            if(nums[i] > 0 && nums[i] <= len){
                buf[nums[i]] = 1;
            }
        }

        //查找
        for(int i = 1; i <= len; i++){
            if(buf[i] == 0){
                return i;
            }
        }

        return len + 1;
    }
};
```