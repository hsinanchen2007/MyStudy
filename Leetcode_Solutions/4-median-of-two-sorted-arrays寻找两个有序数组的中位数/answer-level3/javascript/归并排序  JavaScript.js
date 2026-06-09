### 解题思路
根据两个数组的特点：有序数组。
一、将两个数组利用**归并排序**算法的思想合并为一个数组
二、找出合并后的数组的中位数。如果合并后的数组长度为偶数，则为中间两个数的和的一半，如果为奇数，则为中间的数的一半
注意：返回结果为浮点数，采用JavaScript中的**toFixed()**方法选择保留的小数位数

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1,nums2){
				var arr = [];
				var p1 = 0;
				var p2 = 0;
				while(p1<nums1.length&&p2<nums2.length){
					if(nums1[p1]<nums2[p2]){
						arr.push(nums1[p1]);
						p1++;
					}else{
						arr.push(nums2[p2]);
						p2++;
					}
				}
				while(p1<nums1.length){
					arr.push(nums1[p1]);
					p1++;
				}
				while(p2<nums2.length){
					arr.push(nums2[p2]);
					p2++;
				}
				var len = arr.length;
				var mid = 0;
				if(len%2==0){
					mid = ((arr[len/2]+arr[(len/2)-1])/2).toFixed(5);
				}else{
					mid = (arr[(len-1)/2]).toFixed(5);
				}
				return mid;
};
```