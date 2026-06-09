### 解题思路
此处撰写解题思路
这道题想了一下没有太好的思路，只能一个一个字符的遍历了：
首先获取字符串s的长度
然后在长度范围内使用for循环遍历每个字符，
如果不是空格就append到新字符串里（这里注意append的时候要取s[i]的地址也就是使用char* 然后限制只拷贝一个字符 Tmps.append(&s[i],1)）
如果是空格就append字符串"%20"

### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        short SLen = s.length();
        string Tmps;
        string OtherS = "%20";
        for( short i=0;i<SLen;i++ )
        {
            if(s[i] == ' ')
            {
                Tmps.append(OtherS);
            }else
            {
                Tmps.append(&s[i],1);
            }

        }
        return Tmps;
    }
};
```