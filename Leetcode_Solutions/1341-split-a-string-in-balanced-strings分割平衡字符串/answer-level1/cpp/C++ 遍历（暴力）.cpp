这道题我感觉从前遍历到最后应该是大家能想到的最简单的方法了
```
int balancedStringSplit(string s)
{
    int R_num = 0,L_num = 0,i = 0,ans = 0;
    while (i < s.length())
    {
        if(R_num == L_num && R_num && L_num)
            ans++,R_num = L_num = 0;

        if(s[i] == 'R')R_num++;
        if(s[i++] == 'L')L_num++;
    }

    return ans + 1;
}
```
