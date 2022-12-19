直接暴力算排列组合计算过程中会超过2^32-1，加了两个优化：1.边除边算，发现中间还是会溢出 又加了2.算C(m+n-2，min(m-1,n-1))，这样算的会更少一点。其实第二个优化应该是很自然加上去的。事实上直接用Long就完事儿了，我搁这儿优化个锤子
```
class Solution {
    fun uniquePaths(m: Int, n: Int): Int {
        if(m>n){
            return uniquePaths(n,m)
        }
        var res=1
        var i=1
        var j=m-1
        while(true){
            if(res%i==0&&i<=m-1){
                res/=i
                i++
            }else{
                if(j>=1){
                    res*=n-1+j
                    j--
                }else{
                    return res
                }
            }
        }
    }
}
```
