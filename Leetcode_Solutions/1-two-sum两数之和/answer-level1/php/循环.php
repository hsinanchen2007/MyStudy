### 解题思路
此处撰写解题思路
利用冒泡循环  第一个数依次 追加后面的数
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $data = array();
       for ($i=0; $i < count($nums); $i++) { 
            for ($j=$i+1; $j < count($nums); $j++) { 
               if ($nums[$i] + $nums[$j] == $target) {
                   $data = array($i,$j);
                   return $data;
               }
            }
        }
    }
}
```