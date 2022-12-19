### 解题思路
（1）遍历，把所有字母代表的数加上
（2）选出特殊情况，减去多加上的数

### 代码

```c
int romanToInt(char * s){
    int i=0,j=0,sum=0;
    while(*(s+i)!='\0'){
        switch(*(s+i)){
            case 'I':sum=sum+1;break;
            case 'V':sum=sum+5;break;
            case 'X':sum=sum+10;break;
            case 'L':sum=sum+50;break;
            case 'C':sum=sum+100;break;
            case 'M':sum=sum+1000;break;
            case 'D':sum=sum+500;break;
        }
        i++;//i=7
    }
    while(*(s+j)!='\0'&&j<i){// 0 1
        if(*(s+j)=='I'&&*(s+j+1)=='V') 
            {
                sum=sum-2;
                j++;
            }
        if(*(s+j)=='I'&&*(s+j+1)=='X') 
            {
                sum=sum-2;
                j++;
            }
        if(*(s+j)=='X'&&*(s+j+1)=='L') 
            {
                sum=sum-20;
                j++;
            }
        if(*(s+j)=='X'&&*(s+j+1)=='C') 
            {
                sum=sum-20;
                j++;
            }
        if(*(s+j)=='C'&&*(s+j+1)=='D') 
            {
                sum=sum-200;
                j++;
            }
        if(*(s+j)=='C'&&*(s+j+1)=='M') 
            {
                sum=sum-200;
                j++;
            }
        j++;
    }
    return sum;

}
```