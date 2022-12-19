### 解题思路
统计每个整数的数量，判断这些数量是否存在公约数


### 代码

```php
class Solution
{
    /**
    * @param Integer[] $deck
    * @return Boolean
    */
    function hasGroupsSizeX($deck)
    {
        $group = array();
        foreach ($deck as $num)
        {
            if(!isset($group[$num]))
            {
                $group[$num]=0;
            }
            $group[$num]++;
        }

        $min = min($group);

        for($i=2;$i<=$min;$i++)
        {
            $result = true;
            foreach ($group as $num)
            {
                if(!is_int($num/$i))
                {
                    $result = false;
                    break;
                }
            }

            if($result)
            {
                return true;
            }
        }

        return false;
    }
}
```