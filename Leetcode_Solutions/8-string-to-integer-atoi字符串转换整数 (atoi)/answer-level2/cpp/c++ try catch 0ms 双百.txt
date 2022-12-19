![image.png](https://pic.leetcode-cn.com/942d29cc341a2d1ced4d114dd675e25a633f88f736c3b6ee4f7a2b8607ebbd24-image.png)

**实际上题目的要求跟stl的stoi基本上是一致的**，无视空格啥的。
区别在于stl会直接抛异常。
so，有现成的轮子不用，让我自己造轮子？
直接try catch就完事了。

**为什么不用流（stringstream）**，如果用流代码可以更简洁。
因为C++的流属实是弟弟，非常低效，反正我是尽量避免用的。
```
class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        try {
            result = stoi(str);
        } catch (invalid_argument) {
        } catch (out_of_range) {
            for (auto ch : str) {
                if (ch == '-') {
                    return INT_MIN;
                } else if (isalnum(ch)) {
                    return INT_MAX;
                }
            }
        }
        return result;
    }
};
```
