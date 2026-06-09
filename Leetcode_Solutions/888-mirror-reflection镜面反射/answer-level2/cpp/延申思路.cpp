```
class Solution {
public://执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
//假设北墙不存在，可以想象镜面北面不断的翻转延申画个图就出来了
    int k,cnt;
    int mirrorReflection(int p, int q) {
        k = p*q/gcd(p,q);
        cnt = k/q;
        if(cnt%2==0) return 2;
        cnt = k/p;
        if(cnt%2==0) return 0;
        return 1;
    }
    inline int gcd(int a,int b) {return b==0?a:gcd(b,a%b);} 
};
```
