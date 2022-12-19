### 解题思路
双指针分别指向头尾。如果小头++，如果大尾--。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
	//定义双指针一次遍历
	int *data=malloc(8);
    data[0]=0;
    data[1]=0;
	int t=0;
	while(t!=numbersSize-1)
	{
		if(numbers[t]+numbers[numbersSize-1]>target)
		{
			
			numbersSize--;
		}
		else if(numbers[t]+numbers[numbersSize-1]<target)
		{
			t++;
		}
		else
		{
			data[0]=t+1;
			data[1]=numbersSize;
			* returnSize=2;
			return data;
		}
	}
    return data;
}


```