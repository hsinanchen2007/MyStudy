![QQ截图20191216163023.png](https://pic.leetcode-cn.com/b11de8b5cbe10e88ee58f8f065b62b9fc1f54b529441a3bf197fac04d57e3459-QQ%E6%88%AA%E5%9B%BE20191216163023.png)

一开始我先求出质数的排列组合a和非质数的排列组合b，两数相乘再模,发现n>28之后，答案就不对了。
看了解题才知道是因为js没有bigint。
然后就有了下面这种方法
```
代码块
var numPrimeArrangements = function(n) {
    var mod = 10**9+7;
    var h=1; 
    for(var i=2;i<=n;i++){
    	for (var j=2;j<i;j++) {
    		if (i%j==0 ) {      //求出非质数的个数h
 				h++;
    			break;
    		}
    	}
    }
    var z = n-h;        //求出质数的个数z
    var a=1;
    for (var i=1;i<=h;i++) {
    	a*=i;
        a=a%mod;
    }
    for (var i=1;i<=z;i++) {
    	a*=i;
        a=a%mod;
    }
   
    return(a%mod);
};
```

