### 解题思路
时间消耗0ms，打败100%。空间复杂度为O(1)(不过为啥空间消耗才打败6.9%......)

思路如下：
1. 首先要明确，路径要想不相交，那任意时刻只有两种变化趋势（见下图）：a. 路径经过的范围越来越大；b.路径路过的范围越来越小。可以是先经过a类型的变化再转为b类型的变化，但不可能经过b类型的变化再转化为a类型的变化！据此，我们可以将遍历分成两个部分。首先遍历路径的范围越来越大的部分，然后遍历路径的范围越来越小的部分。
![tu1.PNG](https://pic.leetcode-cn.com/a846e12e001544bc6f1eaa7b5962eb7cec4b8a6665306f5dbac92a59202fe9a6-tu1.PNG)
2. 当路径只是a类型变化或者b类型变化时，是好处理的。a类型时，我们只要记录下横向、纵向的经过的最大长度，下次横向或纵向移动时，必须大于已记录的横向或纵向的最大长度，否则必然会有交线；b类型时，我们只要记录下横向、纵向的经过的最小长度，下次横向或纵向移动时，必须小于已记录的横向或纵向的最小长度，否则必然会有交线。
3. 当a类型转变为b类型时，有两种情况。情况一：图中a方式需要更新纵向的最小长度，然后转变为类型b的变化趋势，a方式纵向最小长度需要更新为`yl - py`，如下图：
![tu2.png](https://pic.leetcode-cn.com/af8e9494e54604dec455379e1e8b5185a4c49d84ea372f9fe0585844c21dd182-tu2.png)
同理，情况二：图中a方式需要更新横向的最小长度，然后转变为类型b的变化趋势，a方式横向最小长度需要更新为`xl - px`。
![tu3.PNG](https://pic.leetcode-cn.com/a40ae37549c372c2298cd5c2f981a21a9f603635c70455bb0413e390db3d4eec-tu3.PNG)
4. 从图中可以看出，其实px，py的值其实就是xl、yl最新的旧值，每次更新xl、yl时，另外用px、py保存其旧值就可以了。


### 代码

```java
class Solution {
    public boolean isSelfCrossing(int[] x) {
        if(x.length <= 3)
            return false;
        int i, xl = x[1], yl = x[0], px = 0, py = 0;
        //检测a类型路径的变化趋势
        for(i = 2; i < x.length; i++){
            if((i & 0x1) == 1){
                if(x[i] <= xl){
                    //a ---> b
                    if(xl - px <= x[i])
                        yl -= py;
                    xl = x[i];
                    break;
                }
                //用px保存xl的旧值
                px = xl;
                xl = x[i];
            }else {
                if(x[i] <= yl){
                    //a ---> b
                    if(yl - py <= x[i])
                        xl -= px;
                    yl = x[i];
                    break;
                }
                //用py保存yl的旧值
                py = yl;
                yl = x[i];
            }
        }
        //检测b类型路径的变化趋势
        for(i++; i < x.length; i++){
            if((i & 0x1) == 1 && x[i] < xl){
                xl = x[i];
            }else if(x[i] < yl){
                yl = x[i];
            }else{
                return true;
            }
        }
        return false;
    }
}
```