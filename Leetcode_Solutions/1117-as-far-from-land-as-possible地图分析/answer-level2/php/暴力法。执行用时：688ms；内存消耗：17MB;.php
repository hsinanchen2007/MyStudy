### 代码

```php
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function maxDistance($grid)
    {
        $len = count($grid);
        $min = -1;
        for($x=0;$x<$len;$x++)
        {
            for($y=0;$y<$len;$y++)
            {
                $_min = $this->_maxDistance($grid,$len,$x,$y);
                if($_min>$min){
                    $min = $_min;
                }
            }
        }
        return $min;
    }

    //某个点的最大距离
    function _maxDistance(&$grid,$len,$x,$y)
    {
        $min = -1;
        if($grid[$x][$y]==1) return $min;

        for($w=1;$w<=(2*$len-2);$w++)
        {
            $hasLand = $this->hasLand($grid,$len,$x,$y,$w);
            if($hasLand)
            {
                return $w;
            }
        }
        return $min;
    }

    //某个点在某狗距离内是否有陆地
    function hasLand(&$grid,$len,$x,$y,$w)
    {
        for($s=0;$s<=$w;$s++)
        {
            $_x = $x+$s;
            $_y = $y+($w-$s);
            if(isset($grid[$_x][$_y]) && $grid[$_x][$_y]==1)
            {
                return true;
            }
            $_x1 = $_x;
            $_y1 = 2*$y-$_y;
            if(isset($grid[$_x1][$_y1]) && $grid[$_x1][$_y1]==1)
            {
                return true;
            }
            $_x1 = 2*$x-$_x;
            $_y1 = $_y;
            if(isset($grid[$_x1][$_y1]) && $grid[$_x1][$_y1]==1)
            {
                return true;
            }
            $_x1 = 2*$x-$_x;
            $_y1 = 2*$y-$_y;
            if(isset($grid[$_x1][$_y1]) && $grid[$_x1][$_y1]==1)
            {
                return true;
            }
        }
        return false;
    }
}
```