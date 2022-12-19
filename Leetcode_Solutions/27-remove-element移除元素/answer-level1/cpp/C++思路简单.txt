### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int j=0;
    int len=nums.size();
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]==val) {
            j++;
        }
        else
            nums[i-j]=nums[i];
    }
    return (len-j);
}
};
```