### 解题思路
利用C语言memset、memcpy和memcmp函数，使程序更简洁，可读性更强。

### 代码

```c
char s[10000];
char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize==0)//处理异常情况 如[]
        return "";
    for(int i=0;i<strsSize;i++){//处理异常情况 如["",""]
    	if(strlen(strs[i])==0)
    		return "";
	}

    int minl=strlen(strs[0]);
    for(int i=0;i<strsSize;i++){
    	if(strlen(strs[i])<minl)
    		minl=strlen(strs[i]);
	}//求出最短的那个字符串的长度
    int flag=1;
    memset(s,0,10000);//清除数据
    for(int j=minl;j>=1;j--){
        flag=1;
        memcpy(s,strs[0],j);//将str[0]的前j位赋给s
        for(int i=0;i<strsSize;i++){
            if(memcmp(s,strs[i],j)!=0){//比较s和strs[i]的前j位是否相同
                flag=0;//不相同，标识符置0，进入下一次循环
                break;
            }
        }
        if(flag==1){
            return s;//相同，s即为最大前缀，返回s，结束。（因为前缀的长度是从大到小判断的，所以只要是前缀，就必定是最大前缀）
        }
        memset(s,0,10000);//再次清除数据，否则s将无限变长，容易导致内存溢出
    }
    return "";
    
    
}
```