### 解题思路
![微信图片_20200131220433.png](https://pic.leetcode-cn.com/07b1a2a1c6cfbc3704226f60d09014f8a4cb9e7e70a8719e37d9b62571319a5c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200131220433.png)


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    #方法一
    function twoSum($nums, $target) {
        for($i=0;$i<count($nums);$i++){
            $temp = array_keys($nums,$target-$nums[$i]);
            if(!empty($temp) && $temp[0] != $i){
                if(!empty($temp[1])){
                    return $temp;
                }
                return [$temp[0],$i];
            }
        }
    }

    #方法二
    function twoSum($nums, $target) {
        $found = [];
        for($i=0;$i<count($nums);$i++){
            $diff = $target - $nums[$i];
            if(!isset($found[$diff])){
                $found[$nums[$i]] = $i;
                continue;
            }
            return [$found[$diff],$i];
        }
    }
}
```