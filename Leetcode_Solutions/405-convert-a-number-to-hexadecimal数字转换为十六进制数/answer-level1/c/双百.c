### 解题思路
垃圾代码

### 代码

```c
char intToChar(int d){
    if(d>=0&&d<=9){
        return '0'+d;
    }
    return 'a'+d-10;
}
void reverse(char*s,int low,int high){
    while(low<high){
        char t=s[low];s[low]=s[high];s[high]=t;
        low++;high--;
    }
}
char * toHex(int num){
    char*res=NULL;
    if(num==0){
        res=(char*)malloc(sizeof(int)*2);
        res[0]='0';res[1]=0;
        return res;
    }
    unsigned int mod=15,temp=(unsigned int)num,sum=0;
    while(temp>0){
        sum++;
        temp=temp>>4;
    }
    res=(char*)malloc(sizeof(char)*(sum+1));
    res[sum]=0;
    temp=(unsigned int)num;
    int index=0;
    while(temp>0){
        int k=temp&mod;
        res[index++]=intToChar(k);
        temp=temp>>4;
    }
    reverse(res,0,index-1);
    return res;
}
```