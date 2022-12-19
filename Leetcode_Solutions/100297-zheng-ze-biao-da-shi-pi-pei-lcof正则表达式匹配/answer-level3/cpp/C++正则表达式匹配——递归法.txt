### 解题思路
这道题《剑指 offer》和leetcode输入参数不一样，要注意，当输入是string时，要定义char指针指向string
同时，这道题如果输入是字符串string就不用考虑空了
普普通通递归就完事了。
接下来还有一个方法————动态数组法。研究一下。

### 代码

```cpp
class Solution {
public:
    bool isMatch(string su, string pu) {//s是字符，p是匹配 含符号
        //if(su.length()==0 && pu.length()==0) return false;
//定义指针
char* s=su.data();char* p=pu.data();
        return match(s,p);
    }

    bool match(char* s,char* p)//
    {
        if(*s=='\0'&& *p=='\0') return true;//遍历完了
        if(*s!='\0'&& *p=='\0') return false;
        if(*(p+1)=='*')
        {
            if(*p==*s || (*p=='.'&& *s!='\0')) 
            return(match(s+1,p+2)||match(s,p+2)||match(s+1,p));
            else//不等
            return(match(s,p+2));

        }

        //没有'*'的情况
        if(*p==*s || (*p=='.' && *s!='\0'))
        {
            return(match(s+1,p+1));
        }
        return false;


    }
};
```