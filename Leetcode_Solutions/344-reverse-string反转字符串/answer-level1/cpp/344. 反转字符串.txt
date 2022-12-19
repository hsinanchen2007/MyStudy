### 解题思路
1.双指针交换各自元素实现反转字符。

### 代码

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
            char temp;
    int left = 0;
    int right = s.size() - 1;
    while(left < right){
        temp = s[right];
        s[right] = s[left];
        s[left] = temp;
        left++;
        right--;
    }
    }
};
```