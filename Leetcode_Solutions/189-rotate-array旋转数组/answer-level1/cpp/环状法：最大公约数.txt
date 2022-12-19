思想：采用环状法。k = k % n。
用tmp保存要被替换的值nums[future]。
之后，用当前current位置的值去替换他将来要占的坑future即nums[future]=nums[current]。
替换后，current记得变为之后要替换current位置的新的位置，即current = (current + n - k) % n。
但是，实际上会发现，当替换x次后，curren会回退到之前替换过的位置了，即这是一个循环。
所以，我们用n,k的最大公约数x来表示一个循环内的替换次数，而最大公约数则表示总共有多少个循环。
    即
```
int nums_in_cycle = n / x;
int cycles = x;
```
记得每次循环中的最后要用tmp去替换最后一个值。
完整代码如下：
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if ((k % n) == 0)
            return;
        k = k % n;
        int x = n, y = k, rem = 0;
        while (y != 0)
        {
            rem = x % y;
            x = y;
            y = rem;
        }
        // 最后，x 为最大公约数
        int nums_in_cycle = n / x;
        int cycles = x;
        for (int j = 0; j < cycles; j++)
        {
            int current = j;
            int future = (current + k) % n;
            int tmp = nums[future];
            for (int i = 1; i < nums_in_cycle; i++)
            {
                nums[future] = nums[current];
                future = current;
                current = (current + n - k) % n;
            }
            nums[future] = tmp;
        }
    }
};
```
