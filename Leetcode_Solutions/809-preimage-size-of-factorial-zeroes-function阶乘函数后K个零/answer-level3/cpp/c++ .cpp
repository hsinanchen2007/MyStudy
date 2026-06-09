首先，在阶乘中每五个零会变一次，可能加1，可能加2.
答案只可能是0或者5，这个很多作者已经说过了。
我是模拟加1还是加2还是3，来计算多次，查看是否符合。

求和中可能会数字太大，没有做优化直接用了longlong
查找边界也是用了简单方法，不会出错就是需要数字大一点。
```
class Solution {
public:
    int getsum(int num){
        long long temp = 1;
        long long time = 0;
        while(temp <= num){
            temp *= 5;
            time++;
        }
        temp /= 5;
        long long sum = 0;
        long long tempsum = 0;
        while(time){
            sum += (num / temp - tempsum)* time;
            tempsum += (num / temp - tempsum);
            temp /= 5;
            time--;
        }
        int ss = sum;
        return ss;
    };
    int preimageSizeFZF(int K) {
        if(K<5) return 5;
        //int left=0,right=K+1;
        int left,right;
        for(int i=5;i<K;i+=K/10){
            if(getsum(i) <= K && getsum(i+K/10) >= K){
                left = i;
                right = i+K/10;
            }
        }
        while(left < right){
            int center = (left + right)/2;
            int numzero = getsum(center);
            if(numzero > K)
                right = center;
            else if(numzero < K)
                left = center+1;
            else
                return 5;
        }
        return 0;
    }
};
```
