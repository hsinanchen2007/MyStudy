### 递归解题思路
递归需要注意2点：
1、每一次递归结果都需要取模，否则会溢出；
2、需要缓存f(n)的结果，否则每一次计算都太慢了，以空间换时间的做法。

### 递归代码

```php
class Solution {

    private $ans=[];

    /**
     * @param Integer $n
     * @return Integer
     */
    function fib($n) {
        return ($this->helper($n));
    }

    function helper($n){
        if($n<2) return $n;
        if(isset($this->ans[$n])) return $this->ans[$n];
        $return = ($this->helper($n-1)+$this->helper($n-2))%1000000007;
        $this->ans[$n] = $return;
        return $return;
    }
}
```

### 动态规划解题思路
每一个动态规划问题都有一个网格，正如背包问题(可参考《图解算法》第9章，通俗易懂)：每个网格=当前选项价值而+剩余网格容量的价值

动态规划不使用递归的办法，他是自底向上的办法，每次将结果都保存在网格中，使用的时候直接拿就可。

这里使用动态规划解决,动态规划需要写出状态转移方程：

![image.png](https://pic.leetcode-cn.com/e378625ef675ad3ab6afdd4866d6bce6e4d27398ab67f6f63199d9144220c6e8-image.png)


PS:啥叫状态转移方程？

说白了就是通项公式，比如f(n)是由f(n-1)+f(n-2)转移而来，这就是状态转移方程。

综上，动态规划需要：

1、自底向上的解决思路；

2、问题存在子问题重复，也就是需要通项公式(状态转移方程)

3、每个子问题都保存在网格中，便于后面大问题需要子问题的解时直接从网格取。

### 动态规划代码
```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function fib($n) {
        if($n<=1) return $n;
        $arr=[];
        $arr[0]=0;
        $arr[1]=1;
        for($i=2;$i<=$n;$i++){
            $arr[$i] = ($arr[$i-1]+$arr[$i-2])%1000000007;
        }
        return $arr[$n];
    }
}
```