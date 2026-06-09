### 解题思路
老贪心了

### 代码

```c
int balancedStringSplit(char * s){
    int sum=0,res=0;
    while(*s!=0){
        if(*s=='L'){
            sum++;
        }else{
            sum--;
        }
        if(sum==0){
            res++;
        }
        s++;
    }
    return res;
}
```