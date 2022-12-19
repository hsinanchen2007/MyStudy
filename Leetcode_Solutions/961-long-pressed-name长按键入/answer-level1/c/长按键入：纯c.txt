### 解题思路
指针i指向name，指针j指向typed；
先对name字符串操作：用c1记录i所指的元素与相邻元素相同的个数。
再对typed字符串操作：用c2记录j所指的元素与相邻元素相同的个数。
然后判断i所指元素与j所指相同且c2>=c1时，表明第一个字母匹配（重复的字母均看作一个，例如aaaabbbc,a是第一个字母，b是第二个字母，c是第三个），然后i和j都向前走一步，重复上述，直到字符串为空。

### 代码

```c
bool isLongPressedName(char * name, char * typed){
    int i=0,j=0,c1,c2;
   while(name[i]!='\0'&&typed[j]!='\0')
    {
        c1=0;
        c2=0;
        while(name[i]==name[i+1])
        {
            c1++;
            i++;
        }
        while(typed[j]==typed[j+1])
        {
            c2++;
            j++;
        }
        if(typed[j]==name[i]&&c2>=c1)
        {
            i++;
            j++;
        }
        else
        {
            return false;
        }
    }
    if(name[i]!='\0')
        return false;
    return true;
}
```