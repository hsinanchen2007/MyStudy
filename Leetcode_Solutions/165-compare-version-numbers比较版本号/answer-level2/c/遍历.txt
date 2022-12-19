### 解题思路
此处撰写解题思路

### 代码

```c
int compareVersion(char * version1, char * version2){
    int i=0,j=0,a,b;
    while(i<strlen(version1)||j<strlen(version2)){
        a=0,b=0;
        while(i<strlen(version1)&&version1[i]!='.'){
            a=a*10+version1[i++]-'0';
        }
        while(j<strlen(version2)&&version2[j]!='.'){
            b=b*10+version2[j++]-'0';
        }
        i++;
        j++;
        printf("a=%d b=%d\n",a,b);
        if(a>b) return 1;
        else if(a<b) return -1;
    }
    return 0;
}
```