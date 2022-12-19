# 两种解法

![image.png](https://pic.leetcode-cn.com/6d22e035ad3edea40e8dd711b7ecd5d7aef5e60808507cbb5816035faea6b5d6-image.png)

迭代24ms
递归44ms

## 递归 (相对耗时 吃内存)

```
/**
     * 圆圈中最后剩下的数字(约瑟夫环) 递归解法
     * @param $n
     * @param $m
     * @return mixed
     */
    function lastRemainingReucr($n, $m) {
        return $this->findRecur($n, $m);
    }

    //递归解法
    function findRecur($n, $m) {
        if ($n == 0) return 0;
        $x = $this->findRecur($n - 1, $m);
        return ($x + $m) % $n;
    }
```

## 迭代 （相比递归效率高）

```
/**
     * 2020-03-30
     * 圆圈中最后剩下的数字(约瑟夫环) 迭代解法
     * @param Integer $n
     * @param Integer $m
     * @return Integer
     */
    function lastRemaining($n, $m) {
        $res = 0;
        for ($i = 2; $i < $n + 1; $i++) {
            $res = ($m + $res) % $i;
        }
        return $res;
    }
```
