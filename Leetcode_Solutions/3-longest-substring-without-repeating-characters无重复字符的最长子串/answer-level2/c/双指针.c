### 解题思路
双指针，右指针向后查找，用一个asciiArr[256]数组来标记所有字符，如果下标为a的值等于0，则说明a是第一次出现，继续挪动右指针，如果下标为a的值大于0，则说明a已经在之前出现过，需要挪动左指针，直到将下标为a的值减为0。

### 代码

```c
int max (int a, int b)
{
    if (a >= b)
        return a;
    else
        return b;
}

int lengthOfLongestSubstring(char * s){

    if (s == NULL || strlen(s) == 0)
        return 0;
    
    int l = 0, r = 0;
    int asciiArr[256] = {0}; // 用ascii值作为字母的数组下标，记录该字母出现的次数
    int res = 0;
    
    while (l < strlen(s))
    {
        if (r < strlen(s) && asciiArr[s[r]] == 0) //当前是否有重复，没有就移动o右指针
        {
            asciiArr[s[r]] ++;
            r++;
        }
        else //有重复，移动左指针
        {
            asciiArr[s[l]] --;
            l++;
        }
                
        res = max(res, r - l);
    }
    
    return res;
}

```