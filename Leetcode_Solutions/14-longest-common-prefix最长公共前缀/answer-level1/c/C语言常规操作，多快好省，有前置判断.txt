### 解题思路
![图片.png](https://pic.leetcode-cn.com/fc82e50a90171c23df493ac720095f79b9087f97753cf8be680654892d79ef0f-%E5%9B%BE%E7%89%87.png)


### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    int minlen=0x7fffffff;
    char *output="";
    if(strsSize==0){
        return output;
    }
    for(int i=0;i<strsSize;i++){
        int len=strlen(strs[i]);
        if(len==0){
            return output;
        }
        minlen=minlen<len?minlen:len;
    }
    output=(char*)malloc(sizeof(char)*minlen+1);
    int n=0;
    for(int i=0;i<minlen;i++){
        char a=strs[0][i];int flag=0;
        for(int j=1;j<strsSize;j++){
            if(a!=strs[j][i]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            output[n++]=a;
        }else{
            break;
        }
    }
    output[n]='\0';
    return output;
}
```