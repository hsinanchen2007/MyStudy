二分法说简单了其实就是都是一个函数模板，说难了也真是难啊，各种变换
```
Int bsearch_l(int l, int r)
{
	while(l<r)
	{
		int mid = l+(r-l)>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	return l;
}
```
难就难在找这个check
这道题，如果单一元素在mid之前或之后，那么前后相等的元素的位置就会发生变化，说肯定难懂，举几个例子就好了。
如果单一元素在第一个或者最后一个，单独判断一下，因为后面会用到mid-1 和 mid+1。
比如数组[1 1 2 3 3 4 4 8 8]
index  [0 1 2 3 4 5 6 7 8]
一开始mid是4，是偶数，nums[3] == numd[4] => right = mid - 1;
如果是 [1 1 2 2 3 3 4 8 8]
index [0 1 2 3 4 5 6 7 8]
一开始mid是4，是偶数，nums[4] == num[5] => left = mid + 1;
同理： 数组 [1 1 2 2 3 4 4]
index     [0 1 2 3 4 5 6]
mid = 3 奇数，nums[2] == nums[3] => left = mid + 1;
[1 1 2 3 3 4 4]
[0 1 2 3 4 5 6]
mid = 3 nums[3] == nums[4] => right = mid - 1;
最后是代码：

```
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int left = 0, right = n-1;
        while(left<right)
        {
            int mid = left + ((right-left)>>1);
            if(nums[mid+1]!=nums[mid] && nums[mid-1]!=nums[mid]) return nums[mid];
            else
            {
                if(mid%2==0 && nums[mid-1]==nums[mid]) right = mid-1;
                else if(mid%2==0 && nums[mid+1]==nums[mid]) left = mid+1;
                else if(mid%2==1 && nums[mid-1]==nums[mid]) left = mid+1;
                else if(mid%2==1 && nums[mid+1]==nums[mid]) right = mid-1;
            }            
        }
        return nums[left];
    }
```
