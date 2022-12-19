### 解题思路
迭代器遍历的效率可能很高。

### 代码

```cpp
class Solution 
{
    public:
    string removeVowels(string S) 
    {
        string::iterator tra;
        string ans ="";

        for(tra = S.begin(); tra != S.end(); ++tra) 
        {
            if(! (*tra == 'a' || *tra == 'e' || *tra == 'i' || *tra == 'o' || *tra == 'u') ) 
            {
                ans += *tra;
            }
        }
        return ans;
    }
};
```