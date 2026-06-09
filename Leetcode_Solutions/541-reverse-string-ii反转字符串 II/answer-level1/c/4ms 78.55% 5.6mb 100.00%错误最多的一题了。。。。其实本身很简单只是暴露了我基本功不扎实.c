### 解题思路
此处撰写解题思路

### 代码

```c
void reverse(char*s,int low,int high){
    while(low<high){
        char t=s[low];s[low]=s[high];s[high]=t;
        low++;high--;
    }
}
char * reverseStr(char * s, int k){
    int i=0;
    int t=0;
    for(i=0;s[i]!=0;i++){
        t=(i+1)%(k<<1);
        if(t==0){
            reverse(s,i+1-(k<<1),i-k);
        }
    }
    i--;
    t=(i+1)%(k<<1);
    if(t==0){
        return s;
    }
    if(t<k){
        reverse(s,i+1-t,i);
    }else{
        reverse(s,i+1-t,i-t+k);
    }
    return s;
}
```