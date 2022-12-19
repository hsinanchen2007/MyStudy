### 解题思路
逆向思维，到2X>=Y时输出结果

### 代码

```c
int brokenCalc(int X, int Y){
    int ret = 0;
    int cnt = 0;
    if (X > Y) return X - Y;
    while(X != Y) {
        if ((X >= Y/2) && (X < Y)) {
           ret = (X - Y+1/2 + 1) < (Y - X)? (X - Y/2 + 1):(Y - X);   
           return ret + cnt;    
        } 
        if(Y % 2) {
            Y += 1; 
            cnt++;
        } else {
            Y /= 2;
            cnt++;
        }       
    }
    return ret; 
}
```