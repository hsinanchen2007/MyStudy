矩形的面积是长和宽相乘，如果要面积大，那么长和宽要尽可能的长。

在这题里，矩形的宽就是`h(i)`和`h(j)`的距离，就是`(j-i)`,而宽则是`h(i)`和`h(j)`中较短的那一条。那么要面积尽可能的大，就需要`Math.min(h(i),h(j))`尽量大，`(j-i)`尽量大。

我们设置两个指针 `left`和 `right`，分别指向数组的最左端和最右端。此时，两条垂直线的距离是最远的，若要下一个矩阵面积比当前面积来得大，必须要把 `height[left]`和 `height[right]`中较短的垂直线往中间移动，看看是否可以找到更长的垂直线。

因为将较长的那根垂直线往中间移动，面积只会减小，所以移动较短的那根。

将所有的情况用递归树列出来，如下图：

![IMG_9099.JPG](https://pic.leetcode-cn.com/4e081d02c08414eae8febeec4da9b375bbfbc466bc73ea1db3009a1883e876e6.JPG)

 数组是 `[1,8,6,2,5,4,8,3,7]`

指针在两端，没进行一次比较就能划去一列不可能的选项。如下图，当比较第一次的时候，h(0)h(8)比较，此时的面积是h(0)*(8-0)=8，那么就需要划掉跟0相关的那一列，因为那一列的面积肯定只会比8小。如下图：

![1](https://pic.leetcode-cn.com/37cda03cfbbc3b1cdda883b72169ec99f30ab47ff235988bea52b319dea9ee07.JPG)

然后比较下一级h(1)和h(8)，从而得出面积是49，因为h(1)>h(8),所以可以划去跟h(8)相关的一列，因为面积无论怎么样都会小于(1,8)，如下图

![2](https://pic.leetcode-cn.com/da205be867e8a5575cd8d572aa7b0824df055e67f71998ae589c12bb21be46b8.JPG)



以此类推，最终得到一条路线。

![1.jpeg](https://pic.leetcode-cn.com/9304b94e20d7bc8745a01e0a9da479c075628e39c074461a0fdaa77861532319-1.jpeg)


在比较的时候就把最大值存入一个变量中，然后在结束的时候返回就行。

```js
var maxArea = function(height) {
    let maxS = 0;
    let i = 0,j = height.length-1;
    while(i < j){
      maxS = Math.min(height[i],height[j])*(j-i)>maxS?Math.min(height[i],height[j])*(j-i):maxS;
      height[i] <= height[j] ? i++ : j--
    }
    return maxS;
  };
```


执行用时 :64 ms, 在所有 JavaScript 提交中击败了97.97%的用户

内存消耗 :35.2 MB, 在所有 JavaScript 提交中击败了85.63%的用户



其实意思是懂了，也理解了，不过我作为前端，对于指针的概念还不是很清楚，所以理解起来会比较慢。以上也都是些粗略的理解。借鉴了很多大佬的题解。