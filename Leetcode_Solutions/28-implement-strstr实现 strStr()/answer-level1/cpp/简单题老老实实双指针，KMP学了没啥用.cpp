### 解题思路

![image.png](https://pic.leetcode-cn.com/90785cc5324af147b3c90558742aeb7e279a5d2584fe8eed9631d59ba084c065-image.png)

我寻思这简单题老老实实双指针就行了呗，整那么大力气学KMP有啥用，面试基本用不到。更何况题目标签也提示双指针就行。

### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for(int i = 0; i < n - m + 1; i ++)
        {
            int j = 0;
            for( ; j < m; j ++)
            {
                if(haystack[i + j] !=  needle[j])
                //为了保证在这个循环里haystack的索引也跟着needle索引一起向前推进，i的含义设置为起始点，i + j才是haystack的索引
                    break;
            }
            if(j == m)
                return i;
        }
        return -1;
    }
};

```