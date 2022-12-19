### 解题思路
方法一、排序+双指针
### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    nums1.sort((a, b) => a - b);//升序排序
    nums2.sort((a, b) => a - b);
    var arr=[]
    for(var i=0,j=0,k=0;i<nums1.length&&j<nums2.length;){
        if(nums1[i]<nums2[j]){
            i++;
        }else if(nums1[i]==nums2[j]){
            arr.push(nums1[i]);
            i++;
            j++;
        }else{
            j++;
        }
    }
    return arr;
};
```
方法二、哈希表
```
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    var map=new Map()
    var arr=[];
    for(var i=0;i<nums1.length;i++){
        if(map.has(nums1[i])){
            map.set(nums1[i],map.get(nums1[i])+1)
        }else{
            map.set(nums1[i],1)
        }
    }
    for(i=0;i<nums2.length;i++){
        if(map.has(nums2[i])){
            arr.push(nums2[i]);
            if(map.get(nums2[i])>1){
                map.set(nums2[i],map.get(nums2[i])-1)
            }else{
                map.delete(nums2[i])
            }
        }
    }
    return arr;
};
```
