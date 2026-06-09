### 解题思路
利用左右指针，因为题目为升序数组，则左累加右累减即可找到最后的结果

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left=0, right=numbers.size()-1;
        while(left<right){
            int sum = numbers[left] + numbers[right];
            if (sum == target){
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if (sum < target)
                left++;
            else
                right--;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/d86b8d27a726358664b313474bfb25f26599ce628a2026230241bd9d17665bd2-image.png)
