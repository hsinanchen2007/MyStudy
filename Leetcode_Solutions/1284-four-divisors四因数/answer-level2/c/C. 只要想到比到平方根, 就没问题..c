### 解题思路
加油......

### 代码

```c

int number_divisors(int num)
{
	int sum = 0, count = 0, m = sqrt(num);
	
	if(m*m == num)
	return 0;
	
	for(int i = 1; i <= m; i++)
	{
		if(num % i == 0)
		{
			sum += i + num/i;
			count += 2; 
		} 
		
		if(count > 4)
		break; 
	}
	
	return count == 4 ? sum : 0; 
}


int sumFourDivisors(int* nums, int numsSize)
{
	int sum = 0;
	
	for(int i = 0; i < numsSize; i++)
	{
		sum += number_divisors(nums[i]); 
	} 
	
	return sum;

}

```