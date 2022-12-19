这是一个有限自动机

+ 当前状态匹配：
  + 判断下一个是不是'\*'，如果是
    + 可能含义是出现0次，那这次匹配就不算，str不移动，匹配串右移2（*不参与匹配）
    + 可能含义是出现1次，那这次匹配算，str右移1，匹配串右移2
    + 可能含义是出现n次，那这次匹配算，str右移1，匹配串不移动
  + 不是'\*'，str右移1，匹配串右移1
+ 当前状态不匹配：
  + 判断下一个是不是'\*'：如果是，就把'\*'当做出现0次，这次匹配不算
  + 不是'\*'，返回false
+ 终止状态：两个串同时为'\0'返回true，如果匹配串为空而str不为空，返回false
+ 注意，并不是str为空就终止，可能匹配串是'a*'这类

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size() == 0&&p.size() == 0){
            return true;
        }
        char *str = s.data(),*pattern = p.data();
        return matchState(str,pattern);
    }
    bool matchState(char *str,char *pattern){
        if(*str == '\0' && *pattern == '\0') return true;
        if(*str != '\0' && *pattern == '\0') return false;

        if(*pattern == *str ||(*pattern == '.' && *str != '\0')){
            if(*(pattern + 1) != '*'){
                return matchState(str + 1,pattern + 1);
            }else{
                return matchState(str,pattern + 2)||//0
                       matchState(str + 1,pattern + 2)||//next state
                       matchState(str + 1,pattern);//ignore
            }
        }
        
        if(*(pattern + 1) == '*'){
            return matchState(str,pattern + 2);
        }

        return false;
    }
};
```

