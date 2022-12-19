#### 1.暴力法
时间复杂度：O(n^2)  
空间复杂度：O(1)
```
var maxArea = function(height) {
    const len = height.length
    let result = 0,tmp = 0
    for(let i=0;i<len;i++){
        for(let j=i+1;j<len;j++){
            tmp = (j-i)*Math.min(height[i],height[j])
            result = Math.max(result,tmp)
        }
    }
    return result
};
```
#### 2.双指针法
时间复杂度：O(n)  
空间复杂度：O(1)
###### 算法思路：
- 两线段之间形成的区域总是会受到其中较短那条长度的限制  
- 两线段距离越远，得到的面积就越大  

1. 我们在由线段长度构成的数组中使用两个指针，一个放在开始，一个置于末尾。 此外，我们会使用变量来持续存储到目前为止所获得的最大面积。 
1. 在每一步中，我们会计算出指针所指向的两条线段形成的区域，更新变量，并将指向较短线段的指针向较长线段那端移动一步。

```
var maxArea = function(height) {
    const len = height.length
    let result = 0,tmp = 0
    let i=0,j=len-1;
    while(j>i){
        tmp = (j-i)*Math.min(height[i],height[j])
        result = Math.max(result,tmp)
        height[i]>height[j] ? j-- : i++
    }
    return result
};
```

 