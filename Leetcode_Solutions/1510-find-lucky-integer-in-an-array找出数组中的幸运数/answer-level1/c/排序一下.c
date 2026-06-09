### 解题思路
此处撰写解题思路

### 代码

```c
int findLucky(int arr[],int n)   
{
	int temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	int count=1;
	int i;
	for(i=n-1;i>0;i--) //记录次数 
	{
		if(arr[i]==arr[i-1])
		{
			count++;
		}
	    else
	    {
	    if(count==arr[i])
			{
				return count;
			}
			else
			{
				count=1;
			}	
		}		
	}
	
	if(count==arr[i])
	{
		return count;
	}
	else
	{
		return -1;
	}	
} 

```

//把数组从小到大排序，然后从后往前遍历，设置个count=1用来记录出现次数，a[i]==a[i-1]则出现次数+1，不相等就判断count是否等于a[i]，等于就直接返回count值，不等于则count=1，继续遍历