### 解题思路
双指针法
首先设置p指向数组中第0个元素，q指向第1个（在这之前先确保第一个元素不为0，之后介绍）。如果nums[q]不为0，那么将q上的值赋给nums[p+1]，如果nums[q]==0,则q++  
可以看出如果数组中没有需要删除的元素那么等于自己给自己赋值了一遍，p其实记录的就是需要保存的元素的长度。
但是运用这个方法首先要保证第一个p所指不为0，也很简单，用一个while循环判断nums[P]是否为0，如果是0那就把nums[q]赋值给nums[p]，然后p++ ，等循环结束数组数组第0个位置上就是数组中第一个非0元素，p==0。
最后循环条件是q<numsSize，遍历一遍以后将p以后的位置都用0填充，注意p需要加一。

### 代码

```c

void moveZeroes(int* nums, int numsSize) {
	if (numsSize > 1) {
		int p = 0, q = 1;
		while (nums[p] == 0 && q < numsSize) {
			nums[p] = nums[q];
			q++;
		}
		if (q == numsSize) {
			//说明数组中全是0
		}
		else {
			while (q < numsSize) {
				if (nums[q] == 0) {
					q++;
				}
				else {
					nums[p + 1] = nums[q++];
					p++;
				}
			}
		}
        p+=1;
        while (p < numsSize) {
			nums[p++] = 0;
		}
	}
}
```
![1.png](https://pic.leetcode-cn.com/57c7c6bcfc1d47e07dcdd6dbe63035ef7b691a2526a44060b9c69a22fc2ffb3b-1.png)
