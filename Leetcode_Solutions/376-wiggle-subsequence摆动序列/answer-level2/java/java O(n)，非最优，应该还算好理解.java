由于这个题目要求是增一减一或者说是减一增一的变化过程，我就想使用一个布尔类型来指示一下当下是在上升还是在下降。
这里我设定了一个 up 参数来指示
如果是在增长的过程中，出现了后者高于前者，那么就更新这个最大值，但是计数不增加
                    出现了后者低于前者，那么就是一个震荡，计数加一
                                                    同时  布尔值反转，最小值更新
如果是在减少的过程中，出现了后者低于前者，那么就更新这个最小值，但是计数不增加
                    出现了后者高于前者，那么就是一个震荡，计数加一
                                                    同时，布尔值反转，最大值更新

整体考虑的话，由于这个最大值和最小值都是我们遍历循环当前值的前一个数字（有点长，也捋一下哈）
那么我们可以使用一个变量 tem  来实现最大值与最小值的功能
（也就是说，增长的最高点，就是最大值，降低的最低点，就是最小值，比较结合增长变化过程，容易合二为一）

但是此时我们有一个问题，就是前两个数字的关系我们并不知道，也就是说这个布尔值的初始化怎么赋值的问题。
开始我的思路是直接比较，然后根据比较结果来给  up  赋初值，可想而知，由于本身也可能出现相等的情况，所以并不合适。

考虑后我使用了这样的方法：
```
public int wiggleMaxLength(int[] nums) {
        if (nums.length<2) return nums.length;
        boolean up = true;
        int counter = 1;
        if (nums[0] == nums[1]) counter = 1;
        int tem = nums[0];
        for (int i = 1;i<nums.length;i++){
            if (nums[i] == tem)
                continue;
            if (counter == 1)
                up = nums[i]>tem?false:true;
            if (up){
                if (nums[i] < tem) {
                    counter++;
                    up = !up;
                }
                tem = nums[i];
            }else {
                if (nums[i] > tem) {
                    counter++;
                    up = !up;
                }
                tem = nums[i];
            }
        }
        return counter;
    }
```

这样就可以直接跳过开头重复的位置，当出现不相等的时候，就可以对up进行赋初值，以便完成之后的判断和计数了

提交结果是这样的：

![image.png](https://pic.leetcode-cn.com/ced11afe7354a8e89a633a0ff744c834efe39017024756486189b6ce9f62bedd-image.png)
但我认为这个实现思路并不会是最优的。

