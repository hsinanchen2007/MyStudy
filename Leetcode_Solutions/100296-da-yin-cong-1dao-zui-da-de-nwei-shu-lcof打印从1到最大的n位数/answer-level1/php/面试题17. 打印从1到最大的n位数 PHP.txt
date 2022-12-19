### 解题思路
常规方法循环输出，终止条件为 10 的 n 次方 （也就是 n 位数的最大值 +1）

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer[]
     */
    function printNumbers($n) {
        $i = 1;
        $result = [];

        while(true) {

            if($i == pow(10, $n)) {
                break;
            }

            $result[] = $i++;    
        }

        return $result;
    }
}
```