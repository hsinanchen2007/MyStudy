|n阶楼梯|上楼梯种数|
|---|---|
|1|1|
|2|2|
|3|3|
|4|5|
|5|8|
|6|13|

**题目理解**

- 有n层楼梯，最后可以爬一层或者二层。
- a、如果最后爬一层，前面还有（n-1）层未爬，总共有f(n-1)种方法；
- b、如果最后爬两层，前面还有（n-2）层未爬，总共有f(n-2)种方法；
- 因此，总共有 f(n-1) + f(n-2) 种方法，
- 即f(n) = f(n-1) + f(n-2) 


*法一：递归*

缺点：n太大会超出时间限制，故不可取

```js
var climbStairs = function(n) {
    if(n <= 2) {
    	return n;
    } else {
    	return climbStairs(n-1) + climbStairs(n-2)
    }
};

var n = 45;
console.log(climbStairs(n))
```

*法二:动态规划*

```js
var climbStairs2 = function(n) {
    let result = new Array(n+1);
	result[1] = 1; //到第一阶有1种
	result[2] = 2; //到第二阶有2种

	for(let i = 3; i < n+1; i++){
		result[i] = result[i-1] + result[i-2];
	}

	return result[n];
}
```

