解法1（常规解法,不推荐）：暴力统计各个数的出现次数，然后根据出现次数过半来返回值。时间复杂度：O(n),空间复杂度O(n)。
```c++
class Solution {
public:
    // 众数：找到出现次数大于半数的那个数
    // 大前提：数组非空、总是存在众数
    // 思路1：暴力统计各个数出现的次数
    int majorityElement(vector<int>& nums) {
        int half_len  = nums.size()/2;
        int max_count = 0;
        // 统计各个数字出现的次数
        map<int,int> count;
        for (int item : nums)
        {
            count[item]++;
            if (count[item]>max_count)
            {
                max_count = count[item];
                if (max_count>half_len)
                    return item;
            }
        }

        // 由于题目前提是默认总是有众数所以这个返回值不会用到的
        return 0;
    }
};
```

解法2：可以用摩尔投票法（推荐高效低内存）。它设置一个临时变量x,初始值是 x=data[0]。还有一个计数变量count。然后i从1到len的遍历数组data[]，遇到与x相同的数那就count++，与x不同那就count--。当count==0时就x=data[i]。遍历结束后的x取值就是众数。
![image.png](https://pic.leetcode-cn.com/29b9a5cbfbe59ae334b6d09ea62d0e72f19179f767aadaa91c935832ffc359f0-image.png)


```c++
class Solution {
public:
    int majorityElement(vector<int> &nums)
{
    int half_len = nums.size() / 2;
    int x = nums[0];
    int count = 0;

    for (int item : nums)
    {
        if (count==0)
            x=item;
        if(item==x)
            count++;
        else
            count--;
    }
    return x;
}
};
```


解法3：时间复杂度不能再降了，但是空间复杂度可以降到O(1)。当**然这道题里面测试用例数据量非常小**所以这种解法反而看起来效果并不好。
可以把所有的数看做是0，1组成的序列。组成众数01序列一定是出现频率超过n/2.
比如众数是：101，那么所有数中从左往右数第一位中1出现的次数一定是过半，第二位0出现的次数也一定过半，第三位是1也同样。

我们反过来就可以推测出众数是哪个。只需要统计各个位中出现频率超过n/2到底是0还是1即可。
比如从左往右数第1位、第2位、第3位出现频率超过n/2的字符（0或1）分别是：1,0,0.
那么众数就是 二进制"100"对应的十进制数即4。
下面是实现的代码：
 
```c++
class Solution {
public:
    int majorityElement(vector<int> &nums)
{
    int half_len = nums.size() / 2;
    int max_count = 0;

    // 统计32位中各个位1出现的次数(因为不是0就是1，
    // 知道1的次数那0出现的次数就用总数减去1出现的次数即可)
    int count[32] = {0};

    int bit_checker[32] = {1}; // bit_checker[i]的二进制第i位是1
    for (int i = 1; i < 32; i++)
    {
        bit_checker[i] = bit_checker[i - 1] << 1;
    }

    for (int item : nums)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((bit_checker[i] & item) != 0)
                {
                    count[i]++;
                }
        }
    }

    int result = 0;
    long base = 1;
    for (int i = 0; i < 32; i++)
    {
        if (count[i] > half_len)
        {
            result += base;
        }
        
        base = base << 1;
    }

    return result;
}
};
```

