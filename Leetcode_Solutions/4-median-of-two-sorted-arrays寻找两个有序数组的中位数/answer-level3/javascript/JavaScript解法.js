### 解题思路
求中位数，所以循环只需要跑一半，再判断下奇偶就可以了

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    var i=0;
    var j=0;
    var num=[];
    if (nums1.length===0){
        if (nums2.length%2===1){
            return nums2[parseInt(nums2.length/2)]
        }
        else return (nums2[parseInt(nums2.length/2)]+nums2[parseInt(nums2.length/2)-1])/2    
    }
    if (nums2.length===0){
        if (nums1.length%2===1){
            return nums1[parseInt(nums1.length/2)]
        }
        else return (nums1[parseInt(nums1.length/2)]+nums1[parseInt(nums1.length/2)-1])/2    
    }
    for (var k=0;k<=((parseInt(nums1.length+nums2.length))/2);k++){
        if(nums1[i]===undefined){
            num.push(nums2[j]);
            j++
        }
        else if (nums2[j]===undefined){
            num.push(nums1[i]);
            i++
        }else if (nums1[i]<nums2[j]){
                num.push(nums1[i]);
                i++;
              }
               else{
                   num.push(nums2[j]);
                   j++;
               }
    }
    if ((nums1.length+nums2.length)%2===1){
        return num[parseInt((nums1.length+nums2.length)/2)]
    }
    else return (num[parseInt((nums1.length+nums2.length)/2)]+num[parseInt((nums1.length+nums2.length)/2)-1])/2
};
```