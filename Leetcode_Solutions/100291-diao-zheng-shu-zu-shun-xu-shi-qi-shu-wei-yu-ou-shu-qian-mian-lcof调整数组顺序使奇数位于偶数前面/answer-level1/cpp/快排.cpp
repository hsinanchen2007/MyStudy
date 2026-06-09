### 解题思路
快排思想：
两个指针首尾往中间扫描，保证第一个指针前面的数都是奇数，第二个指针后面的数都是偶数。

每次迭代时的操作：

第一个指针一直往后走，直到遇到第一个偶数为止；
第二个指针一直往前走，直到遇到第一个奇数为止；
交换两个指针指向的位置上的数，再进入下一层迭代，直到两个指针相遇为止；

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i = 0 ,j = nums.size()-1;
        while(i<j){
            while(i<j&&nums[i]%2==1)i++;
            while(i<j&&nums[j]%2==0)j--;
            if(i<j)swap(nums[i],nums[j]);
        }
        return nums;
    }
};
```