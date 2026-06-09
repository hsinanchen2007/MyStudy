### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer[]
     */
    function getLeastNumbers($arr, $k) {
        // 快速排序
        $arr = self::quickSort($arr);

        return array_slice($arr, 0, $k);
    }

    function quickSort($arr){
        // 选定基准数
        $count = count($arr);
        if($count < 2){
            return $arr;
        }
        $mid = $arr[0];
        // 找出比基准值大的，和比基准值小的
        $left = [];
        $right = [];
        foreach($arr as $k => $value){
            if($k == 0){
                continue;
            }
            if($value > $mid){
                $right[] = $value;
            } else {
                $left[] = $value;
            }
        }

        return array_merge(self::quickSort($left), [$mid], self::quickSort($right));

    }
}
```