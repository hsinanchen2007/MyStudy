### 解题思路
遍历

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Boolean
     */
    function isMonotonic($A) {
        return $this->increase($A) || $this->decrease($A);
    }

    public function increase($A)
    {
        for ($i = 0; $i < count($A) - 1; $i++) {
            if ($A[$i + 1] < $A[$i]) return false;
        }

        return true;
    }

    public function decrease($A)
    {
        for ($i = 0; $i < count($A) - 1; $i++) {
            if ($A[$i + 1] > $A[$i]) return false;
        }

        return true;
    }
}
```

### 算法复杂度
- 时间复杂度：O(n)
- 空间复杂度: O(1)