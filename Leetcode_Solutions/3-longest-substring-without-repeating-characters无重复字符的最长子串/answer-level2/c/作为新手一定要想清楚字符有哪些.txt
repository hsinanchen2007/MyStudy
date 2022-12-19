### 解题思路
此处撰写解题思路

### 代码

```c
int lengthOfLongestSubstring(char * s){
    long char_len;
    int i,j,k,repeat,*count;
    char_len=(long)strlen(s);                        
    count=(int*)malloc(sizeof(int)*(char_len+1));       
    
    if(s[0]=='\0') return 0;
    for(i=0;i<char_len;i++){
        count[i]=1;
    }

    for(i=0;i<char_len-1;i++){
        for(j=i+1;j<char_len;j++){
            for(k=i;k<j;k++){
                if(s[k]==s[j]){
                    repeat=1;
                    break;
                }
                
            }
            if(repeat==1){
                repeat=0;
                break;
            }
            else count[i]++;
        }
    }
    k=count[0];

    for(i=1;i<char_len;i++){
        if(k<count[i]) k=count[i];
    }
    return k;
}
```