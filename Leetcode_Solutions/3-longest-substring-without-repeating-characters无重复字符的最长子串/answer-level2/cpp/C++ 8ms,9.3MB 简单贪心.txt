### 解题思路
快乐贪心！
设置头尾指针，维护两指针（当然，不需要用指针这么可怕的数据类型）间满足条件的序列。
可以很容易发现，当头指针在位置x时，如果获得的最远尾指针在位置y，那么当头指针后移到x+1位置时，尾指针只会停留在原地或是继续后移。
也就是说，这是一个单向移动的过程，时间复杂度就可以简化为O(N)啦！

![image.png](https://pic.leetcode-cn.com/9fa6ec54772b60c7e98be21e5345370826444d817ebb5825c8ef7cdfde21bff3-image.png)

### 代码
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        // 对于字符串长为0时特殊处理（这里需要这么做，是因为最后答案输出时是ans + 1
        if(len == 0) return 0;
        //头尾下标指针初始化
        int st = 0, en = 0;
        int ans = 0;
        bool ch[128];
        // ch数组按照ASCII码的值记录每个字符是否已被使用
        memset(ch, false, sizeof(ch));
        // 记录第一位的字符
        ch[s[0]] = true;
        // 注意，因为String存储范围的下标其实是 0..(len-1)，因此全部处理成en + 1 < len
        while(en + 1 < len)
        {
            // 利用贪心，如果下一位超出String范围，或是已被使用过，则退出循环
            while(en + 1 < len && !ch[s[en + 1]])
            {
                en ++;
                ch[s[en]] = true;
            }
            // 由于ans存储的是尾指针-头指针的数值，因此比实际长度小1
            ans = max(ans, en - st);
            // 头指针后移一位
            ch[s[st]] = false;
            st ++;
        }
        // 这里使用ans + 1输出是为了将len = 1的情况一起包括进来，感兴趣的码友可以尝试一下此类数据
        return ans + 1;
    }
};
```
