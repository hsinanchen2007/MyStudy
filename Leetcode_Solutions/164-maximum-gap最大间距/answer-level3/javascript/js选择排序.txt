### 解题思路
js根据选择排序的原来，在选择排序的过程中确定相邻项之间的差值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
    if(nums.length<2)
    return 0;

    var maxCur=0;
    // 选择排序
    for(let i=0,min;i<nums.length;i++){
        min=nums[i];
        for(let j=i+1,tmp=[];j<nums.length;j++){
            if(min>nums[j]){
                let mid=min;
                min=nums[j];
                nums[j]=mid;
            }
        }
        nums[i]=min;
        // 第二轮循环才可以确定下来第一个位置和第二个位置
        if(i>0){
            let cur=nums[i]-nums[i-1];
            if(cur>maxCur)
            maxCur=cur;
        }
    }

    return maxCur;
};
```