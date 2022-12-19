### 运行情况
![image.png](https://pic.leetcode-cn.com/fcea7a2858422e60b80b826d280375e242476575887b3471fe77464799ff0e31-image.png)

### 思路
题目数组都是单调递增的
当一个数`a[i]`左侧有一个数比它大的时候，或者右侧有一个数比它小的时候，它一定是在被排序的序列内。
因为一个数如果 左边的数都比它小，右边的数都比它大，显然没必要排序。
关键是我们如何找出 
- <1>最右侧一个`a[i]`，它的左边含有一个大于它的数
- <2>最左侧一个`a[i]`，它的右边含有一个小于它的数

我们这里可以使用两次遍历，分别从左往右找<1>，从右往左找<2>。
- 记录当前遍历序列的最大值MAX，如果有一个数比它小，那么记录这个数的index，遍历完成后，这个index即是<1>
- 记录当前遍历序列的最小值MIN，如果有一个数比它大，那么记录这个数的index，遍历完成后，这个index即使<2>


### 代码

```javascript
/**
 * @param {number[]} array
 * @return {number[]}
 */
var subSort = function(array) {
    let r=-1,l=-1;
    //正向遍历记录最右区间值
    let max = Number.MIN_SAFE_INTEGER;
    for(let i=0;i<array.length;i++){
        if(array[i]>=max){
            max = array[i];
        }else{
            r = i;
        }
    }
    //反向遍历记录最左区间值
    let min = Number.MAX_SAFE_INTEGER;
    for(let i=array.length-1;i>=0;i--){
        if(array[i]<=min){
            min = array[i]
        }else{
            l = i;
        }
    }
    return [l,r]
};
```