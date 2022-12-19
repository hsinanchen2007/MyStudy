### 解题思路
暴力解题

### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function trap($height) {
        $tmp = $height;
        $rain = $before = 0;
        $after = max($tmp);

        foreach ($height as $v){
            if ($v >= $before)
                $before = $v;
            else
                $rain += min($after,$before) - $v;
            
            $tmp[array_keys($tmp,$v)[0]] = 0;
            if ($v == $after){$after = max($tmp);}
        }

        return $rain;
    }
}
```