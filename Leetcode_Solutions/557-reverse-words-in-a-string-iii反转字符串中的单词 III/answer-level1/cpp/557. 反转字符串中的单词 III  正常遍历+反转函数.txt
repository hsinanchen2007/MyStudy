### 解题思路
用反转函数：从s的i到j反转
for遍历s，遇到‘ ’才操作，不然就继续遍历 
   设置指针f记录反转的起始位置，每次反转更新一次f
    而i为反转的结束位置
给s+‘’最后记得减去‘’
方便划分，因为原s最后没有空格

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int f=0;
        int len=s.length();
        s+=' ';
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                reverse(s.begin()+f,s.begin()+i);
                f=i+1;
            }
        }
        s=s.substr(0,len);
        return s;
    }
};
```