### 解题思路
此处撰写解题思路

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
//如果能理解字符串数组就是一个二维数组就很好做了
int i,j;
if(strsSize==0)
    return "";
//先遍历二维数组的列，再遍历二维数组的行
for(j=0;strs[0][j]!='\0';j++)  //遍历第一个字符串，直到出现结束符号'\0'
{
    for(i=1;i<strsSize;i++)   //遍历所有字符串数组
    {
        if(strs[0][j]!=strs[i][j] && i==0)  //如果第一个字符就开始不同，表明不存在公共前缀
        {
            return "";
        }
        else if(strs[0][j]!=strs[i][j])   //监测到前缀字符不相同
        {
            strs[0][j]='\0';
            strs[0][j+1]='\0';      //后一个也赋值结束符，是为了跳出第一个循环
            break;
        }
    }
}
return strs[0];
}
```