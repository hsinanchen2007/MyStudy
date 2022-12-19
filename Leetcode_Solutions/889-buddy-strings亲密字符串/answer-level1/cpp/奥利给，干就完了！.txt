# 把所有情况考虑一遍就行了，一次通过。

首先，两个字符串长度不相等或长度为0肯定不行：
```
if(A.size()!=B.size()||A.size()==0)
    return false;
```

其次，如果两个字符串完全相等，则每个字符串至少要有两个相同的字母才行：
```
if(A==B)
{
    unordered_set<char> c;
    for(int i=0;i<A.size();i++)
    {
        if(c.find(A[i])==c.end())
            c.insert(A[i]);
        else
            return true;
    }
    return false;
}
```

最后，最复杂的情况来了，两个字符串中有且只能有两个字母的索引不同。
我们按部就班，一个字母一个字母的对比，当第一对不同的字母出现时，记录下此时的索引，然后继续比较；第二对不同的字母出现时，要保证这两对字母正好相反，否则return false;另外，如果出现第三对不同的字母，直接return false;
```
int first;
bool foundfirst=false,foundsecond = false;
for(int i=0;i<A.size();i++)
{
    if(A[i]!=B[i])
    {
        if(foundsecond)
            return false;
        if(!foundfirst)
        {
            first = i;
            foundfirst = true;
        }
        else
        {
            if(A[first]==B[i]&&B[first]==A[i])
                foundsecond = true;
            else
                return false;
        }
    }
}
```
这段代码里first用于标记第一对不同字母的索引，foundfirst用于标记是否已经找到第一队不同字母，foundsecond用于标记是否已经找到第二对不同的字母。

如果符合上述所有条件，就要：
```
return true;
```

下面是完整代码：
```
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size()||A.size()==0)
            return false;
        if(A==B)
        {
            unordered_set<char> c;
            for(int i=0;i<A.size();i++)
            {
                if(c.find(A[i])==c.end())
                    c.insert(A[i]);
                else
                    return true;
            }
            return false;
        }
        int first;
        bool foundfirst=false,foundsecond = false;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=B[i])
            {
                if(foundsecond)
                    return false;
                if(!foundfirst)
                {
                    first = i;
                    foundfirst = true;
                }
                else
                {
                    if(A[first]==B[i]&&B[first]==A[i])
                        foundsecond = true;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
```

执行效率：
![执行时间.jpg](https://pic.leetcode-cn.com/0b90082c0761a06c80d52694652864241e719f755adeec239aeca42af958a448-%E6%89%A7%E8%A1%8C%E6%97%B6%E9%97%B4.jpg)
