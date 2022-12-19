### 解题思路
其实很简单，没啥可说的。left从做往右走，right从右往左走，每次都交换一个元素即可。

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            std::swap(s[left], s[right]);
            left += 1;
            right -= 1;
        }
    }
};
```
![微信图片_20200102152528.png](https://pic.leetcode-cn.com/a826abd55333a9312f026a4ac1c265a3cb1e20f215911dab11229d646b120b81-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200102152528.png)
