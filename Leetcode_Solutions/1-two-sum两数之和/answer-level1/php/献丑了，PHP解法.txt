执行用时 12 ms
内存消耗 20.4 MB
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $maps = [];
        foreach($nums as $i => $num){
            $maps[$num][] = $i;
        }

        foreach ($nums as $i => $num) {
            if (isset($maps[$target - $num])) {
                if (count($maps[$target - $num]) == 1) {
                    if ($i !== $maps[$target - $num][0]) {
                        return [$i, $maps[$target - $num][0]];
                    }        			
                }else{
                    return [$i, $maps[$target - $num][1]];
                }
            }
        }
        
        return [];
    }
}
```

看其他大神的解答才想起来有个array_flip函数可用，array_flip可以覆盖前面的键，所以可以更精简

执行用时 12 ms
内存消耗 16.8 MB
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $maps = array_flip($nums);

        foreach ($nums as $i => $num) {
            if (isset($maps[$target - $num]) && $maps[$target - $num] !== $i) {
                return [$i, $maps[$target - $num]];
            }
        }
        
        return [];
    }
}
```

