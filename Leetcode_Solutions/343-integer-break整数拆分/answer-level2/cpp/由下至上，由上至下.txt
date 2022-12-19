### 解题思路
暴力搜索->记忆化搜索->动态规划,
费劲，参考别人的
### 代码

```cpp
class Solution {
// public:
//     int integerBreak(int n) {
    //     int num;
    //     int a=0,b=1;
    //     for(int num=2;a<b;num++){
    //         a = mymax(n,num);
    //         b = mymax(n,num-1);
    //     }
    //     return b;
    // }
    // int mymax(int n,int num){
        
    //     int a=n/num;
    //     int s=1,m=s;
    //     for(int i=num;i>0;i--){
    //         a = n/num;
    //         n=n-a;
    //         if(n/num < num) a=n;
    //         s*=a;
    //         m = m>s?m:s;
    //     }
    //     return m;

    //暴力 迭代法，超时
    // if (n == 2) {
    //     return 1;
    // }
    // int res = -1;
    // for (int i = 1; i <= n - 1; i++) {
    //     res = max(res, max(i * (n - i), i * integerBreak(n - i)));
    // }
    // return res;
    
    //改成记忆化搜索一般需要两个函数才行，因为需要维护new的数组空间吧，都在一个函数里就乱了
// public:     
//     int *memory;
//     int integerBreak(int n) {
//     memory= new int[n + 1]{0};  //初始化都要是0 才行，默认的应该是随机值，所以报错，坑了好久
//     return f(n);
// }
// public: int f(int n) {
//     if (n == 2) {
//         return 1;
//     }
//     // 记忆化的核心
//     if (memory[n] != 0) {  // memory的初始值为0，如果它不为0，说明已经计算过了，直接返回即可
//         return memory[n];
//     }
//     int res = -1;
//     for (int i = 1; i <= n-1 ; i++) {
//         res = max(res, max(i * f(n - i), i * (n - i))); //f(n - i)和 (n - i) 比较大小
//     }
//     memory[n] = res;
//     return res;
//     }

public:     
    int integerBreak(int n) {
    int m[n+1] = {0};
    m[2]=1;
    for(int i =3 ; i<=n ;i++){
        for(int j=1;j<i;j++){
            m[i] = max(m[i],max(j*m[i-j],j*(i-j)));
        }
    }

    return m[n];
}

};
















```