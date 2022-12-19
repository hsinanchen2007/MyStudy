### 解题思路


### 代码


```c

bool canPermutePalindrome(char* s){
    int k=strlen(s);
    if(k<=1) return true;
    int i,j,count,x=0;
    for(i=0;i<k-1;i++){
        count=1;
        for(j=i+1;j<k;j++){
            if(s[j]!='#'&&s[i]==s[j]){
                count++;
                s[j]='#';
            }
        }
        if(count%2==0) x=x+count;
        else x=count-1+x;
    }
    if(k%2!=0) x=x+1;
    if(x==k) return true;
    else return false;

}

```


```c
bool canPermutePalindrome(char* s){
    int k=strlen(s);
    if(k<=1) return true;
    int hash[128]={0};
    int i=0;
    while(s[i]!='\0'){//存储每个字母出现的次数
        hash[s[i]]++;
        i++;
    }
    int num=0;
    for(i=0;i<128;i++){
        if(hash[i]%2){
            num++;
        }
    }
    if(num>1) return false;//出现次数为奇数的字母不止一个
    return true;
}
```






