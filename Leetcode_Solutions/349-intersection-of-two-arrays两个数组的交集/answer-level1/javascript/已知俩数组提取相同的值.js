### 解题思路
1/先声明新的空数组
2、判断已知的数组中的值是否在另一个数组中并且属否已经在新的数组中生成
3、否和条件push

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    var newArry = [];
    nums1.forEach((item,index)=>{
        if(nums2.indexOf(item)>-1 && newArry.indexOf(item) ===-1){
            newArry.push(item)
        }
    })

    return newArry
};

```