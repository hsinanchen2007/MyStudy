### 解题思路
快速选择
![屏幕快照 2020-03-20 下午1.01.06.png](https://pic.leetcode-cn.com/92c4b6bd686981aa0332a0e41cd811366aa68b3725eeb4d07aa2945454e6f647-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-20%20%E4%B8%8B%E5%8D%881.01.06.png)

和这道题类似[https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/]()
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    var len=nums.length;
    var start = 0;
    var end = len-1;
    if(!len)return null;
    var index = quickSort(nums,start,end);
//跳出循环的条件是，返回的索引恰好就是要找的第k大的数字
    while(index !== k-1){
        if(index>k-1){
            end = index-1;
            index = quickSort(nums,start,end);
        }else{
            start = index+1;
            index = quickSort(nums,start,end);
        }
    }
    return nums[k-1];
};
//将大的数放在左边，小的数放在右边
function quickSort(nums,left,right){
    var pivot = nums[right];
    while(left<right){
        while(left<right && nums[left]>=pivot){
            left++;
        }
        nums[right]=nums[left];
        while(left<right && nums[right]<pivot){
            right--;
        }
        nums[left]=nums[right];
    }
    nums[right]=pivot;
    return left;
}