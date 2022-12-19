### 解题思路
我是菜鸟，做题基本凭感觉，还做不到跟各种算法联系。

我是通过观察示例图的柱子，加上想象得到的思路。示例中的第一根柱子是索引为1的位置，高度为1，它与索引为3的位置的柱子形成一块接水的区域。为什么会有这么一块区域呢，因为这两根柱子之间有一个高度为0的地方，比他俩都低，而这两根柱子之间形成的区域，高度由低的1决定，宽度则是两根柱子之间的距离。而索引为3的柱子往后也是遇到比它高的柱子后才形成了一块新的接水区域，这块区域面积是低的柱子（2）乘以宽度（3）再减去该区域内的两根柱子的大小。由此可知，每个接水区域的形成，都是一根柱子往后寻找到比它高的柱子而形成的接水区域。
特殊的，当两根柱子挨着时是不能形成接水区域的。
如果中间有根很高的柱子，后面没有比它高的柱子该怎么办？此时可以从右向左计算。

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if (height == null || height.length < 3) return 0;
        int area = 0;
        //左边界
        int i = 0;
        //右边界
        int j = 1;
        while(true){
            if (height[i] <= height[j]){
                //左边界遇到比它高的柱子，两个柱子之间便可以接雨水
                area = oneArea(area, i, j, height);
                //这两个柱子中间的区域计算完毕，左右边界同时向右移动，准备计算新的区域
                i = j;
                //如果右边界移到最后，则跳出循环
                if (++j == height.length) break;
            }else if (j+1 == height.length){
                //如果最后一格没有参与到面积计算中便已经移动到最后一格了
                //如果左边界已经到了倒数第二格，说明此时最后一格要比倒数第二格低，没办法接雨水，跳出循环
                if (i+1 == j) break;
                //中间可能会有个很高的柱子，导致后续格子没有比它高的，此时从右到左计算
                //把这根最高柱子的索引记录下
                int max = i;
                i = j - 1;
                while(i >= max){
                    if (height[i] > height[j]){
                        area = oneArea(area, i, j, height);
                        j = i;
                        if (--i == max) break;
                    }else{
                        i--;
                    }
                }
                break;
            }else{
                //正常情况下右边界一直向右移动
                j++;
            }
        }
        return area;
    }
    //计算一块区域
    private int oneArea(int area, int i, int j, int[] height){
        //两个挨着的柱子是接不到水的
        if (i+1 == j) return area;
        //宽
        int w = j - i - 1;
        //高。短的柱子
        int h = height[i] < height[j] ? height[i] : height[j];
        //先算总面积
        area += h * w;
        //再减去内部柱子的面积
        for (int k = i+1; k < j; k++){
            area -= height[k];
        }
        return area;
    }
}
```