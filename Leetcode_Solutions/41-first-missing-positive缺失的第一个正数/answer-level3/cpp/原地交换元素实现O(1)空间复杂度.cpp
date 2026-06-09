### 解题思路
这题在字节跳动二面碰到了，当时一开始没想出来，在面试官提示下做出来了。这题的难点主要在于空间复杂度的限制，如果不要求空间复杂度O(1)的话，其实很简单，只需要开辟一个一样长的新数组当做哈希表，把输入的值都放在正确的位置，然后在新数组里遍历一下，找到第一个位置不对的数值即可。但是这里要求空间复杂度为O(1)，因此只能把原数组作为哈希表，这里就涉及到元素的原地交换，需要不停地交换元素，直到不符合条件。代码如下。

### 代码

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= nums.size() && i != nums[i]-1) { //不停交换元素，把元素摆到 下标=值-1 的位置
                int tmp = nums[nums[i]-1];
                if (tmp == nums[i]) { //如果相应位置已经摆对了，忽略这个值
                    nums[i] = -1;
                    break;
                }

                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;
            }

            if (nums[i] <= 0 || nums[i] > nums.size()) { //无法交换，把这里挖个空洞，用-1表示
                nums[i] = -1;
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                return i+1;
            }
        }

        return nums.size()+1;
    }
};
```