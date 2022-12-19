### 解题思路
这是我第一次完全自己思考 解答出来的第一个题目
笨拙的解题方法 也留下点脚印
也暴露出自己这方面有多么的不足吧

希望接下来的练习中 可以看到自己的进步 加油

执行用时200ms 内存消耗39.6MB
### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */

var findMedianSortedArrays = function(nums1, nums2) {
    //有序数组
    //判断数组是否为空 合并数组 再排序 获取数组的长度 判断奇偶性 得出中位数
    let arr = nums1.concat(nums2)
    arr =arr.sort((a, b) => {
            return a-b; // 从小到大排序
        });
    let len = arr.length
    if(len%2 == 0){
        let num = len/2
        return (arr[num-1] + arr[num])/2
    }else{
        let num = Math.ceil(len/2)
        return arr[num-1]
        
    }
};

```