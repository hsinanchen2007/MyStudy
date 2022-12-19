### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/9da1d6a098493a3de648e3cc348d7204449faa7df3fcbfd6b370c4629c9e182c-image.png)


### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left <= right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
```