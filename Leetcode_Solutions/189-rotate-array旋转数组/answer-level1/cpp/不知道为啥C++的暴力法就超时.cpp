### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0)return;
        /* 暴力法，但超时
        int length = nums.size();
        k %= length
        while(k--)
        {
            int temp = nums[length-1];
            for(int i=length-1;i>0;--i)
            {
                nums[i] = nums[i-1];
            }
            nums[0] = temp;
        }
        */
        /*使用algorithm库的reverse*/
        k %= nums.size();
        reverse(nums.begin(),nums.begin()+nums.size()-k);
        reverse(nums.begin()+nums.size()-k,nums.end());
        reverse(nums.begin(),nums.end());
        return;
    }
};
```