### 解题思路
环状替换
边界条件-最大公约数
### 最小化k
当k>nums.size()时，可以将k mod s，得到最小移动距离。

### 环状替换
将某个元素保存在temp中，向后替换第(k mod s)个元素，再循环向后，直到替换到最开始位置的元素。(可以证明一定可以回到最初的元素)
**但在某些情况下不能遍历到所有元素** 
例如：s=6，k mod s = 2 时，环状替换顺序为0->2->4->0,至此跳出循环，1，3，5位的元素不能遍历到，WHY？

### 与正整数相关的性质
1. 设a,b为正整数，则存在整数X，Y满足，X\*a + Y\*b = gcd(a,b)。
2. gcd(a,b)是可用以上方式表示的最小正整数。
3. gcd(a,b)表示正整数a,b的最大公约数，辗转相除法可在O(logn)的时间复杂度内求出最大公约数。(这里的n表示二进制表示时正整数的位数）

例如：s=6，k mod s = 2 时，gcd(6,2)=2,则X\*6+Y\*2能够表示的最小正整数为2，那么环状替换链就需要有两条(0->2->4->0),(1->3->5->1).
那么在环状替换的外层需要另外的边界条件，来切换到另外的环状替换链上。

而当s和k互质时，即gcd(s,k) = 1时，替换链只需一条，即可遍历到所有的元素。
例如：s=6，k mod s = 5时，环状替换链为(0->5->4->3->2->1->0)

### 复杂度分析

1. 时间复杂度
    总时长 = 环状替换链数量 * 环状替换链长度 = gcd(s,k) * (s/gcd(s,k)) = s
    即时间复杂度为*O(n)*
2. 空间复杂度
    仅使用一个额外空间来暂时保存待移动元素，时间复杂度为*O(1)*

### 代码

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        k%=s;
        if((k==0) || (s < 2))return;
        int gcd_s_k = gcd(s, k);
        for(int i = 0; i < gcd_s_k; ++i)
        {
            int temp = nums[i];
            int j = i + k;
            while(j%s != i)
            {
                int temp1 = nums[j%s];
                nums[j%s] = temp;
                temp = temp1;
                j+=k;
            }
            nums[i] = temp;
        }

    }
    int gcd(int a, int b)
    {
        if( a < b)swap(a,b);
        return b == 0 ? a : gcd(b,a%b);
    }
};
```