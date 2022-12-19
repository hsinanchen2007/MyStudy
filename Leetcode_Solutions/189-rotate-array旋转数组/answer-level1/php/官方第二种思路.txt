### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return NULL
     */
    function rotate(&$nums, $k) {
        $tmpArr = [];
        $len = count($nums);
        foreach($nums as $m=>$v){
            $key = ($m+$k)%$len;
            $tmpArr[$key] = $v;
        }
        ksort($tmpArr);
        $nums = $tmpArr;

        return $nums;
    }
}
```