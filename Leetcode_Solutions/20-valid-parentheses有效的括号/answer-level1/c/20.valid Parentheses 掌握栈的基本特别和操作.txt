### 解题思路
根据题意，成对出现才是true，因此count用来判断是否成对:

遍历字符串：

1）如果当前字符为左半边括号时，则count++，并将其保存到ptr中

2）如果遇到右半边括号时，则count--；

3）如果左右都没有遇到，返回 false

最后根据count值判断：

1）count = 0，说明成对出现，返回true

2）count != 0,说明不是成对出现，返回false

最后，记得处理空字符串，释放申请的空间

### 代码

```c
bool isValid(char * s){
    int i,count=0;  
    int len = strlen(s);
    //处理空字符串。
    if(len==0) return true;    
    char *ptr = (char *)malloc(sizeof(char)*(len+1));  
    memset(ptr,0,len+1);
    for(i=0;i<len;i++)
    {
        if((s[i]=='(')||(s[i]=='{')||(s[i]=='[')){
            count++;
            ptr[count]=s[i];
            
        }
        else if((s[i]==ptr[count]+1)||(s[i]==ptr[count]+2)){
            count--;
        }      
        else  return false;   
    }
    free(ptr);
    
    if(count) return false;
    return true;
}
```