思路

例子 1,1,1,2,2,3
由于数组是排序好的
那么这个题本质是去重

拿一个指针从最开始0号位置 一直到最后5号

**那么实际当前元素 不等于 后面元素   则说明当前数字在接下来的数组里面唯一了**

**就把这个元素塞到新数组里面就行了**

**由于指针往后移了 所以可以直接按顺序塞到nums里面即可 不会与后面未处理的混淆**

func removeDuplicates(nums []int) int {
	length :=len(nums)

	if(length<=1){
		return length
	}
	if(length==2){
		if nums[0]==nums[1]{
			return 1
		}else{
			return 2
		}
	}

	var j =0
	for i:=0;i<length;i++{
		if( (i==length-1) || (nums[i]!=nums[i+1])){
			nums[j]=nums[i];
			j++
		}
	}

	return j
	

}