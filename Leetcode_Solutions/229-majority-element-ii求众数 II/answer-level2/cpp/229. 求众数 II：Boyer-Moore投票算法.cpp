### 解题思路
* 注意数据范围（未声明）；
* 测试样例不保证有解，可能是空数组；
* 投票算法

### 代码

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        if(nums.empty())    return ans;

        int cand1 = nums[0], cand2 = nums[0]; // 未说明数据范围，假装全是正数
        int count1 = 0, count2 = 0;

        for(int n: nums) {
            if(cand1 == n) {
                count1++;
            }
            else if(cand2 == n) {
                count2++;
            }
            else if(count1 == 0) {
                cand1 = n;
                count1 = 1;
            }
            else if(count2 == 0) {
                count2 = 1;
                cand2 = n;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;    // 计算候选人票数是否> n / 3
        for(int n: nums) {
            if(n == cand1)  count1++;
            else if(n == cand2) count2++;
        }
        if(count1 > nums.size() / 3)    ans.push_back(cand1);
        if(count2 > nums.size() / 3)    ans.push_back(cand2);
        return ans;
    }
};
```
![3.png](https://pic.leetcode-cn.com/0409c822d849ddd52747583e6972f376f351f145b0ee2f351761885a952a0c31-3.png)
