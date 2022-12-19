### 解题思路
先计算目标字符个数，然后取其最小值。
![微信截图_20200328083244.png](https://pic.leetcode-cn.com/515ae9755f92dfe992ef11d83489c0571791b7e41664185266c6218ea07b9667-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200328083244.png)

### 代码

```php
class Solution {

    /**
     * @param String $text
     * @return Integer
     */
    function maxNumberOfBalloons($text) {
        $b_count = substr_count($text,'b');
        $a_count = substr_count($text,'a');
        $l_count = substr_count($text,'l');
        $o_count = substr_count($text,'o');
        $n_count = substr_count($text,'n');
        return min($b_count,$a_count,(int)($l_count/2),(int)($o_count/2),$n_count);
    }
}
```