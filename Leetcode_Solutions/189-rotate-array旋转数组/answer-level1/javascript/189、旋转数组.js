### 解题思路
**方法一、暴力法**
每次只移一位
### 代码
```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    var pre,temp;
    for(var i=0;i<k;i++){
        pre=nums[nums.length-1];
        for(var j=0;j<nums.length;j++) {
            temp=nums[j];
            nums[j]=pre;
            pre=temp;
        }
    }
};
```
**方法二、**
首先将所有元素反转。然后反转前 k 个元素，再反转后面 n-kn−k 个元素，就能得到想要的结果。
```
原始数组                  : 1 2 3 4 5 6 7
反转所有数字后             : 7 6 5 4 3 2 1
反转前 k 个数字后          : 5 6 7 4 3 2 1
反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果
```


```
var rotate = function(nums, k) {
    k=k%nums.length;
    reverse(nums,0,nums.length-1);
    reverse(nums,0,k-1);
    reverse(nums,k,nums.length-1);
};
function reverse(arr,start,end){
    while(start<end){
        var temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--; 
    }
}
```

