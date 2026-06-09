再一次做到这个题 觉得是时候彻底搞明白二分查找的区间问题和中位数选择问题了 先贴一发自己一开始的代码
```
class Solution {
    public int searchInsert(int[] nums, int target) {
    	int len = nums.length;
    	int left = 0;
    	int right = len - 1;
    	while (left <= right) {
    		int mid = (left + right) / 2;
    		if (nums[mid] == target)
    			return mid;
    		else if(nums[mid] > target)
    			right = mid - 1;
    		else
    			left = mid + 1;
    	}
    	return left;
    }
}
```
这个代码我一直没闹明白为什么return left 但是我知道return left在很多情况下是对的 然而 不明白!!!

今天看了[@liweiwei1419](/u/liweiwei1419/)老哥题解 终于悟透 不再单独判断target == mid 当l = r 我就结束循环 这样
我想return l就return l 想 return r就return r!

题目的要求不同 二分法的方法相应的也会有不同
1.若题目中明确说明输入的数组一定包含要找的目标值target 那么 l = 0; r = nums.length - 1; return l当然也可以return r 因为l = r嘛)
2.若题目中的输入数组中不一定含有要找到目标值target,那么大体可以划分成一下几个情况
   1>若不存在要求返回-1 那么 l = 0; r = nums.length - 1; 在循环结束后 需要判断left(当然也可以判断y是否等于target) 若是就按照题目要求返回 不是就返回-1
   2>若不存在要求返回它应该在的位置(第一个比target大的数的位置) 那么 l = 0; r = nums.length(如果target比nums中所有元素都大 那么他返回的index应该是nums.length) 在这种情况下 应选择使用左中位数l + r / 2 排除left 即left = mid + 1
   3>若不存在要求返回第一个比他小的数的位置 那么l = -1(如果target比nums中所有元素都大 那么他返回的index应该是nums.length); r = nums.length 在这种情况下 选择使用右中位数 l + r + 1 / 2  排除right 即right = mid - 1

下面是左中位数和右中位数的选取
 简单说 如果选错了中位数 程序会进入死循环 具体原因不太好描述 自己用一个两个元素的数组试一下就明白了
 重点说若何选取中位数
 1.首先 要先写完下面的if判断语句(你没有看错 就是要先写if语句！！) 因为我们只有知道了l + 1还是r + 1我们才能决定使用哪个中位数 我推荐在写if语句是只写一个if 这个if语句要能使得边界 + 1(即l + 1或r + 1) 换句话说 要完全排除掉mid是解的可能 若不能完全排除 则另一个条件就不能直接写else (这也解释了上面说的 在返回第一个比target大的数的位置是 要选取左中位数 因为如果if判断的是 target < nums[mid] 这一条件是无法保证mid不是解的 它很有可能就是第一个比target大的数 因此之后你还需要判读target == nums[mid] 这样一来你会发现 绕了一圈还是l + 1 如果不懂 下面有这两种if的具体代码)
 2.在完成了if语句之后 我们可以正式选择中位数了 现在问题变得很简单 谁+1就选谁中位数(若在if语句中是l+1 那么就选左中位数)

```
/** 缩小左边界 */
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0;
        int r = nums.length;
        while (l < r){
            int mid = l + (r - l) / 2;
            if (target > nums[mid]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return r;
    }
}

/** 缩小右边界 */
class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0;
        int r = nums.length;
        while (l < r){
            int mid = l + (r - l) / 2;//在完成下面的if语句后在确定使用左还是有中位数 由于左侧被缩小 所以用左中位数
            if (target < nums[mid]){
                r = mid;//这里并不是mid + 1 因为若数组中不存在target nums[mid]就有可能是第一个比target大的数 即为解
            }
            else if (target == nums[mid]){
                r = mid;//这个模板不存在等于target就返回的if 在此可将其与上面的if合并 变成target<=nums[mid]
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
}