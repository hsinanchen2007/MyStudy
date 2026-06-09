### 解题思路
循环字符串进行字符串拼接

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function replaceSpace($s) {
        
        $len = strlen($s);

        $str = '';

        for ($i = 0 ; $i < $len; $i++ )
        {

            if($s[$i] == ' ')
            
                $str .= '%20';
            
            else
            
                $str .= $s[$i];
            
        }

        return  $str;
    }
}
```