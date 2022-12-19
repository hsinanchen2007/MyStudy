我看过许多高手的模板，但是无不例外都有个特点：一些特殊情况需要另外考虑。
很麻烦，改bug改得让人头皮发麻。
恭疏鄙见，敬请斧正：
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int i=0,j=nums.size() - 1;
		int mid;
		while (i<=j)
		{
		mid = i+(j-i)/2;
		if(target>nums[mid])i = mid+1;
		else j = mid-1;                //很巧妙，一般模板都是j = mid;
		}                          //但是那样的话结果会有很多麻烦
		return i;
    }
};
```
我是怎么发现这个办法的呢？我写代码的时候并没有看过其他人的解法，自然而然写出了这个解法。
我感觉一般学过的专业的人else后面都不会用mid-1（排除的思想）毕竟这样可能会降低效率什么的。。。
然后我就用了，然后我就惊喜地发现，所有情况下只需要输出i就是答案了，包括已知的特例。。。
