思路很简单，维护一个数组count统计nums中的元素二进制表示中每一位1出现的次数，每一位产生的汉明距离等于count[i] * (n-count[i])，累加即可得到汉明距离之和。
在计算二进制表示时，用位运算比做除法快很多。
![屏幕快照 2020-02-12 下午4.05.38.png](https://pic.leetcode-cn.com/b94fdb306c98d4be7ab0d165863ff49db931dc054960f07a348e8671f0731343-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-12%20%E4%B8%8B%E5%8D%884.05.38.png)
```
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> count(30,0);
        int tmp, j, n = nums.size(), res = 0;
        if(n<2)
            return 0;
        for(int i = 0; i < n; i++) {
            tmp = nums[i];
            j = 0;
            while(tmp != 0) {
                count[j] += tmp&1;
                tmp >>= 1;
                j++;
            }
        }
        int top = 29;
        while(count[top] == 0 && top >= 0)
            top --;
        for(;top >= 0; top --) {
            res += count[top] * (n - count[top]);
        }
        return res;
    }
};
```
