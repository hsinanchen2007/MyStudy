### 解题思路
简单哈希存储

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums1
     * @param Integer[] $nums2
     * @return Integer[]
     */
    

    function intersect($nums1, $nums2) {
        $hm = [];//哈希表来存储第一个数组中数字及其频率

        for($i=0;$i<count($nums1);$i++){
            $hm[$nums1[$i]]++;//记录数字和频率
        }

        $res = [];

        for($j=0;$j<count($nums2);$j++){
            if($hm[$nums2[$j]] > 0){//在第二个表中找到第一个组中的数字，且剩余频率为正
                $res[] = $nums2[$j];//把找到的数字存入结果，并频率减一
                $hm[$nums2[$j]]--;  
            }
        }

        // print_r($res);
        return $res;
    }
}
```