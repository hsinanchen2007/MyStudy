### 解题思路
此处撰写解题思路
刚学c,书写上比较简陋，请多谅解。

核心思路：本题只遍历一次，先判断首尾是否满足前大后小，有一个不满足，则t++；
然后从1到n-2遍历，即每当查到a[i]>a[i+1]时，说明出现了违反前小后大的情况，此时再判断这两个数与左右相邻的a[i-1]和a[i+2]的大小关系，如果a[i]比二者中大的（a[i+2]）还大并且a[i+1]比小的(a[i-1])还小,则此时必须改变两个数才行，此时直接false；若满足其中一个条件，则只改变a[i]和a[i+1]之一即可，此时该数已找到，t++；每次遍历检查t是否为2，若是说明需改两个数，返回false，若t==1，说明改一个数即可，返回ture，t==0，说明不需改变。


### 代码

```c
bool checkPossibility(int* nums, int numsSize){
	int i,t=0;   //t用于记录可改变数的个数，先置0
    int n=numsSize;  //为书写方便
    if(n<=3)   //小于3的情况不再赘述
    {       
        for(i=0;i<n-1;i++) {
            if(nums[i]>nums[i+1])
                t++;
        }
        if(t==2)
	    return false;
	    else
	    return true;
    }
    else   //n>3
	{
    if(nums[0]>nums[1])
	t++;
	if(nums[n-1]<nums[n-2])  //检查首尾
	t++;
	for(i=1;i<n-2;i++) 
    {
		if(t==2) 
			return false; 
		if(nums[i]>nums[i+1]) 
        {
			if(nums[i]>nums[i+2]&&nums[i+1]<nums[i-1])
			return false;
			else
			t++;
		}
	}
	if(t==2)
	return false;
	else
	return true;
    }
}
```