```
class Solution {
    public int search(int[] nums, int target) {
		return half_search(nums, target, 0, nums.length - 1);
	}

	public int half_search(int[] nums, int target, int min, int max) {
		int middle = (min + max) / 2;
		if (max < min)//target不在数组里，看下面模拟示例2的过程
			return -1;//返回-1
		if (target == nums[middle])//找到target
			return middle;//返回数组下标
		else if (target > nums[middle]) {//target在下标为middle的元素右边
			min = middle + 1;//下标为middle的元素在上一个if里面判断过了，避免再次判断，也为了max<min这个条件的成立，所以进行+1操作
			return half_search(nums, target, min, max);//递归
		} else {//同上
			max = middle - 1;
			return half_search(nums, target, min, max);
		}
	}
}
```
用本代码模拟示例2过程：
第一次：min=0,max=5,middle=2,nums[2]=3>target=2,进入else分支，max=middle-1=2-1=1;
第二次：min=0,max=1,middle=0,nums[0]=-1<target=2,进入else if分支，min=middle+1=0+1=1;
第三次：min=1,max=1,middle=1,nums[1]=0<target=2,进入else if分支，min=middle+1=1+1=2;
第四次：min=2,max=1,middle=1,直接在第一个if(max<min)时返回-1，查找结束。