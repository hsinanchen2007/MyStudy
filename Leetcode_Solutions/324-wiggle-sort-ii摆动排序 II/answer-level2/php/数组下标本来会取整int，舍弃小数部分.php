### 解题思路
![image.png](https://pic.leetcode-cn.com/2ce211f43ceba64181dc5c7efec164ed585204e46a4bb6d0bce1fbb190aec7ea-image.png)

先排序，然后$arr = [$nums[$n/2],$nums[$n],$nums[$n/2 - 1],$nums[$n -1]]
偶数部为前半部分倒叙，奇数部为后半部倒叙

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function wiggleSort(&$nums) {
        sort($nums);
        $arr = [];
        for($i = 0, $j = (count($nums) -1)/2, $m =count($nums) - 1; $i < count($nums); $i +=2) {
            $arr[$i] = $nums[$j--];
            if($i < (count($nums) - 1)){
                $arr[$i+1] = $nums[$m--];
            }
                              
        }
        $nums = $arr;
    }
}
```