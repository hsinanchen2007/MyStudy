我们不妨假设，满足条件的一组解是[a,a+1,...,b],其中有b-a>=1.
那么根据等差数列求和公式，我们有：
        (a+b)(b-a+1) = 2*target;
所以我们可以得知，a+b和b-a+1是2*target的因子，肯定有:
        2*target%(b-a+1) == 0 
        a+b = 2*target/(b-a+1);
所以我们令b-a+1 = i,从i=2开始遍历，容易注意到b+a>b-a+1,所以i < sqrt(2*target);
不过由于题目要求的顺序，我们需要反过来遍历：
从i = ~~sqrt(2*target)开始反过来遍历到i=2.
另外，我们还要注意，b-a+1和a+b奇偶不同，所以我们还加上一条判断，2*target整除i且i+2target/i是奇数
对于这样的i，有：
        b-a+1 = i;
        a+b = 2*target/i.
解出a,b，得到对应的序列即可。

```
var findContinuousSequence = function(target) {
    var tot = [];
    var a;
    var b;
    for(i = ~~Math.sqrt(2*target);i >= 2;i--){
        if(2*target % i == 0 && (i + 2*target/i)%2 == 1){
            a = (2*target/i - i + 1)/2;
            b = (2*target/i + i - 1)/2;
            var h = [];
            for(j = a;j <= b;j++) h.push(j);
            console.log(h);
            tot.push(h);
        }
    }
    return tot;
};
```