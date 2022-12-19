### 解题思路
此处撰写解题思路
string now表示将要输出的字符串，将其初始化为“1”。
然后进入循环：
使用string result表示对now的描述结果。
每次遍历就是简单的数出连续相同的字符个数再写入result中。

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string now="1";
        n--;
        if(n==0)
            return now;
        else
        {
            while(n--)
            {
                string result;
                int i=0;
                char ch=now[0];
                int l=0;
                for(;i<now.length();i++)
                {
                    if(now[i]==ch)
                        l++;
                    else
                    {
                        result+=(l+(int)'0');
                        result+=ch;
                        ch=now[i];
                        l=0;
                        i--;
                    }
                }
                if(l!=0)
                {
                    result+=(l+(int)'0');
                    result+=ch;
                }
                now=result;
            }
        }
        return now;
    }
};
```