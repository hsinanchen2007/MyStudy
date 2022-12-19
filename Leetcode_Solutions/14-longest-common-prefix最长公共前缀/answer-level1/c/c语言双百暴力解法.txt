### 解题思路
设置count指向第一个字符串下标处字符，循环遍历之后的每一个字符串该下标处字符是否相同。最后得到最后一个公共字符的后一个位置并设置为'\0'返回即可

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
//以下三行只为应对输入[]时，更好看的写法请教教我
char c='\0';
char *p=&c;  
if(strs==NULL||strsSize==0)return p;//手动返回空串，显得比较蠢。。。
int count=0;//记录公共前缀字符下标
int flag=1; 
while(flag){
    for(int i=0;i<strsSize;i++){
        if(strs[i][count]!=strs[0][count]||count==strlen(strs[i])){
            flag=0;
            break;
        }
    }
    if(flag)
        count++;
}
strs[0][count]='\0';//直接在第一个字符串操作
return strs[0];
}
```