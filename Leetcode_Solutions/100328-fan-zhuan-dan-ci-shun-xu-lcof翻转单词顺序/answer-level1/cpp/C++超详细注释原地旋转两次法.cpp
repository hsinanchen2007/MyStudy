### 解题思路
这道题超级多细节，错了一个就会报错。
我的解题思路是：（参照剑指 offer的解法）
1、先删除头的空格（删完长度为0直接输出“”），再删除尾的空格；最后删除中间重复的空格（前后指针法）；
2、旋转整个字符串s；
3、旋转每个单词里的字母。
注意：将旋转写成函数，调用收尾指针。
注意s.erase(a,a+i)：删除从a开始i个数。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0) return s;
        //删除头空
        int k=0;
        while(s[k]==' ') s.erase(k,1);
        if(s.length()==0) return "";//检验删完是否为空，否则会报错！！
        //删除尾空
        int e=s.length()-1;
        while(s[e]==' ') e--;
        s.erase(e+1,s.length()-1);//要这样写：计算有多少个空格然后一起删掉
        //去除字符串里多个空格
        int f=0,g=1;//定义前后指针！！
        while(f<=s.length()-1)
        {
            if(s[f]==' '&&s[g]==' ')
            {
                while(s[g]==' ') g++;
                s.erase(f,g-1-f);//
                g=f+1;//删掉之后end变为begin+1
            }
            else {++f;++g;}
        }
        //旋转
        int begin=0,end=s.length()-1;
        change(s,begin,end);
        //单词中每个字母旋转
        begin=0;end=0;
        while(end<=s.length())//取等
        {
            if(s[end]==' '||s[end]=='\0')//最后一个是\0
            {
                change(s,begin,end-1);
                begin=end+1;//begin取空格的下一个！！！！！！！
            }
            end++;
        }
        return s;
    }
    void change(string& s,int begin,int end)
    {
     while(begin<end)
        {
            char si=s[begin];
            s[begin]=s[end];
            s[end]=si;//交换
            begin++;end--;
        }
    }
};
```