![QQ截图20191024092652.png](https://pic.leetcode-cn.com/64b620dc687f6699414d9722a111f8112db3be3131baf0b5f89949e47bc329ed-QQ%E6%88%AA%E5%9B%BE20191024092652.png)


求a的b次方余c，然而b是一个超大整数，远远大于long long 的表示范围，但是你用大整数乘法也做不了，
因为要取模。。。。呢就直接切入正题好了，既然幂次很大，呢肯定是要降幂了，其实做这道题你就能想到
肯定有一种降幂公式，因为要用到欧拉函数，呢这里就讲一下欧拉函数的具体概念及其求法好了。。。

欧拉函数是指：对于一个正整数n，小于n且和n互质的正整数（包括1）的个数，记作φ(n) 。

通式：φ(x)=x*(1-1/p1)*(1-1/p2)*(1-1/p3)*(1-1/p4)…..(1-1/pn),其中p1, p2……pn为x的所有质因数，x是不为0的整数。φ(1)=1（唯一和1互质的数就是1本身）。

对于质数p，φ(p) = p - 1。注意φ(1)=1.

欧拉定理：对于互质的正整数a和n，有aφ(n) ≡ 1 mod n。

欧拉函数是积性函数——

若m,n互质，φ(mn)=φ(m)φ(n)。

若n是质数p的k次幂，φ(n)=p^k-p^(k-1)=(p-1)p^(k-1)，因为除了p的倍数外，其他数都跟n互质。

特殊性质：当n为奇数时，φ(2n)=φ(n)

欧拉函数还有这样的性质：

设a为N的质因数，若(N % a == 0 && (N / a) % a == 0) 则有E(N)=E(N / a) * a；若(N % a == 0 && (N / a) % a != 0) 则有：E(N) = E(N / a) * (a - 1)。

求欧拉函数的具体代码：
```
long ol(long x)
{
	long i,res=x;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			res=res-res/i;
			while(x%i==0)
				x/=i;
		}
	}
	if(x>1)
		res=res-res/x;
	return res;
}
```

欧拉函数知道后，呢就直接上降幂公式了，该公式的证明就不在说了，挺难的。
直接上公式吧，毕竟还是很好记的。。。。
![786945-20161122214248346-633478961.gif](https://pic.leetcode-cn.com/438e345e5c33d9a170fba3e5d5a8344e857109a867a915bae4443bc215d67ea9-786945-20161122214248346-633478961.gif)
（降幂公式中 phi() 为欧拉函数）

```
class Solution {
    public int superPow(int a, int[] b) {
        int c=ol(1337);
        int sum=0;
        for(int i=0;i<b.length;i++)
        	sum=(sum*10+b[i])%c;
        sum+=c;
        return q((long)a,sum,1337);
    }
    
    private int q(long x,int y,int M) {
    	long res=1;
    	while(y>0) {
    		if(y%2>0)
    			res=res%M*x%M;
    		x=x%M*x%M;
    		y/=2;
    	}
    	return (int)res;
    }
    
    private int ol(int x) {
    	int res=x;
    	for(int i=2;i*i<=x;i++) {
    		if(x%i==0) {
    			res=res-res/i;
    			while(x%i==0)
    				x/=i;
    		}
    	}
    	if(x>1) res=res-res/x;
    	return res;
    }
}
```

