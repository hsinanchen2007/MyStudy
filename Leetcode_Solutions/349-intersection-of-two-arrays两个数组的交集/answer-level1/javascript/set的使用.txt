### 解题思路
方法一、比较复杂

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    var map1=new Map();
    var map2=new Map();
    var arr=arr2=[];
    var j=k=0
    for(var i=0;i<nums1.length;i++){
        if(map1.has(nums1[i]) == false){
            map1.set(nums1[i],i)
        }
    }
    for(i=0;i<nums2.length;i++){
        if(map2.has(nums2[i]) == false){
            map2.set(nums2[i],i);
        }
    }
    var arr1 = [...map2.keys()];
    for(i=0;i<arr1.length;i++){
        if(map1.has(arr1[i])){
            arr.push(arr1[i])
        }
    }
    return arr;
};
```
方法二、利用set的一些性质
```
var intersection = function(nums1, nums2) {
    var a=new Set(nums1);
    var b=new Set(nums2);
    let intersect = new Set([...a].filter(x => b.has(x)));
    return [...intersect];
};
```
