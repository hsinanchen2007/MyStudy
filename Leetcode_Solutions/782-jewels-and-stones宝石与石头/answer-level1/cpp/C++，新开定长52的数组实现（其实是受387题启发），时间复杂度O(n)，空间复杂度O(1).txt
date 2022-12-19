执行用时 : 4 ms, 在Jewels and Stones的C++提交中击败了99.91% 的用户  
内存消耗 : 8.2 MB, 在Jewels and Stones的C++提交中击败了90.03% 的用户  

开个定长52的新数组  
遍历S把52个字母出现的次数都存下来（下面的第一个for循环）  
这样对于J中的每一个宝石都可以直接拿到其数量，然后挨个加起来就行了  
```cpp
int numJewelsInStones(string J, string S) 
{
    //771st
    int amount[52] = { 0 };
    int ans = 0;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] >= 'a')
            amount[S[i] - 'a']++;
        else
            amount[S[i] - 'A' + 26]++;
    }
    for (int i = 0; i < J.size(); i++)
    {
        if (J[i] >= 'a')
            ans += amount[J[i] - 'a'];
        else
            ans += amount[J[i] - 'A' + 26];
    }
    return ans;
}
```