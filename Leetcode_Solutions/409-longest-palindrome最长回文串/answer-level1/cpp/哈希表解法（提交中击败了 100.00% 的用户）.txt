### 解题思路
分析：回文字符串，分为奇数形式与偶数形式。唯一不变的是，如果有一个字符个数为偶数，那么对于此字符，一定可以两两配对。如果一个字符个数为奇数，且它的数目不为1，那么可以将其字符个数减一构成偶数。此外，对于所有字符个数为奇数的字符，剩余的1个字符可以加入已经构造好的字符对（+1），但是对于所有字符而言，只能加一次（因为没有其他字符与之匹配，只能放在回文字符串的中间）。
### 代码

```cpp
class Solution {
public:
int longestPalindrome(string s)
{
    int ans=0;
    map<char,int> mmp;
    for(int i=0;i<s.length();i++)
    {
        mmp[s[i]]++;
    }

    int flag=0;
    for(auto iter=mmp.begin();iter != mmp.end();iter++)
    {
        int temp=iter->second;
        if(temp%2==0)
            ans+=temp;
        else
        {
            ans+=temp-1;
            flag=1;
        }
    }

    return ans+flag;
}
};
```