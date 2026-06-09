### 解题思路
两个键值对数组，$nums,$map;$map就是$nums的键值对颠倒；一次for循环中每循环一次$nums就给$map添加一个元素，用array_key_exists去判断目标值减当前值在$map的key中是否存在，存在则return，不必向下循环全部

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $map=[];
        for($i=0;$i<count($nums);$i++){
            $complement=$target-$nums[$i];
            if(array_key_exists($complement,$map)){
                return [$map[$complement],$i];
            }
            $map[$nums[$i]]=$i;
        }
    }
}
```