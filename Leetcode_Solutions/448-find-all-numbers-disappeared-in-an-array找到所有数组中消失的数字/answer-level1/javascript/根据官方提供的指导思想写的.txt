### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    //把每个数字对应的index位置的元素设置为它的相反数也就是0-n，用来标志它是否出现了
    for(let n of nums){
        const pos = Math.abs(n)-1;
        const slot=nums[pos];
        if(slot>0)nums[pos]=-slot;
    }
    const res=[];
    for(let i=0; i<nums.length; i++){ //第二次再检查>0的元素（因为没其他数等于它的index，所以没被标志）就是所缺少的数字了
        const n=nums[i];
        if(n>0)res.push(i+1);
    }
    return res;
};
```