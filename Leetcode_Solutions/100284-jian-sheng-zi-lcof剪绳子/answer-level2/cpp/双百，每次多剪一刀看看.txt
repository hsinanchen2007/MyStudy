### 解题思路
两个问题：
1. 给定绳长和可以剪的次数，最佳剪法是怎样的？
2. 给定绳长$n$，最多可以剪$n-1$次，依次比较最佳剪法。其实可以提前终止，如果剪$j$次不如剪$j-1$次，那再剪$j+1,j+2$次也只会有更差结果，因为会剪出很多长度为1，不贡献乘积。
对于问题1，最佳剪法是让每段绳长尽可能相等，比如$8$剪成2段，那就是$4+4$；剪成$3$段，就是$3+3+2$；.编程具体做法是先求出余数$r$，把余数分配再前$r$段上，每段分配$1$.比如长$8$分$3$段，$8/3=2...2$，把余数$2$分配到前两段，得到$3,3,2$。

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
		int best=0;
    	for(int i=2; i<58; i++) {
    		if (cutn(n, i) > best) 	// 如果多剪一段更好，那就不要犹豫，赶紧剪
    			best = cutn(n, i);
    		else
    			break;				// 多剪一段也没用，再多剪不可能好了
		}
		return best;
    }
    
    int cutn(int n, int i) { // 长n,剪i段
    	int j=n%i;	
    	int prod=1;			// 剪成i段的乘积
    	for(int k=0; k<i; k++) {
    		if(k < j)
    			prod *= (n/i + 1);
    		else
    			prod *= n/i;
		}
		return prod;
	}
};
```