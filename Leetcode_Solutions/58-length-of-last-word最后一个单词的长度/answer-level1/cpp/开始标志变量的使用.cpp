### 解题思路
从后往前扫描，
1）记录第一个字母的下标
2）继续向前扫描直到遇到空格或者达到字符串头。相减即为最后一个单词长度。
注意特殊情况：整个字符串为若干个空格，则记录的下标无效，直接返回0.

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s =="")
            return 0;
        int begin = 0;
        int end = 0;
        int flagStart=1;
        for(int i=s.length()-1;i>=0;i--){
            if(flagStart==1&&s[i]==' ')
                continue;
            if(flagStart==1&&((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))){
                end = i;
                flagStart = 0;
                continue;
            }
            if(flagStart==0&&s[i]==' '){
                begin = i+1;
                break;
            }
            if(flagStart==0&&((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))&&i==0){
                begin=i;
                break;
            }
           

        }
        if(flagStart)
        return 0;
        return end-begin+1;
    }
};
```