一个数+它的反码都是111...111形式，即2^n-1。
换底公式求出（n-1）
class Solution {
public:
    int bitwiseComplement(int N) {
        if(!N)
        return 1;
        int i=log10(N)/log10(2);
        int temp=pow(2,i+1);
        return temp-1-N;
    }
};
```