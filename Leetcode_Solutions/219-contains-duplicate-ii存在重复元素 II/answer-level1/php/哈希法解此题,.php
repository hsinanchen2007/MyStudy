### 解题思路
执行用时 :20 ms, 在所有 PHP 提交中击败了100.00% 的用户
内存消耗 :20.7 MB, 在所有 PHP 提交中击败了63.64%的用户
$k是两个相同k之间的(至多)最大距离，所以此题只考虑  相邻两个相同值之间的距离 （第2个相同值和第三个相同值距离大于$k,则  第2个和第四个是不用考虑的）$map[$vv] = $kk的作用是生成和更新的作用

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Boolean
     */
    function containsNearbyDuplicate($nums, $k) {
        $map = [];
        foreach($nums as $kk=>$vv){
            if(isset($map[$vv]) && abs($kk-$map[$vv]) <= $k){
                return true;
            }
            $map[$vv] = $kk;
        }
        return false;
    }
}
```