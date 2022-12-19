### 解题思路
核心思路：头尾双指针，交换奇偶数
执行用时 :44 ms, 在所有 C++ 提交中击败了11.30%的用户
内存消耗 :18.2 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(j>i){
            while(i<nums.size()&&nums[i]%2==1){
                i++;
            }
            while(j>=0&&nums[j]%2==0){
                j--;
            }
            if(j>i){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
        return nums;
    }
};
```