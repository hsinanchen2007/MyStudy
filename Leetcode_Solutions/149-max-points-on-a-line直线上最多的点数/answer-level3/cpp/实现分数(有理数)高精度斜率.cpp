思想很简单，双层遍历，求出任意两点之间斜率，使用哈希映射统计个数。Time O(n^2), Space O(n^2)。
难点在于，无论是用单精度浮点数还是双精度浮点数作为斜率（哈希KEY），都会有误差，那么自己实现一个分数类Fraction，从根本上解决精度。
特别注意，斜率为无穷大时，强制转成1/0;同一个点情况，0/0。做特殊处理。
```
class Solution {
    struct Fraction{
        int num, den;    // numerator, denominator
        bool sign;
        Fraction(int n, int d, bool s=true):num(n),den(d),sign(s){}
    };
    struct FractionHash{
        static int gcd(int a, int b){
            if(a==0 || b==0) return a?a:b;
            return gcd(b,a%b);
        }
        bool operator()(const Fraction &a, const Fraction &b)const{
            return (a.sign?1L:-1L)*a.num*b.den==(b.sign?1L:-1L)*b.num*a.den;    // math
        }
        size_t operator()(const Fraction &f)const{
            int r=gcd(f.num,f.den);
            if(r==0) return 0;    // 0/0
            long n=labs(1L*f.num/r), d=labs(1L*f.den/r);
            return (n<<32)|d;
        }
    };
public:
    int maxPoints(vector<vector<int>>& points) {
        int mx=0;
        for(const auto &p:points){
            int x=p[0], y=p[1], pc=0, m=0;
            unordered_map<Fraction,int,FractionHash,FractionHash> ks;
            for(const auto &q:points){
                if(!(p==q)){
                    Fraction k(x-q[0], y-q[1]);
                    m=max(m,++ks[k]);    // line k's points except p
                }
                else ++pc;    // point p count
            }
            mx=max(mx,m+pc);
        }
        return mx;
    }
};
```
另外，可以进一步优化，把所有点加入哈希映射中，key为点，val为该点的个数，降低遍历次数。
![深度截图_选择区域_20191120160730.png](https://pic.leetcode-cn.com/c6c020e59253f507bfb874cff62d5d082d3846bcbe438e024cf2c5e29cef3c6d-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20191120160730.png)
