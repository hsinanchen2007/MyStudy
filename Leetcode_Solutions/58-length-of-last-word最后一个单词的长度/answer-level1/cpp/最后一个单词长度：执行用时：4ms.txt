### 代码

```cpp
class Solution {
public:
int lengthOfLastWord(string s)
{
    if(s.empty())
        return 0;
    int n=s.length();
    int count=0,space=0;//space:末尾空格数
    for(int i=n-1;i>=0;i--) if(s[i]==' ') space++; else break;
    for(int i=n-space-1;i>=0;i--) if(s[i]!=' ') count++; else break;
    return count;
}
};
```