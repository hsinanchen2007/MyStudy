### 解题思路
就单纯的写下日志大佬们别理我

### 代码

```c
int binaryGap(int N){
    int max=0,dist=1;
    while(N%2==0){
        N/=2;
    }
    if(N==1){
        return 0;
    }
    while(N>0){
        int t=N%2;
        if(t==0){
            dist++;
        }else{
            if(dist>max){
                max=dist;
            }
            dist=1;
        }
        N/=2;
    }
    return max;
}
```