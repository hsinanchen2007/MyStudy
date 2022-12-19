思路：
令n=a+(a+1)+...+(a+k) 其中k=0,1,2...,a=1,2,...
即n=a(k+1)+k(k+1)/2,化简得
2n/(k+1)-k=2a;
可知对于k取值范围满足k>=0,k*(k+1)<2*n，若2n/(k+1)为整数且2n/(k+1)-k为偶数即为有效解。
代码如下：
```
int consecutiveNumbersSum(int N){
    int cnt=0;
    for(int i=0;i*(i+1)<2*N;i++){
        if((2*N)%(i+1)==0&&((2*N)/(i+1)-i)%2==0) cnt++;
    }
    return cnt;
}
```
