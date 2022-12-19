### 解题思路
此处撰写解题思路
刚开始使用暴力法，双层for循环，结果正确，但是超时了
优化后的用的递减栈思想来做
### 代码

```php
class Solution {

    /**
     * @param Integer[] $T
     * @return Integer[]
     */
    function dailyTemperatures($T) {
        if(empty($T)) return false;
        $stack=[];//声明栈
        $count=count($T);
        $result=array_fill(0,count($T),0);
        for($i=0;$i<$count;$i++){
        while(count($stack) &&  $stack[count($stack) - 1][0]<$T[$i]){
            $result[$stack[count($stack) - 1][1]] = $i - $stack[count($stack) - 1][1];
            array_pop($stack);

        }
            $stack[]=[$T[$i],$i];
        }
        return $result;
    }
}
```