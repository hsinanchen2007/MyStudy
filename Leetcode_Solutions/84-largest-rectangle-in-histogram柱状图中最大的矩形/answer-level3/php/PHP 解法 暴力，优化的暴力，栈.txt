```
    //暴力
    function largestRectangleArea($heights) {
        $maxarea = 0;
        $len = count($heights);
        for($i = 0; $i < $len; $i++){

            for($j = $i; $j < $len; $j++){

                //定义一个最大的值，以在下面比较的时候找到一个最小值
                $minheight = PHP_INT_MAX;
                //因为两点之间 会出现比两端还小的高度，所以一 i到j这个间距之间 最小的那个高度为准，
                for($k = $i; $k <= $j; $k++){
                    $minheight = min($minheight, $heights[$k]);
                }
                //然后高是最小的那个高度 宽是i和j之间的距离
                $maxarea = max($maxarea, $minheight * ($j - $i + 1));
            }
        }

        return $maxarea;
    }

    //优化的暴力
    function largestRectangleArea($heights) {
        $maxarea = 0;
        $len = count($heights);

        for($i = 0; $i < $len; $i++){
            $minheight = PHP_INT_MAX;
            //$j在往前走，但是最小高度是从$i开始走的，所以$j到$i之间的最小高度的柱子可以被记录下来
            for($j = $i; $j<$len; $j++){
                $minheight = min($minheight, $heights[$j]);
                $maxarea = max($maxarea, $minheight * ($j - $i + 1));
            }
        }

        return $maxarea;
    }

    //栈方法
    function largestRectangleArea($heights) {
        $stack = new SplStack();
        $stack->push(-1);
        $maxarea = 0;
        $len = count($heights);

        for($i = 0; $i < $len; $i++){

            //然后判断 栈的下一个是否为-1 且heights中的当前是否比下一个大
            while($stack->top() != -1 && $heights[$stack->top()] >= $heights[$i]){
                $maxarea = max($maxarea, $heights[$stack->pop()] * ($i - $stack->top() - 1));
            }

            $stack->push($i);
        }

        while($stack->top() != -1){
            $maxarea = max($maxarea, $heights[$stack->pop()] * ($len - $stack->top() - 1));
        }

        return $maxarea;
    }
```
