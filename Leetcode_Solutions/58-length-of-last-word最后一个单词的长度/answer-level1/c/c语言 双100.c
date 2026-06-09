### 解题思路
从后遍历，count记录字母个数，初值为0，读到空格判断下，count不大于零就继续遍历，count大于零就返回count

### 代码

```c
int lengthOfLastWord(char * s){
    if(strlen(s)==0)
    {
        return 0;
    }
    if(s[strlen(s)-1]==' '&&strlen(s)==1)
    {
        return 0;
    }
    int i=(int)(strlen(s))-1;
    int count=0;
    while(i>=0)
    {
        if(s[i]!=' ')
        {
            count++;
            i--;
        }
        else
        {
            if(count>0)
            {
                return count;
            }
            else
            {
                i--;
            }
            
        }
    }
    return count;
}
```