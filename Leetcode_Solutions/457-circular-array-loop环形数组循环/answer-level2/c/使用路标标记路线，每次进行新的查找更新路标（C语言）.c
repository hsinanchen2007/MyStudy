### 解题思路
本题的难点在于，一次路线查找失败后，下一次查找，要区分：（1）未访问（2）失败路线（3）当前路线
因此每次路标需要更新。另外是否长度为1，在找到当前路线后，检查一下即可。

![image.png](https://pic.leetcode-cn.com/16ecbcc6fccea0fc6820b682d0864b91d067f5cc9b310c95122ef2915d6d76cf-image.png)

### 代码

```c

//【算法思路】路标。已经访问过的位置标记，但是开始出现异常的点不标记。为了区分是否访问到之前失败路线，则路标每次更新。
// 注意：1.路标每次更新;2.负数求余等于numsSize + rem
bool circularArrayLoop(int* nums, int numsSize){
	if(numsSize < 2)
	{
		return false;
	}

	int *flags = (int *)calloc(numsSize, sizeof(int));

	int tag  = 1;

	for(int i = 0; i < numsSize; i++)
	{
		//排除已经访问过的点
		int id = i;
		bool org_dir = nums[i] > 0;
		bool new_dir = org_dir;
        //printf("id = %d, new_dir = %d\n", id, new_dir);

		while(flags[id] == 0 && new_dir == org_dir)
		{
			//打当前tag
			flags[id] = tag;
			//计算新id
			id = nums[id] + id;
			id %= numsSize;
            id = id >= 0? id : id + numsSize;
			new_dir = nums[id] > 0;
            //printf("id = %d, new_dir = %d\n", id, new_dir);
		}

		if(flags[id] == tag && new_dir == org_dir)
		{
			//判断长度
			int new_id = nums[id] + id;
			new_id %= numsSize;
            new_id = new_id >= 0? new_id : new_id + numsSize;

			if(id != new_id)
			{
				return true;
			}
		}

		tag++;
	}

	return false;
}
```