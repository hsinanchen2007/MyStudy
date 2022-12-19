## 思路
同官网，设置三个指针：
L：指向左边下一个插入0位置
R：指向右边下一个插入2位置
i：当前指针
从头开始遍历：
- 如果当前指针值为0，则与num[L]交换，同时向右移动L和i，因为i的当前值已经被访问。
- 如果当前指针值为1，则直接右移当前指针，保持在中间。
- 如果当前指针值为2，则与num[R]交换，左移R指针，因为交换后num[i]还未被访问，所以不用右移当前指针值i。
### 代码
时间复杂度：O(n)
空间复杂度：O(1)
```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size < 0) {
            return;
        }
        int L = 0, R = size-1;
        int i = 0;
        while (i <= R) {
            if (nums[i] == 0) {
                swap(nums[L], nums[i]);
                ++L;   
                ++i;
            } else if (nums[i] == 1) {
                ++i;
            } else {
                swap(nums[i], nums[R--]);                
            }
        }
    }
};
```
