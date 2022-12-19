### 解题思路
递归

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function sumNums($n) {
        if($n==1) return $n;
        return $n+$this->sumNums($n-1);
    }
}
```