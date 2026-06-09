### 解题思路
1. 摩尔投票的作用：找到个数最多的两个元素，不保证一定过n/3。
2. 为什么只有两个candidate？ 因为长度超过n/3的数最多只有两个
3. 为什么两个candidate相等不影响计算？ 这个比较绕脑子，但是两个candidate的更新是有先后的。（我还需要再理解理解呀

### 代码

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> re;
        if (nums.size()==0) return re;
        int candidate1 = 0;
        int count1 = 0;
        int candidate2 = 0;
        int count2 = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == nums[candidate1]) count1++;
            else if (nums[i] == nums[candidate2]) count2++;
            else if (count1==0) {
                candidate1 = i;
                count1 = 1;
            }
            else if (count2==0) {
                candidate2 = i;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == nums[candidate1]) count1++;
            else if (nums[i] == nums[candidate2]) count2++;
        }
        if (count1 > nums.size()/3) re.push_back(nums[candidate1]);
        if (count2 > nums.size()/3) re.push_back(nums[candidate2]);
        return re;
    }
};
```