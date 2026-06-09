参考了官方题解，需要注意的地方是原地修改，就是不能修改原始的数据的长度之类的
```
var nextPermutation = function(nums) {
    let len = nums.length
    if(len<2) return nums;
    let l = len-1
    let r = 0
   //  从数列的右侧开始检索，对比连续两个大小，如果右侧小于左侧，则说明这连续的两个数是降序，他们之间已经是最大值，需要继续对比下一个连续数
    while(nums[l]<=nums[l-1]) {
    	l--
    }
    // 得到左侧数小于右侧后，说明这个是可以排的下一个较大的一个位置，但是我们需要知道这个位置应该是什么数合适，应该是一个比他大一点的数
    while(nums[l-1]<nums[l+r]) {
		r++
	}
	if(l===0){
		return nums.reverse()
	}
	let f = nums[l-1]
	let s = nums[l+r-1]
	nums[l-1] = s
	nums[l+r-1] = f
// 调换位置后我们需要对位置后的数列进行升序排，因为升序后后剩余数是最小的，即是我们需要的下一个大数
	let sp = nums.slice(l).reverse()
	for(let i=0; i<sp.length; i++) {
		nums[l+i] = sp[i]
	}
	return nums
};
```