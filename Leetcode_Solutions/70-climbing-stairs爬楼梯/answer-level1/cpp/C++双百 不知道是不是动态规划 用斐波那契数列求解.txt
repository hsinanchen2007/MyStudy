
题目一次只能走1步或者2步，那么当上n（n>=2）级台阶的时候可以通过递推式得到
** f(n)=f(n-1)+f(n-2)**
解释：
1. f(n-1) - 当上n级之前上了n-1级，那么最后只有一种走法，再上1级；
2. f(n-2) - 当上n级之前上了n-2级，本来最后还可以有两种走法到n即f(n-2)+1+1/f(n-2)+2，但是f(n-2)+1+1的那种方法应该归类到f(n-1)中（相当于f(n-1)+1），所以也只有一种走法，就是再上2级；
因此采用递推式，该递推式即斐波那契数列，用循环法求取
```
class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int fnminusone=2, fnminustwo=1, ans=0; // f(n-1)和f(n-2)

        n-=2;
        while(n--){
            ans = fnminusone+fnminustwo;
            fnminustwo = fnminusone;
            fnminusone = ans;
        }
        return ans;
    }
};
```

