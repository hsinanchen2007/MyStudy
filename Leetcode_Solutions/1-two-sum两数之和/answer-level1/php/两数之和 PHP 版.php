## 暴力解法

暴力解法：双重循环。

时间复杂度：$O(N^2)$。

```PHP []
function twoSum($nums, $target) {
    $count = count($nums);
    for($i=0; $i< $count; $i++){
        for($j=$i+1; $j< $count; $j++){
            if ($nums[$i] + $nums[$j] == $target) {
                break 2;
            }
         }
    }

    return [$i, $j];   
}
```

## 使用 HashMap 

HashMap 法：直接去查找对应的值的key。

时间复杂度：$O(N)$。

PHP 里使用 array 模拟 HashMap。

` array_keys` 如果加了 第二个参数，表示仅返回含有该值的 key。

```PHP []

function twoSum($nums, $target) {
    $count = count($nums);
    for($i=0; $i< $count; $i++){
        $ele = $target - $nums[$i];
        $keys = array_keys($nums, $ele);
        foreach($keys as $key) {
            if ( $key &&  $key != $i) {
                return [$i, $key]; 
            }
        }
        
    }
}
```
时间复杂度：$O(n)$。

**改进：**
借助一个hashtable，每次循环的时候，发现当前值在table中找不到配对，先记录下来，key是值，值是与之配对的值的索引；如果当前值在table中找到配对，说明配对成功。
``` php
function twoSum($nums, $target) {
    $table = []; //值 => 可以配对的索引
    $len = count($nums);
    for($i = 0; $i < $len; $i++ ) {
        $value = $nums[$i];
        if (isset($table[$value]))  {
            return [$table[$value], $i]; //配对成功
        } else {
            $table[$target - $nums[$i]] = $i; //记录该值配对对应的索引
        }
    }
}
```
时间：O(N)，空间O(N)。

## 二分法

用一个排序都能把复杂度降到 $O(NlogN)$，通过排序，然后用两个指针从前后扫描逼近真值。

注意这个思想，可以让 $O(N^2)$ 的复杂度降为 $O(N)$，充分利用排序，因为一定会有一个值满足，然后通过值去原数组里找对应的下标。

```PHP []
function twoSum($nums, $target) {
    $nums_c = $nums; //保留原数组，sort函数会修改原数组
    sort($nums);
    $start = 0;
    $end = $count =  count($nums);

    //两边逼近
    while($start < $end){
        while($nums[$start] + $nums[--$end] > $target);
        if ($nums[$start] + $nums[$end] == $target) {
            break;
        }

        while($nums[++$start] + $nums[$end] < $target);
        if ($nums[$start] + $nums[$end] == $target) {
            break;
        }
    }

    //从原始数组里查找对应值的key
    $result = [];
    for($i=0; $i < $count; $i++) {
        if ($nums_c[$i] == $nums[$start] || $nums_c[$i] == $nums[$end]) {
            $result[] = $i;
        }
    }
    
    return $result; 
}
```

时间复杂度：$O(n)$。