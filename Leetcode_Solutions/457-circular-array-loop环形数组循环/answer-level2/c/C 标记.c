时间复杂度为 O(n)、额外空间复杂度为 O(1)
首先想到的是标记法。

标记中留存的信息有：正负号，用于判断路线是否可行。
                  访问轮次： 用来判断是否是本轮路线上的点。

因为 -1000 ≤ nums[i] ≤ 1000， 所以 使用了 ±(2000 + slow)做为标记。


```
int code(int* nums, int i, int key);
bool circularArrayLoop(int* nums, int numsSize){
	
	for(int slow = 0; slow < numsSize; slow++)
	{
		if(nums[slow] > 1000 || nums[slow] < -1000)
		{
			continue;
		}
		
		int fast = (slow + nums[slow] % numsSize + numsSize) % numsSize; 
		
		code(nums, slow, slow); // code 是给当前的循环做标记， 标记是 slow

        if(fast == slow) // 循环长度必须大于一
        { 
            continue;
        }
		while((nums[fast] > 0 && nums[slow] > 0) || (nums[fast] < 0 && nums[slow] < 0)) // fast和slow方向必须一致
		{
			if(nums[fast] > 1000 || nums[fast] < -1000) //如果fast 被编号了，说明之前走到过
			{
				if(abs(nums[fast]) - 2000 == slow) // 如果编号的是当前正在走的轮次，说明发现了循环， 如果不是，说明此路不通不用继续走了（如果通的话之前就走到了）
				{
					return true;
				}
				break;
			}
			
			int next = (fast + code(nums, fast, slow) % numsSize + numsSize) % numsSize;  // 同理也得检查循环长度的大小。 
	
			//另外索引计算必须多次取余， 先对nums[i] 取余，因为nums[i]可能很小， 使得fast + code(nums, fast, slow) % numsSize + numsSize为负数。最后索引也是负数

            if(next == fast)
            {
                break;
            }

            fast = next;
		}
	}
	
	return false;
}


int code(int* nums, int i, int key) // 给nums[i] 编码并返回编码前的值
{
	int temp = nums[i];
	if(nums[i] > 0)
	{
		nums[i] = 2000 + key;
	}
	else
	{
		nums[i] = -2000 - key;
	}	
	return temp;
}
```
