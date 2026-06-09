![2019-09-28_07-30.png](https://pic.leetcode-cn.com/9381f0cefe0aa60b6cd5452c5ea3b8e23b54b9432555bec1008bcde0fa324d0b-2019-09-28_07-30.png)

### 几何意义
刚拿到这道题的时候是从斜率的角度考虑，实现起来非常复杂。苦思冥想出一种类似归纳法的巧妙解法，时间复杂度为 O(n)，空间复杂度为 O(1)，并且只需一次遍历。

首先我们先考虑最简单的情况。如果忽略数组的中间值，只考虑左右边界，那么水平面高度应该等于左右边界中的较小值，$level = min(height[left], height[right])$。如下图所示。

![Diagram1.png](https://pic.leetcode-cn.com/4c63ae778ea16a0b4c661119e4dcdafe562bce56d69e4a8832d4e236cbf5eaf0-Diagram1.png)

接下来考虑两边界内部的情况，如果内部泥土的高度都比水平面低，那么不会对水平面有任何影响。

![Diagram2.png](https://pic.leetcode-cn.com/648d258b56b6c568b54ae3bee9b51930cc1422adb61f0b8aa9127c6593af7c0e-Diagram2.png)

**定义任何水平面高度相等的连续区域都是一个坑。** 如果内部出现比水平面高的泥土，则水平面一定会被改变，并且会形成左右两个坑。

![Diagram3.png](https://pic.leetcode-cn.com/2d596e9513e0495c27c58db9ea5bb7dbd88485a76d988e21c808a6d08653d3d0-Diagram3.png)

### 扫描
首先假设左右边界之间是一个坑，并在边界处放置指针 cl/cr。移动较矮边界处的指针（此处是 cl），直到找到超过水平面的泥土，则 left 与 cl 之间就形成了一个坑。水量为 $(cl - left)\times min(height[cl], height[left]) - \sum\limits_{i=left+1}^{cl-1}height[i]$。

![Diagram5.png](https://pic.leetcode-cn.com/0419b79bfbc8327af975a848351059e212c77854edd881d696dab6fcb5eddf9b-Diagram5.png)

更新 $left = cl$，并对新的左右边界內部的区域重复以上步骤，直到 $cl > right$ 或 $cr < left$。

![Diagram6.png](https://pic.leetcode-cn.com/534b110ed6b486c1721357ca755b66d9b49c1105a36380038471e6e201c6fb5e-Diagram6.png)

### 其它细节
1. 为什么移动较短边的指针？
    较短边决定了水面高度，不论内部泥土高度如何，与较短边相连的水面高度是确定值
2. 內部的高度可以在扫描过程中直接从总水量中减去。

```c
int trap(int* height, int heightSize){
    int * left = &height[0];               // 待求解区域左边界
    int * right = &height[heightSize - 1]; // 待求解区域右边界
    int * cl = left + 1;          // 左指针
    int * cr = right - 1;         // 右指针
    int ret = 0;                // 返回值

    while (cl <= right && cr >= left) {
        // 如果右边界较矮则移动右指针
        if (*left > *right) {
            // 当右指针移动到比右边界高的位置时
            // 认为右指针与右边界之间形成了一个坑
            if (*cr >= *right) {
                // 水面高度等于右指针和右边界中的较小值
                // 水面宽度等于 right - cr - 1
                ret += *right * (right - cr - 1);
                // 更新右边界
                right = cr;
            }
            else
                // 减去坑底的高度
                ret -= *cr;
            // 移动右指针
            --cr;
        }
        // 如果左边界较矮则移动左指针
        else {
            if (*cl >= *left) {
                ret += *left * (cl - left - 1);
                left = cl;
            }
            else
                ret -= *cl;
            ++cl;
        }
    }
    return ret;
}
```
