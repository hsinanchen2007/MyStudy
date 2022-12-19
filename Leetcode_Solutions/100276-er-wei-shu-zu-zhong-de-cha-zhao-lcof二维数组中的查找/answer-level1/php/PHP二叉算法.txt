### 解题思路
按照二叉顺序查找

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $matrix
     * @param Integer $target
     * @return Boolean
     */
    function findNumberIn2DArray($matrix, $target) {
        
        foreach ($matrix as $value) 
        {
            foreach ($value as $v)
            {
                if($v > $target)
                {
                    break;
                }

                if($v == $target)
                {
                    return  true;
                }

            }

            if(isset($value[0]) && $value[0] > $target)
            {
                return  false;
            }

        }

        return false;
    }
}
```