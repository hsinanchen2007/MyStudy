### 解题思路
本题思路很简单，主要是超时的问题；
定义left和right变量，分别初始化为0和s.size()-1;
这个时候分为三种情况：
1、left 处的字符不满足回文串要求的字符，如' '和':'之类的，此时left++;
2、right处的字符不满足回文串要求的字符，如' '和':'之类的，此时right--;
3、left和right处的字符满足回文串的要求，这个时候进行判断，如果相等，则left++，right--,否则返回false；
当迭代到left >= right的时候，迭代结束。

### 代码

```cpp
class Solution {
public:
    //判定字符串是否符合回文串
    char normalize_string(char t){
        int temp = t - '0';
        if(temp >= 'A' - '0' && temp <= 'Z' - '0') return t;
        if(temp >= 'a' - '0' && temp <= 'z' - '0') return toupper(t);
        if(temp >= 0 && temp <= 9) return t;
        return ' ';
    }
    bool isPalindrome(string s) {
        string s_simply;
        int left = 0;
        int right = s.size()-1;
        //左右夹逼迭代
        while(left < right){
            if(normalize_string(s[left]) == ' ') left++;
            if(normalize_string(s[right]) == ' ') right--;
            if(normalize_string(s[left]) != ' ' && normalize_string(s[right]) != ' '){
                if(normalize_string(s[left]) == normalize_string(s[right])){
                    left++;
                    right--;
                }
                else return false;
            }
        }
        return true;
    }
};
```