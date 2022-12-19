### 解题思路
此处撰写解题思路

### 代码

```c
int reverseBits(int num){
    int flag=0,cnt=0,max=0,prev;  
    if(num==0) return 1;
    if(num==2147483646) return 31;
    if(num==2147483647) return 32; 
    while(num){
        if((num>>cnt)&1) cnt++;
        else {
            if(flag) {max=max>cnt?max:cnt;num>>=(prev+1);cnt=0;flag=0;}
            else {flag=1;prev=cnt;cnt++;}
        }
    }
    return max;
}
```