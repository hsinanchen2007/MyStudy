### 解题思路
正常的一个暴力思路
题解记录排坑：(评论区看到的)
关于c++字符串拼接的问题，s = s + "A"会产生一个新的对象
在返回结果给s，s += "A" 应该是涉及到对象的引用，不需要产生额外的对象
因此s = s + 'A'在每次拼接时都产生额外的对象占用内存
在字符串特别长的时候会导致超出内存限制的问题

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        string ans = "";
        int len = S.length(),num = 1;
        for(int i=0;i<len;i++)
        {
            if(S[i]==S[i+1])
            {
                num++;
            }
            if(S[i]!=S[i+1])
            {
                ans +=  S[i];
                ans +=  to_string(num);
                num = 1;
            }
        }
        int lan = ans.length();
        return lan<len?ans:S;
    }
};
```