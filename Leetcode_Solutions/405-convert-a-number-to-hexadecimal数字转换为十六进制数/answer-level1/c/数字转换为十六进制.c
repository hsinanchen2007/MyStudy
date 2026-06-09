### 解题思路
位操作，一次取四位。

### 代码

```c


char * toHex(int num){
    if(num==0) return "0";
    char *temp=(char*)malloc(sizeof(char)*9);   //多申请一位
    int i,k=0,res;
    for(i=0;i<8;i++){
        res=num&0x0000000f;             //取num最后4位
        if(res<=9)temp[k++]=res+'0';
        if(res>9)temp[k++]=res-10+'a';
        num>>=4;
    }
    temp[k]='\0';
    for(i=0,res=k-1;i<res;i++,res--){   //将字符串逆置
        char ch=temp[i];
        temp[i]=temp[res];
        temp[res]=ch;
    }
    char *p=temp;
    while(*p=='0')p++;              //去除字符串中多余的前导零
    return p;
}


```