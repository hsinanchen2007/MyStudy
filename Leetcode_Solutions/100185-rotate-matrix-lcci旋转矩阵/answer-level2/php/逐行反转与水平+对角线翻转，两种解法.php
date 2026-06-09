这道题是 N×N，不是N×M，也不是别的，并且用的是地址传入，如果按 N×M 的矩形计算，5×3->3×5,改变了数组的大小那么像java必报错，不必平白分别计算长宽

- 可以理解为每行反转，也可以理解为横纵转换
```
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function rotate(&$matrix) 
    {
        $temp=$matrix;
        $count=count($matrix);

        for($i=0;$i<$count;$i++)
        {
            for($j=0;$j<$count;$j++)
            {
                $matrix[$i][$j]=$temp[$count-1-$j][$i];
            }
        }
    }
}
```

- 第二种方式就是先将数组水平镜像翻转，再对角线翻转
比起先对角线翻转，在竖直镜像翻转有一个好处，就是减少了一个嵌套循环
```
class Solution {

    /**
     * @param Integer[][] $matrix
     * @return NULL
     */
    function rotate(&$matrix) {
        $n=count($matrix);
        
        //水平翻转,向下取整floor
        for($i=0;$i<floor($n/2);$i++)
        {
            $temp=$matrix[$i];
            $matrix[$i]=$matrix[$n-$i-1];
            $matrix[$n-$i-1]=$temp;
        }

        //对角线翻转
        for($i=1;$i<$n;$i++)
        {
            for($j=0;$j<=$i;$j++)
            {
                $temp=$matrix[$i][$j];
                $matrix[$i][$j] = $matrix[$j][$i];
                $matrix[$j][$i] = $temp;
            }
        }
    }
}
```
