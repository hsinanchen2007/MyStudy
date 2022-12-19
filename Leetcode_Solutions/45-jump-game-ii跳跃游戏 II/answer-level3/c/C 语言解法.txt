### 解题思路


### 代码

```c
int jump(int* nums, int n){
	if(n==2) return 1;
    if(n==1) return 0;
	int cur=0,maxStep,max_index;
	int pre=0,ans=0;
	for (int i = 0; i < n; )
	{
		cur = nums[i];//当前的台阶
        if((i+cur)>=n-1){//若当前可以一步到终点
            ans++;
            break;
        }

		maxStep = -1, max_index = i; // 重置
		for (int j = i+cur; j > i; j--) // 找最大的落脚点
		{
			if((nums[j]+j)>maxStep){
				max_index = j;
				maxStep = nums[j]+j;
			}
		}

		if (maxStep==0){
			// return false;
			// 若所有的落脚处都是 0，则说明这个阶梯不能踩上去，将数组置空
			nums[i] = 0;
			i = pre; //回到上一个台阶
			ans--;
		}else{
			pre = i ;
			i=max_index;
			ans++;
		}

	}
	return ans;
}
```