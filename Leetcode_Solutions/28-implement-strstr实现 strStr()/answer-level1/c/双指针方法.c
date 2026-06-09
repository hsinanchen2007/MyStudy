### 解题思路
先用第一个指针在haystack里跑， 找到跟needle一样的第一个字符，然后用第二个指针往后逐一比较。如果相同，就返回第一个指针的位置。
比较容易想，但是数据一大跑起来的时间很久。
这个算法在探索的新手教程里的同个题目超时过不了，在普通的题库却过的了。
哈哈。

### 代码

```c


int strStr(char * haystack, char * needle)
{
    int lenn=strlen(needle);
    int lenh=strlen(haystack);
    if(lenn==0)
    {
        return 0;
    }
    
    int i;
    int count=0;
    
    for(i=0;i<lenh;i++)
    {
        if(haystack[i]==needle[count])
        {
            for(count=1;count<lenn;count++)
            {
                if(haystack[i+count]==needle[count])
                {
                    
                }else
                {
                    count=0;
                    break;
                }
            }
        }
        if(count==lenn)
        {
            return i;
        }
    }
    return -1;

}

```