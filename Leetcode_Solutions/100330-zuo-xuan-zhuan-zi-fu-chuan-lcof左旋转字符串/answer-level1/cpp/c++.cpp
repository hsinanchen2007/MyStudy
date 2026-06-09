### 解题思路
此处撰写解题思路：外循环为平移几次；内循环为整体向左平移一位；

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
int len=s.length();
while(n>0)
{
    int i;
    char t;
    for(i=0;i<len-1;i++)
    {
        t=s[i];
        s[i]=s[i+1];
        s[i+1]=t;
    }
--n;
}
return s;
}
};
```