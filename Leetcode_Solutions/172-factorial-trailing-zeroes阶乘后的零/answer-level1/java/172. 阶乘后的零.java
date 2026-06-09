首先0肯定是2*5得来的，这里的2代表的是偶数，由于阶乘的规则是n*(n-1)*(n-2)*...*1,所以偶数这个条件可以不考虑，那么这个题就转换为求5的个数。
刚开始我想的是求每个因数中因子为5的个数，之后相加，这样老是会超出时间限制。
所以写了几个数之后找到个规律：
5！：1*5    1
10！：2*5   2
15！：3*5   3
...
25!:1*5*5   1+5
即不用每个数都去求然后相加。
```
class Solution {
	
    public int trailingZeroes(int n) {
        // 0的个数
    	int count = 0;
    	while(n>=5){
    		count += n/5;
    		n /= 5;
    	}
    	return count;
    }
    public static void main(String[] args){
    	int count = new Solution().trailingZeroes(125);
    	System.out.println(count);
    }
}
```
