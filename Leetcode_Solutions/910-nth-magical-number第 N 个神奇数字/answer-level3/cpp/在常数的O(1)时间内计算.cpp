### 解题思路
要找到第N个可以被A或者B整除的数，很自然想到用数学的解法去解决。
首先，我是从几个例子中找到规律的
当A=7，B=13时，列出其神奇数组：(7,13,14,21,26,28,35,39)
若转化为a*A与b*B的形式：(7*1,13*1,7*2,7*3,13*2,7*4,7*5,13*3)
从上面的这个数组可以知道一个规律，当A<B的时候，在(x-1)*B与x*B之间，必存在至少一个y，使得(x-1)*B<y*A<x*B。
以上就是我们的推论一，即当A<B的时候，在(x-1)*B与x*B之间，必存在至少一个y，使得(x-1)*B<y*A<x*B。
要得出结果，还需要处理，当最小公约数S以及n*S(n为正整数)出现时,会对个数产生重叠，举个例子：
当A=2，B=3时，列出其神奇数组：(2,3,4,6,8,9,10,12)
若转化为a*A与b*B的形式：(2*1,3*1,2*2,2*3(3*2),2*4,3*3,2*5,2*6(3*4))
那么这里，我们就把一个最小公约数内的长度作为一个周期，以上面的例子来说，就是每4个长度为一个周期，之后重新计数。
所以，设A与B的最小公约数内的长度为T，那么，我们的个数N=t*T+K。
t个周期之后，是K个数，那么，我们就可以得出结论：
Result=t*S+a*A(或者b*B)
此时我们就可以用到推论一了，由于在一个周期内，我们可以直接认为在使用推论一时，是没有最小公约数的影响的。
那么，若：K=N%T，则设a+b=K，那么，由(x-1)*B<y*A<x*B得出：
(K-a-1)*B<a*A<(K-a)*B
最后得出：
![K56UE(S87$FZ63NKUPJX0QB.png](https://pic.leetcode-cn.com/656573131b09e6db69b98810dcaf71b08e4528f418c62143e8324cce25c97587-K56UE\(S87$FZ63NKUPJX0QB.png)
最后一步，要得出最终结果，即选A*a还是选B*b
还是举例子：
当A=7，B=13时，a的范围一次为((13/20,26/20),(26/20,39/20),(39/20,52/20),(52/20,65/20),(65/20,78/20),(78/20,91/20))
从上面可以看出，有时a的范围并不能取到一个整数，这个时候就是取B了，最终就可以得出结果
当a的范围包含整数时，取Result=t*S+a*A
当a的范围不包含整数时，Result=t*S+b*B
下面就是代码

### 代码

```cpp
class Solution {
public:
    int find(int A,int B){
        if(B==0) return A;
        return find(B,A%B);
    }
    int nthMagicalNumber(int N, int A, int B) {
        if(A>B){
            int temp=A;
            A=B;
            B=temp;
        }
        if(B%A==0){
            return static_cast<long long>(N)*A%1000000007;
        }
        int gongyue=find(A,B);
        int gongbei=A*B/gongyue;
        int Bei=gongbei/A+gongbei/B-1;
        int BN=N/Bei;
        int num=N%Bei;
        double BAB=static_cast<double>(B)/(A+B);
        double L=BAB*num;
        double R=BAB*(num+1);
        int left=static_cast<int>(L);
        int right=static_cast<int>(R);
        long long res;
        if(left==right) res=(num-left)*B;
        else res=right*A;
        res+=static_cast<long long>(BN)*gongbei%1000000007;
        res=res%1000000007;
        return static_cast<int>(res);
    }
};
```