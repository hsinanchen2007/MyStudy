### 解题思路
此处撰写解题思路

![image.png](https://pic.leetcode-cn.com/60aa4a4262e251ab0a77d9e1a0a4bf7f78056a8f1c124344e585de06d5fe178a-image.png)




### 代码

```cpp
class Solution {
public:
    //使用双指针交换字符  字符串    左边位置   右边位置
    void reserve(string& str,int left,int right){
        while(left < right){
            swap(str[left],str[right]);
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        int front = 0;//初始位置
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reserve(s,front, i - 1);
                front = i + 1;//更新初始位置，变为‘ ’后面的一个字符
            }
        }
        reserve(s, front,s.length() - 1);//对最后一个单词的反转
        return s;
    }
};
```