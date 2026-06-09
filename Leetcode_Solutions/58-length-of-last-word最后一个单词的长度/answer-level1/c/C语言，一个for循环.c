### 解题思路
先用strlen得到数组长度，然后从后往前查找。

### 代码

```c
int lengthOfLastWord(char * s){
    int len=strlen(s);
    int count=0,exist=0;
    if(len==0)return 0;

    for(int i=len-1;i>=0;i--){
        if(s[i]!=' ')exist=1;  //查找是否存在字母
        else{
            if(exist)return (len-i-1); //如果存在字母，且s[i]==' '，return结果
            else len--;  //s[i]==' '但是不存在字母，将len减一
        }
    }
    return len;
}
```