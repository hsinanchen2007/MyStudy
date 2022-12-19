1. 灵感来自赞最多的java 解法，简介 干脆 利落，上代码：


![image.png](https://pic.leetcode-cn.com/610a9734f69840b5102c1a0528145804977eae52d4b91e00b73291298e3ac752-image.png)

```
/**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
    function isFlipedString($s1, $s2) {
       return $s1 === $s2 or strpos($s1 . $s1, $s2);
    }
```
