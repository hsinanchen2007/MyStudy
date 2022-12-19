时间复杂度：O(N)
空间复杂度：O(1) /* 不包括返回结果用的vector */
搜索过程：
1. 设定一个工作数，初始值为1
2. 每次探求下一个数时，先尝试看看后面多加一个0, 是否超出限制
a. 如果未超出，那下一个数就是在后面接一个0
b. 如果超出了，就把为9的尾巴以及加1后num超过n的尾巴去掉
c. 如果num为0，则结束循环
```cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if (n < 1)
            return {};
        vector<int> ret(n);
        auto it = ret.begin();
        int num = 1;
        while (true) {
            *it++ = num;
            if (num * 10 <= n) {
                num *= 10;
            } else {
                while (num && num % 10 == 9 || num + 1 > n) {
                    num /= 10;
                }
                if (!num)
                    break;
                num++;
            }            
        }
        return std::move(ret);
    }
};
```