### 解题思路
双指针2.0--滑动窗口的应用

![image.png](https://pic.leetcode-cn.com/f87698103b070b416ade08cb6d168d86282c5c65c74072c01732fbe604117f7d-image.png)
### 代码

```c
int minSubArrayLen(int s, int* nums, int n){
	int sum=0,start=0,end=0,minLen=INT_MAX,curLen=0;
    if(n==0)return 0;
	while(end<n){
		sum+=nums[end];//将当前值纳入窗口中
        end++;//
		curLen++;//当前长度加一
		while(sum>=s){//若窗口里的和大于等于s的话
            //更新窗口的最小长度
            minLen = curLen < minLen ? curLen : minLen;
            
            sum-=nums[start];//开始缩小窗口
            start++;
			curLen--;
		}
	}
	return minLen == INT_MAX? 0 : minLen;
}
```