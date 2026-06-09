### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s1
     * @param String $s2
     * @return Boolean
     */
    function isFlipedString($s1, $s2) {
       $s1_count = strlen($s2);

    if($s1==$s2)
    {
        return true;
    }
    for($i=0;$i<$s1_count;$i++)
    {
        $s1.=$s1[0];
        $s1= substr_replace($s1,"",0,1);
     
        if($s1==$s2)
        {
            return true;
        }

    }
    return false;
    }
}
```