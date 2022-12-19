### 解题思路

采用康托编码的思路。其实就是康托展开的逆过程。康托展开用来求某个全排列数是第几小的数，也就是当这些数按顺序排时第几个数。

过程如下：比如求321 是 第几小的，可以这样来想：小于3的数有1和2 两个，首位确定之后后面两位有2！中情况，所以共有2*2！=4种。

小于2的数只有一个1，所以有1*1！=1种情况，最后一位是1，没有比一小的数，所以是0*0！=0

综上：小于321的数有4+1=5个，所以321是第六小的数。


逆过程就是已知这个数是第k个数，求这个数是多少，当然是知道n的值的。

第k个数就是有k-1个数比这个数小。

所以就是 k-1=an*(n-1)!+an-1*(n-2)!+....+a1*0!;

再举一个例子：

如何找出第16个（按字典序的）{1,2,3,4,5}的全排列？
 
1. 首先用16-1得到15
 
2. 用15去除4! 得到0余15
 
3. 用15去除3! 得到2余3
 
4. 用3去除2! 得到1余1
 
5. 用1去除1! 得到1余0
 
有0个数比它小的数是1，所以第一位是1
 
有2个数比它小的数是3，但1已经在之前出现过了所以是4
 
有1个数比它小的数是2，但1已经在之前出现过了所以是3
 
有1个数比它小的数是2，但1,3,4都出现过了所以是5
 
最后一个数只能是2
 
所以排列为1 4 3 5 2



### 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n,'0');
        string result;
        for(int i=0;i<n;i++)
        {
            s[i]+=i+1;
        }
        return kth_permutation(s,k);
    }
private:
    int factorial(int n)
    {
        int result=1;
        for(int i=1;i<=n;i++)
        {
            result*=i;
        }
        return result;
    }

    string kth_permutation(string &s,int k)
    {
        const int n=s.size();
        string result;

        int base=factorial(n-1);
        --k;
        for(int i=n-1;i>0;k=k%base,base/=i,--i)
        {
            auto a =s.begin()+k/base;
            result.push_back(*a);
            s.erase(a);
        }
        result.push_back(s[0]);
        return result;
    }
};
```