**思路一：按行计算法** 计算每一行接的水，相加得到一共接的水。

用一个变量temp记录第i行的水，遍历每个"墙"的高度，遇到`第一个大于等于i`的"墙"启动temp准备记录；继续遍历遇到`小于i`的"墙"`temp++`，否则遇到`大于等于i`的"墙"`ans加上temp并归零temp`。

```java
public int trap(int[] height) {
    if (height==null||height.length<3)return 0;
    int ans=0,maxHeight=height[0];
    for (int h : height)if (h>maxHeight)maxHeight=h;
    for (int row = 1; row <= maxHeight; row++) {
        int temp=0;
        //是否开始统计temp
        boolean isStart=false;
        for (int i = 0; i < height.length; i++) {
            if (isStart&&height[i]<row)temp++;
            if (height[i]>=row){
                ans+=temp;
                temp=0;
                isStart=true;
            }
        }
    }
    return ans;
}
```

时间复杂度：O(maxHeight*n)	**此方法在leetcode上会超时！**

**思路二：按列计算法** 计算出每一列上有多少水，相加得到一共接的水。

想知道第i列上是否有水，我们需要找到第i列的左边和右边最高的"墙"，因为只有形成凹点才能存水；并且"木桶效应"告诉我们存了多少水，只需要考虑第i列左边和右边找到的最高的"墙"中最矮的一个。

第i列的高度`x`和我们找到的左边和右边最高的"墙"中最矮的一个"墙"的高度`y`会有三种关系：

1. `x<y`，第i列上存的水应该是y-x。
2. `x>y`，第i列上一定接不到水。
3. `x=y`，第i列上依然是不能接到水。

知道了这些，编码就很简单了，遍历每一列的同时找到当前列左边和右边最高的两面"墙"中最矮的一个和当前列进行比较，对上述三种情况进行处理即可。

```java
public int trap(int[] height) {
    if (height==null||height.length<3)return 0;
    int ans=0;
    for (int col = 0; col < height.length; col++) {
        //找到col左右最高的墙
        int leftMax=0;
        for (int i = col-1; i >=0; i--) leftMax=Math.max(leftMax,height[i]);
        int rightMax=0;
        for (int i = col+1; i < height.length; i++) rightMax=Math.max(rightMax,height[i]);
        //如果最高的墙中最矮的一个大于col的高度，计算当前列上接的水并加入结果
        if (Math.min(leftMax,rightMax)>height[col])ans+=Math.min(leftMax,rightMax)-height[col];
    }
    return ans;
}
```

时间复杂度：O(n^2)

**思路三：动态规划优化按列计算法** 思路二中每次寻找第i列的左右最高墙的时候都需要遍历一次整个数组。

思路三就是针对这点进行优化。空间换时间。

以题目中实例来演示：

![3U8exO.md.png](https://pic.leetcode-cn.com/324e07e65e2f0e5e95d6cda0b01e0d9f87b047248e6fcdd88aa304d08d9c249d.png)

每次寻找第i列左边做高的"墙"，只需要将"已经记录的i-1列左边最高的墙和i-1列进行比较，取大的即可"。避免了每次遍历整个数组。

寻找第i列右边做高的"墙"同理，只需要将"已经记录的i+1列右边最高的墙和i+1列进行比较，取大的即可"。

所以leftMax[i]的含义就是第i列左边最高的"墙"，rightMax[i]的含义就是第i列右边最高的"墙"(不含第i列本身)。

初始化：顺序遍历一次填写leftMax数组，逆序遍历一次填写rightMax数组。

有了leftMax和rightMax之后，然后计算每一列上接的水和思路二中方法一样。

```java
public int trap(int[] height) {
    if (height==null||height.length<3)return 0;
    //计算leftMax，rightMax
    int[] leftMax=new int[height.length],rightMax=new int[height.length];
    for (int i = 1; i < height.length; i++) leftMax[i]=Math.max(leftMax[i-1],height[i-1]);
    for (int i=height.length-2;i>=0;i--) rightMax[i]=Math.max(rightMax[i+1],height[i+1]);
    //计算每一列上的水
    int ans=0;
    for (int i = 1; i < height.length-1; i++) {
        int min=Math.min(leftMax[i],rightMax[i]);
        if (min>height[i]){
            ans+=min-height[i];
        }
    }
    return ans;
}
```

时间复杂度：O(n)	三次遍历

空间复杂度：O(n)

**思路四：双指针优化动态规划法** 双指针主要是对思路三中的空间复杂度进行优化。

上述方法中，两个数组中的每个元素在计算每一列上的水的时候只会被使用一次。所以完全可以用两个int类型的变量实现。

依然是用题目中的实例来演示：

![3UscqI.png](https://pic.leetcode-cn.com/ce869dffbb6aa96d75e9b3c0ec23d22a184662f1f064b45b449449b86013651c.png)

![question41 3.png](https://pic.leetcode-cn.com/b3ec6172c61496a462dbd3e7a69d9a267bd9a160fdd659102f6d68fb48692cbb-question41%203.png)


![3Us2Zt.md.png](https://pic.leetcode-cn.com/d097f3aa8584144c1738c91da90f384c1e04f5b651230a81b08bd71c0917502b.png)

就按照上述方式计算出每一列上的水并加入结果，直至left>right结束。

双指针法虽然是沿用了思路二思路三的方式去找左右最高"墙"，**但是为什么计算leftMax和rightMax的位置相差这么远依然可以有效判断呢？**

例如，对于left墙height[left]，如果leftMax比height[left]高。那么如果rightMax比leftMax高，那么就说明left右边一定存在比height[left]高的墙，那么left列上面一定可以接到水。

即使rightMax对于left右边来说不是最高的墙也无所谓，因为如果不是最高的墙，那么同样存在另一个比height[left]高的墙，那么left列上同样可以接到水，且接水量同样是leftMax-height[left]。

```java
public int trap(int[] height) {
    if (height==null||height.length<3)return 0;
    int leftMax=0,rightMax=0,ans=0,left=1,right=height.length-2;
    while (left<=right){
        //计算更新leftMax rightMax
        leftMax=Math.max(leftMax,height[left-1]);
        rightMax=Math.max(rightMax,height[right+1]);
        //比较leftMax和rightMax，找到较低的那一侧
        if (leftMax<rightMax){
            if (leftMax>height[left])ans+=leftMax-height[left];
            left++;
        }else {
            if (rightMax>height[right])ans+=rightMax-height[right];
            right--;
        }
    }
    return ans;
}
```

时间复杂度：O(n)

---

本人菜鸟，有错误请告知，感激不尽！

更多题解和学习记录博客:[博客](https://blog.csdn.net/qq_42758551)**、**[github](https://jerrymouse1998.github.io/)