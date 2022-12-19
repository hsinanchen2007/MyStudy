官方的解法很全面了，自己的解法是属于第5种的变体，减少了一些调用、数据和乘法数量
# 矩阵改进
Your runtime beats 100 % of c submissions
Your memory usage beats 100 % of c submissions (5.2 MB)
由于斐波那契的矩阵递归实际上在右上角和左下角是相同的，所以可以在这一点上做文章，减少了一些运算。
```
int fib(int N){
    if (N == 0) return 0;
    if (N < 3) return 1;
    // f1 f0 f-1
    int tmp[3] = {1, 1, 0};
    int res[3] = {1, 0, 1};
    int multi_support;
    int tmp0_back;

    for (; N != 0; N >>= 1)
    {
        // one cycle 9 multiplication and 6 addition
        // logn cycles
        if (N & 1) {
            multi_support = tmp[1]*res[1];
            res[0] = tmp[0]*res[0] + multi_support;
            res[1] = tmp[0]*res[1] + tmp[1]*res[2];
            res[2] = multi_support + tmp[2]*res[2];
        }
        multi_support = tmp[1] * tmp[1];
        tmp0_back = tmp[0];
        tmp[0] = tmp[0]*tmp[0] + multi_support;
        tmp[1] = tmp[1] * (tmp0_back + tmp[2]);
        tmp[2] = multi_support + tmp[2]*tmp[2];
    }
    return res[1];
}
```
# 二倍项关系解题
和矩阵有异曲同工之妙
```
class Solution {
public:
    unordered_map<int,int> map;
    int fib(int N) {
        if(N == 0){
            return 0;
        }
        if(N < 3){
            return 1;
        }
        if(map.count(N)){
            return map[N];
        }
        int temp0 = fib(N/2);
        int temp1 = fib(N/2+1);
        int temp = (N % 2) ? (temp0*temp0 + temp1*temp1) :
                            (temp0*((temp1<<1)-temp0));
        map.insert(make_pair(N,temp));
        return temp;

    }
};
```

