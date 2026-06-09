### 解题思路
思路类似于将字符串中的空格删除，此处只是删除的是除字母和数字之外的其他字符

### 代码

```c
bool isPalindrome(char * s){
    if(strlen(s)==0||strlen(s)==1) return true;
    int i,j;
    for(i=j=0;s[i]!='\0';i++){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
            s[j]=s[i];
            s[j]=(s[j] | ' ');      //题目不区分大小写，此处用到位运算，将其转化为小写
            j++;
        }
    }
    s[j]='\0';      //赋值完成后记得加上字符串结束标志
    i=0;                           
    for(;i<j/2;i++){
        if(s[i]!=s[j-i-1]) return false;
    }
    return true;
}
```