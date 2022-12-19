就是把官方代码用PHP敲了一遍。顺带理解一下，还是学java吧 php没人用了

```
class Solution {
    //第一种暴力：翻转K次
    // function rotate(&$nums, $k) {
    //     $len = count($nums);
    //     for($i = 0; $i < $k; $i++){

    //         for($j = 0; $j < $len; $j++){
    //             $pre = $nums[$len-1];
    //             $nums[$len-1] = $nums[$j];
    //             $nums[$j] = $pre;
    //         }
    //     }

    //     return $nums;
    // }

    //第二种：新数组
    // function rotate(&$nums, $k) {

    //     $arr = [];

    //     $len = count($nums);
        
    //     for($i = 0; $i < $len; $i++){
    //         $arr[($i + $k) % $len] = $nums[$i];
    //     }

    //     ksort($arr);

    //     $nums = $arr;

    //     return $nums;
    // }

    //第三种：使用环状替换
    function rotate(&$nums, $k){
        
        $length = count($nums);
        $k = $k % $length;
        $count = 0;
        for($start = 0; $count < $length; $start ++){
            $current = $start;
            $prev = $nums[$start];//1

            do{
                //获取当前坐标的下一个步伐坐标
                $next = ($current + $k) % $length;//3  6  1  4  7  3由到1了
                //获取下一个正确坐标的数存起来
                $temp = $nums[$next];//4  7  2   5   8 
                //把当前坐标数字移动到下一个正确坐标
                $nums[$next] = $prev; //1移动到4  4移动到7   7移动到2  2到5  5到8
                //把下一个坐标的值给当前
                $prev = $temp;//4给prev  7给prev  2给 prev   5给prev   8给prev
                //把下一个坐标给当前坐标
                $current = $next; //当前位置 3 当前位置6  1  4  7  
                $count++;// 1 2 3  4  5

            }while($start != $current);// 0 不等于 3 为真 进入第二次
        }
    }
}
```
