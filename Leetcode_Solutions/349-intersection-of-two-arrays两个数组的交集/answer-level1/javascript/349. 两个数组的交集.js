### 解题思路
+ map`nums1`,与`nums2`进行比较，
+ 只要`nums2`里有的，则存起来，
+ 最后对结果进行去重

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  let result =[];
  nums1.map((k)=>{
    let index = nums2.findIndex(d=>d==k);
    if(index>=0){
      nums2.splice(index,1);
      result.push(k);
    }
    return k;
  });
  return [...new Set(result)];
};
```