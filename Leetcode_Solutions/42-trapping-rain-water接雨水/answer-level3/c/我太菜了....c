### 解题思路
此处撰写解题思路

### 代码

```c

int trap(int* height, int heightSize)
{
	int ans = 0, l = 0, r = heightSize-1;
	int max_l = 0, max_r = 0;
	
	while(l < r)
	{
		max_l = max_l > height[l] ? max_l : height[l];
		max_r = max_r > height[r] ? max_r : height[r];
		
		if(max_l < max_r)
		ans += max_l - height[l++];
		else
		ans += max_r - height[r--]; 
	}
	
	return ans;
}
```