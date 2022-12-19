既然显示打败了100%，不管是不是bug了，我就信了，开心一下。  

### 思路
分享自己根据题目特点结合排序思想搞的排序。  


1. 使用 low 保存数组中存储 0 的位置。
2. 使用 high 保存数组中存储 2 的位置。
3. 遍历数组。
4. 如果 i 离开 low 的区域，通过判断将外面的 0 交换回去。
5. 同理处理 2 。
6. 注意交换的时候要执行 i-- ，因为交换过来的数有可能还需要被交换出去。

**成功解决**


### 答题
```C++
void sortColors(vector<int>& nums) 
{
	int low = 0;
	int high = nums.size() - 1;
	while (low < nums.size() && nums[low] == 0) low++;
	while (high > low && nums[high] == 2) high--;
	for (int i = 0; i < nums.size(); i++)
	{
		auto swap = [](int &a, int &b) {if (a == b) return; a ^= b; b ^= a; a ^= b; };
		if (i > low && nums[i] == 0) swap(nums[i--], nums[low++]);
		else if (i < high && nums[i] == 2) swap(nums[i--], nums[high--]);
	}
}
```

### 测试
[2,0,2,1,1,0]  
[1,0]  
[2,0]  
[1,2,0]  


另外效率的话有可能是卡bug了才100%，大家不要太当真，做的多了经常会出现这种情况。  




### 致谢
感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)