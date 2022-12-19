    利用find()函数寻找haystack中与needle匹配的字符串，若没有找到，则返回haystack.npos，若找到，则返回needle第一个字符在haystack的位置
![8.jpg.png](https://pic.leetcode-cn.com/b2240b1bb656a4959a1444e5b6c70ca1d3b1a549ac73594340fa8f2d19177b46-8.jpg.png)
(当然，这种投机的方法大家了解就好，主要还是可以通过双指针或KMP算法解决以增强自己的算法逻辑能力)
### 代码

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle) == haystack.npos)
        return -1;
        return haystack.find(needle);
    }
};
```