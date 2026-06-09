### 解题思路
双指针：
1）设置两个指针：left = 0，right = size-1，向中间判断是否为回文。如果是，则直接返回成功。如果不是，则获得left和right当前的位置
2）题目要求最多剔除1个字符，因此向左或向右移动1位，继续判断是否为回文。只要满足一种都返回为TRUE

### 代码

```cpp
class Solution {
public:
    bool judge(int &left, int &right, string s)
    {
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                break;
            }
        }

        if (left >= right) {
            return true;
        }

        return false;
    }

    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        if (judge(left, right, s)) {
            return true;
        }

        int newleft1 = left + 1;
        int newright1 = right;
        int newleft2 = left;
        int newright2 = right - 1;

        if (judge(newleft1, newright1, s) || judge(newleft2, newright2, s)){
            return true;
        }

        return false;
    }
};
```