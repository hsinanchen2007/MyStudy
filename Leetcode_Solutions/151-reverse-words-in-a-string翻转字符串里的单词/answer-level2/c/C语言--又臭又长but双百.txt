### 解题思路
首先反转字符串；
然后去首尾和中间多余的空格；
最后再反转单词。

### 代码

```c
char * reverseWords(char * s){
    int len = strlen(s), i, j=0, size=0;
    char* ans = (char *)malloc(sizeof(char) * (len+1));
    char temp;
    bool flag;

    for(i=len-1; i>=0; i--){
        if(s[i]==' ' && j==0)
            continue;
        
        if(s[i]!=' '){
            flag = false;
            ans[j++] = s[i];
        }else{
            if(!flag){
                ans[j++] = s[i];
                flag = true;
            }else
                continue;
        }
    }

    if(j>0 && ans[j-1]==' '){
        ans[j-1] = '\0';
        len = j-1;
    }else{
        ans[j] = '\0';
        len = j;
    }

    for(i=0; i<len; i++){
        if(ans[i]!=' ')
            size++;
        else{
            for(j=0; j<size/2; j++){
                temp = ans[j+i-size];
                ans[j+i-size] = ans[i-1-j];
                ans[i-1-j] = temp;
            }
            size = 0;
        }

        if(i==len-1){
            for(j=0; j<size/2; j++){
                temp = ans[j+i-size+1];
                ans[j+i-size+1] = ans[i-j];
                ans[i-j] = temp;
            }
        }
    }

    return ans;
}
```