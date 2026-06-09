### 解题思路
双指针循环
遍历数组遇到$i = $val时从数组后面往前遍历当数组后面的数不等于$val时复制到$i直到数组遍历完成
![微信图片_20200222144728.png](https://pic.leetcode-cn.com/eb5c26e71b97e517d1c964acd623e236fecf6f733948aa4199593774cdfcb888-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200222144728.png)


### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $val
     * @return Integer
     */
    function removeElement(&$nums, $val) {
        $end = count($nums);
        for($i=0;$i<count($nums);$i++){
            if($nums[$i] == $val){
                for($j=$end-1;$j>=0;$j--){
                    if($nums[$j] != $val){
                        $nums[$i] = $nums[$j];
                        $end = $j;
                        break;
                    }else{
                        $end -= 1;
                    }
                    if($i >= $end){
                        return $end;
                    }
                }
            }
            if($i >= $end){
                return $end;
            }
        }
    }
}
```