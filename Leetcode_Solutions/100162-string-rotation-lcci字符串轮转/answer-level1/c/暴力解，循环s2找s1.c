### 解题思路
此处撰写解题思路

### 代码

```c
bool isFlipedString(char* s1, char* s2){
    int m=0,i,j=0;
    int len2=strlen(s2);
    int len1=strlen(s1);
    if(len1!=len2)
        return false;
    if(len1==0&&len2==0)
        return true;
    for(i=0;i<len2;i++){
        m=0;
        if(s2[i]==s1[m]){
            for(j=i;j<i+len1;j++){
                if(s1[m]==s2[j%len2]){
                    m++;
                }else{
                    break;
                }
            }
            if(m==len1){
                return true;
            }
        }

    }
    return false;
}
```