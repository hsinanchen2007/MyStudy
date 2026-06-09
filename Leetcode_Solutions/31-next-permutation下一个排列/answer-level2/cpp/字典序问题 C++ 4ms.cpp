### 解题思路
字典序问题

![image.png](https://pic.leetcode-cn.com/dd4080262e70ae44b3561b87c4175964c359223ed50e22d4305839f28464e37f-image.png)


### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return ;
        
        int i = n-2; //若在for循环体内初始化，i只能在循环体内生效
        int flag = 0; //若未交换，则说明已达到最大字典序，从头reverse即可
        for (i; i>=0; i--) {
            if (nums[i] < nums[i+1]) { // i处
                for (int j = n-1; j>i; j--) {
                    if (nums[j] > nums[i]) { // j处       
                        swap(nums[i],nums[j]);  
                        flag = 1;            
                        break; //注意break的位置，其实用while(A && B)更简单
                    }
                }
                break; 
            }
        }

        if (flag==1) {
        // 从i+1处开始升序排序
            vector<int>::iterator it = nums.begin();
            while (i-- >= 0) it++; // iterator移动到i+1处
            reverse(it, nums.end());
        } else { // i==0 还是有移动了或没移动的两种可能，所以必须用flag标记
            reverse(nums.begin(), nums.end());
        }
        
    }
};
```