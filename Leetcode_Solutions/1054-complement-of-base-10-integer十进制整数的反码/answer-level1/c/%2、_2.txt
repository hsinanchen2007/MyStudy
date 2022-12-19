### 解题思路
此处撰写解题思路

### 代码

```c
int bitwiseComplement(int N){
    if(N==0) return 1;
    int a[32],i,s=0;
    for(i=0;N!=0;i++){
        a[i]=(N%2==0);
        N/=2;
    }
    for(i--;i>=0;i--)
        s=s*2+a[i];
    return s;
}
```