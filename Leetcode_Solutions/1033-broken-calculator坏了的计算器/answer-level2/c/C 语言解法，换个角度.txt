### 解题思路
从 Y 推到 X

### 代码

```c
int abs(int a){return a>0?a:a*(-1);}
int brokenCalc(int X, int Y){
    int ans=0;
    
    if(Y<X) return X-Y;

    while(X<Y){
        if(Y%2==0){//若是偶数
            Y/=2; ans++;
        }else{
            Y++;ans++;
        }
    }
    if(X>Y) ans+= X-Y;

    return ans;
}
```