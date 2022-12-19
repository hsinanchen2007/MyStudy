### 解题思路
此处撰写解题思路
1.用count记录不同的数组下标；
2.count > 2或count = 1则返回false；
3.count = 2时判断两个互换是否相等；
4.count = 0 判断A中是否呦重复元素出现，有返回true否则false；
![image.png](https://pic.leetcode-cn.com/ed4d935243e3e9dbcdd6a2374376cff7844e9ec6a2a9017487f5da6b2e163586-image.png)

### 代码

```c
bool buddyStrings(char * A, char * B)
{
    int i,j;
    int count = 0;
    int pos;
    int alen = strlen(A);
    int blen = strlen(B);
    if(alen == 0 && blen == 0)
        return false;
    int tmp[3]={1,2,3};                         //记录不同字符的下标数组，起始值设为不相同
    if(alen != blen)
        return false;
    for(i = 0; i < alen;i++)
    {
        if(A[i] - B[i] != 0)
        {
            tmp[count++] = i;                   //记录不同的位置
        }
        if(count > 2)
        {
            return false;
        }
    }
    if(count == 1)  
    {
        return false;
    }
    if(count == 2 && A[tmp[0]] == B[tmp[1]] && A[tmp[1]] == B[tmp[0]])          //两个位置不同，且互相相等。则返回true
    {
        return true;
    }
    else if(count == 0)                                                         //处理A,B全部相等，若出现重复则返回true
    {
        for(i = 0;i < alen;i++)
        {
            for(j = i+1;j < alen;j++)
            {
                if(A[i] == A[j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
```