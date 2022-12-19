### 解题思路
PHP 数组模拟哈希映射

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $count = count($nums);
        $more = [];
        foreach($nums as $key=>$value){
            if(array_key_exists($value,$more)){
                $more[$value] ++;
            }else{
                $more[$value] = 1;
            }
        }
        if(max($more) > $count/2){
            return array_search(max($more),$more);
        }
    }
}
```