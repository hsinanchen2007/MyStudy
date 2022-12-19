### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        while(n>0)
            //（n-1）/26表示当前处于第几个26循环
            //num即对应当前字母的数字
            int num = n - 26*((n-1)/26);
            //产生当前位temp并加入s
            char temp = 'A' + num - 1;
            s = temp + s;
            //往高一位计算进入下一次循环
            n = (n-1)/26;
        }
        return s;
    }
};
```