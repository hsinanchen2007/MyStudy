### 解题思路
此处撰写解题思路
+ 首先判断输入的合法性
        如果合法直接将小写转化为大写
        不合法跳过该元素
//注意合法性检查完后begin指向的是队尾的下一个元素，需要让begin指向队尾，p指向队首，比较首尾是否相同
+ 判断是否为回文
    相同则双指针都向中间移动，不同直接返回
    

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        char* p = &s[0];
        char* charAndNum = new char[strlen(p) + 1];
        char* begin = charAndNum;
        for (; *p != '\0'; p++) {
            if ((*p >= '0' && *p <= '9') || (*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
                if ((*p >= 'a' && *p <= 'z')) {    //小写转大写
                    *p= *p- 32;
                }
                *begin = *p;
                begin++;
            }
        }
        //此时begin指向末尾的下一个元素。将begin指向末尾，p指向开头
        p = charAndNum;
        begin--;
        while (p < begin) {
            if (*p != *begin) {
                return false;
            }
            p++;
            begin--;
        }
        return true;
    }

};
```