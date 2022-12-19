### 解题思路
![Snipaste_2020-03-18_15-19-29.png](https://pic.leetcode-cn.com/431ba5931ff04027c19610b75240501e23dfcf56100edb1fe90ab41c8e223eb8-Snipaste_2020-03-18_15-19-29.png)


### 代码

```c
char * defangIPaddr(char * address){
    int i=0,k=0;
    char* res=(char*)malloc((strlen(address)+7)*sizeof(char));
    while(address[i]!='\0'){
        if(address[i]=='.'){
            res[i+2*k]='[';
            res[i+2*k+1]='.';
            res[i+2*k+2]=']';
            k++;
        }else{
            res[i+2*k]=address[i];
        }
        i++;
    }
    res[i+6]='\0';
    return res;
}
```