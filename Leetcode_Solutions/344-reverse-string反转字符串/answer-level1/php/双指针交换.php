### 解题思路
交换左右指针的数据

### 代码

```php
class Solution {

    /**
     * @param String[] $s
     * @return NULL
     */
    function reverseString(&$s) {
        $len = count($s);
        $left = 0;
        $regiht = $len - 1;

        while($left < $regiht){
            // 交换
            $swap = $s[$regiht];
            $s[$regiht] = $s[$left];
            $s[$left] =  $swap;
            $left++; $regiht--;
        }

        return $s;
    }
}
```