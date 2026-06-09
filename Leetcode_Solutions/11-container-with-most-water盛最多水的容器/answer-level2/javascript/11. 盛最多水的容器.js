# 暴力法
暴力法没什么好说的，按照正常遍历和面积公式直接莽过去就完事~
```
var maxArea = function(height) {
    let area = 0;
    for(let i = 0,len = height.length;i<len;i++){
        for(let j = i+1;j<len;j++){
            let w = j-i;
            let h = Math.min(height[i],height[j]);
            area = Math.max(area,w*h);
        }
    }
    return area;
};
```
# 双指针法
这里要解释一下双指针：
通过四边形的面积公式我们可以知道，面积受到四边形宽度以及高度所影响；
如题中所示的这样在遍历中高度需要实际的去获取时，无疑是先确定宽度是最为合适，而最大的宽度无疑是数组的首末；
计算完上一次面积之后，关于指针的移动，我们这里需要做几个假设：
假设1：移动两个指针高度较高的，下一个指针高度高于四边形高度，宽度减小，四边形高度不变，面积值减小
假设2：移动两个指针高度较高的，下一个指针高度低于四边形高度，宽度减小，高度减小，面积值依旧减小
假设3：移动两个指针高度较低的，下一个指针高度高于四边形高度，宽度减小，高度增加，面积值可能增加
假设4：移动两个指针高度较低的，下一个指针高度低于四边形高度，宽度减小，高度减小，面积值减小
首先通过假设，在移动较小指针的过程中可以寻找较大值
然后以上四个假设都是定宽情形下，所有移动指针的面积变化情况，进而可以以假设推导假设，以上指针移动不止一格，假设1，2，3，4依旧成立
即通过确定四边形宽，通过增加指针的方式，减去面积一定减小的方案~
```
var maxArea = function(height) {
    let area = 0;
    let left = 0,right = height.length-1;
    while(left != right){
        area = Math.max(area,(right-left)*Math.min(height[left],height[right]));
        height[left] < height[right]?(left++):(right--);
    }
    return area;
};
```
