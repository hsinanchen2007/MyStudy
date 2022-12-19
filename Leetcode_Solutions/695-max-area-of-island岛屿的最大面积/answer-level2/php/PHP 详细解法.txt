`思路参考官方深度优先`

### 官方示例中最大岛的面积为6

![image.png](https://pic.leetcode-cn.com/de0b11b03062d4c6977cc8f036e9d9af68dd50c1ab86216c7fb8e5f5de26f121-image.png)


### 首先了解两个事情：

1. 一个土地相邻的面积，一定是`上下左右`四个方向为1的进行计数，所有相邻土地的计数一起组成岛的面积。
2. 如果一个土地于一个岛联通，那么肯定不与别的岛联通。

### 计算岛的面积

如果我们抓住一个土地`1`通过遍历就可以找到和这个土地关联的其他所有土地，

遍历的`土地数量的和`就是岛屿的`面积`。

接下来应该是找到每个土地，然后遍历他所在岛的面积，

刚才有提过每个土地只会属于一个岛屿，

所以遍历过每一个土地`1`之后，我们将其置为`0`，这样可以避免已经被计算过得岛屿的土地重新成为遍历的起点。提高执行效率。

`遍历算法，通过一个土地起点算出整个岛屿的面积`
```
//深度优先,$gird是引用传过来的，否则无法修改原数组元素值为0
function dfs(&$grid,$i,$j) {
    if(isset($grid[$i][$j])&&$grid[$i][$j]==1){
        //自己是1，计数1，并把自己置0
        $grid[$i][$j]=0;
        //搜索自己的四个方向
        $deep=1+
        $this->dfs($grid,$i+1,$j)+
        $this->dfs($grid,$i-1,$j)+
        $this->dfs($grid,$i,$j+1)+
        $this->dfs($grid,$i,$j-1);

        return $deep;
    } else {
        //不满足条件，搜索结束
        return 0;
    }
}
```

### 遍历土地

遍历每一块土地，然后算出土地所在岛屿的面积，

其中`最大岛屿面积`就是答案。

`遍历每一块土地`

```
function maxAreaOfIsland($grid) {
    $deep_max = 0;
    foreach($grid as $i=>$value_i) {
        foreach($value_i as $j=>$value_j){
            if($grid[$i][$j]==1) {
                //当前土地所在岛屿的面积
                $deep = $this->dfs($grid,$i,$j);
                //与最大的面积比较，取最大值
                $deep_max = max($deep_max,$deep);
            }
        }
    }

    return $deep_max;
    
}
```


完整代码

```
class Solution {

    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function maxAreaOfIsland($grid) {
        $deep_max = 0;
        foreach($grid as $i=>$value_i) {
            foreach($value_i as $j=>$value_j){
                if($grid[$i][$j]==1) {
                    //当前土地所在岛屿的面积
                    $deep = $this->dfs($grid,$i,$j);
                    //与最大的面积比较，取最大值
                    $deep_max = max($deep_max,$deep);
                }
            }
        }

        return $deep_max;
        
    }
    //深度优先,$gird是指针串过来的，否则无法修改原数组元素值为0
    function dfs(&$grid,$i,$j) {
        if(isset($grid[$i][$j])&&$grid[$i][$j]==1){
            //自己是1，计数1，并把自己置0
            $grid[$i][$j]=0;
            //搜索自己的四个方向
            $deep=1+
            $this->dfs($grid,$i+1,$j)+
            $this->dfs($grid,$i-1,$j)+
            $this->dfs($grid,$i,$j+1)+
            $this->dfs($grid,$i,$j-1);

            return $deep;
        } else {
            //不满足条件，搜索结束
            return 0;
        }
    }
}
```




