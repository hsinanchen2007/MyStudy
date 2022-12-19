### 解题思路

- 首先,我是想搜索 1的四周如果有2那么就像1=>修改成2.
- 同时1的4周都是0,那么不能全部传染,但是这就有无法判断的漏洞,当被0隔断,但是4周都是1或者0时无法判断
- 只能回归搜索2的4周
- 同时看别人的解法,应该吧1提取出来,每次循环后去掉提取的1,查看个数是否大于0,并且本次是否有1变成2
- 如果条件不满足说明无法继续感染,导致失败

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
function orangesRotting($grid)
{
    $min=0;
    $col = count($grid[0]);
    $line = count($grid);
    while(1){
        $tmp=[];
        foreach ($grid as $k){
            $tmp=array_merge($tmp,$k);
        }
        //如果灭有2但是有1,返回-1
        if(!in_array(2,$tmp) && in_array(1,$tmp)){
            return -1;
        }
        //检查是否还是格子为1.
        elseif(in_array(1,$tmp)){
            $min++;
            //复制一份
            $old =$grid;
            $has = 0;
            for ($i = 0; $i < $line; $i++) {
                for ($j = 0; $j < $col; $j++) {
                    //4个方向都是0那个这个不能全部感染 -1
                    //改成检测本身2
                    //4个方向都是非1那个这个不能全部感染 -1
                    if ($old[$i][$j] == 2) {
                        if ($i - 1 >=0) {
                            $up = $old[$i - 1][$j];
                            if ($up == 1) {
                                $grid[$i-1][$j] = 2;
                                $has=1;
                            }
                        }
                        if ($i + 1 < $line) {
                            $down = $old[$i + 1][$j];
                            if ($down == 1) {
                                $grid[$i+1][$j] = 2;
                                $has=1;
                            }
                        }
                        if ($j - 1 >= 0) {
                            $left=$old[$i][$j - 1];
                            if ($left == 1) {
                                $grid[$i][$j-1] = 2;
                                $has=1;
                            }
                        }
                        if ($j + 1 < $col) {
                            $right= $old[$i][$j + 1];
                            if ( $right== 1) {
                                $grid[$i][$j+1] = 2;
                                $j++;
                                $has=1;
                            }
                        }
                    }
                }
            }
            if($has==0){
                return -1;
            }
        }
        else{
            return $min;
        }
    }
}


}
```