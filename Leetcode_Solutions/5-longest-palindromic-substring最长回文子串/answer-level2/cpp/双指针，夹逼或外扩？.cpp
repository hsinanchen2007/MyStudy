### 解题思路
此处撰写解题思路

![image.png](https://pic.leetcode-cn.com/be6767029eee3a791e0606b8d02d9d4cbd0144277a73e475e62646f02925e9ae-image.png)

首先很容易想到用到夹逼的方法。但是要考虑的情况太多。
使用双指针外扩的方法比较好容易，只要考虑额外一种情况：一开始中间有重复字母，走到不重复的开始再比较
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        size_t n = s.size();
        int maxL = 1;
        int start = 0;
        for(int i = 0; i<n-1; i++){
            int head = i;
            int tail = i;
            int count = 1;
            while(s[head] == s[tail+1]){
                tail++;
                count++;
            }
            head--;
            tail++;
            while((0 <= head && tail < n) && (s[head] == s[tail])){
                    count+=2;
                    head--;
                    tail++;
            }
           if(count>=maxL) {
               maxL = count;
               start = head+1;
           }
        }
        return s.substr(start,maxL);
    }
};
```