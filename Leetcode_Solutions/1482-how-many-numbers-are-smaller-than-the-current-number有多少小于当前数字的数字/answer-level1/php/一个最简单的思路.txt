### 解题思路
代码效率不好，给大家列举一个反例，想法就是 双层循环挨个比对，思路简单但是效率低下

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
   function smallerNumbersThanCurrent($nums) {
        $arr = [];
        foreach ($nums as $ik => $iv)
        {
            $count = 0;
            foreach ($nums as $jk => $jv)
            {
                if($iv == $jv) {
                    continue;
                }

                if ($iv > $jv) {
                    $count++;
                }
        }
        $arr[] = $count;
    }
        return $arr;
    }
}
```