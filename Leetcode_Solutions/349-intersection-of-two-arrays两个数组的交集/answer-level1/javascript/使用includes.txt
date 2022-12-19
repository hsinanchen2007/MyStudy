### 解题思路

includes() 方法用来判断一个数组是否包含一个指定的值，如果是返回 true，否则false。

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let list = []
    nums1.forEach(item => {
      if(nums2.includes(item)&&!list.includes(item)){
         list.push(item)
      }
    })
    return list
};
```


```js
var intersection = function(nums1, nums2) {
    return [...new Set(nums1)].filter(item => {
      return nums2.includes(item)
    })
};
```