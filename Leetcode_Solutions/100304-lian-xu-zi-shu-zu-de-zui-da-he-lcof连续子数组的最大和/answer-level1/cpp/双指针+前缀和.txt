写出前缀和看了看数组length，就知道这题过不了了，但前缀和的思想还是要有的。本题算是一个一维前缀和的应用，在“最大子阵和”中，涉及到二维前缀和会更加有意思。
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> vt(nums.size() + 1, 0);
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt += nums[i];
            vt[i + 1] += cnt;
        }
        int max = -1000;
        for (int i = vt.size() - 1; i > 0; --i) {
            for (int j = 0; j < i; ++j) {
                if (max < vt[i] - vt[j]) max = vt[i] - vt[j];
            }
        }
        return max;
    }
};
```
感谢 hj24 大佬在题解中提供的思路[Python 前缀和加双指针解法](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/solution/python-qian-zhui-he-jia-shuang-zhi-zhen-jie-fa-by-/)

在此以C++语言实现

>需要一个O(n)的方法，当时就卡在这里了，一开始想到了双指针，但是光用双指针也不可能O(n)的遍历所有区间，必然需要一个策略来更新指针的移动
>这里的策略就是，尾指针遍历到哪一位，看一下头尾指针的前缀和的大小和这一个位的数的大小
>如果前缀和小于这一位，说明从头指针开始的子数组必然小于从这一位开始的子数组，所以这时候把头指针移到尾指针上就行了
>如果前缀和大于这一位的话，尾指针向后+1即可


参见代码如下：
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> vt(nums.size() + 1, 0);
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            cnt += nums[i];
            vt[i + 1] += cnt;
        }
        int left = 1, right = 1;
        int sum = -10000000;
        while (right <= nums.size()) {
            int tmp = vt[right] - vt[left - 1];
            if (tmp < nums[right - 1]) {
                sum = max(sum, nums[right - 1]);
                left = right;
            }
            else {
                sum = max(sum, tmp);
                right += 1;
            }
        }
        return sum;
    }
};
```

