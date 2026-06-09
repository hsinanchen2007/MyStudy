### 解题思路
做得很有一点麻烦，函数冗余，顺着我的思路如果有可以化简的地方请多多指正
1.找出最大的数和第二大的数，并将其下标分别赋值给maxin,secin。
2.如果maxin小于secin交换两个数位置
3.sum函数用来求U区域能装的水量
  maxindex函数用来求一段区域内的最大值和第二大值
用分治法分而治之，不断顺着每一区内中间的U字型向两边再找U字型。
不断嵌套。
sum(a, secin, maxin) + maxindex(a, low, secin+ 1) + maxindex(a, maxin, high)

### 代码

```cpp
class Solution {
public:

int sum(vector<int>& a, int low, int high)
{ 
	int sum = 0;
	int h = min(a[low], a[high]);
	sum = (high - low-1) * h;
	for (int i = low + 1; i < high ; i++)
	{
		sum -= a[i];
	}
	return sum;
}

int maxindex(vector<int>& a, int low, int high)
{
	if (high-low==1||high-low==2)return 0;
	int maxin = low;
	int secin = low;
	for (int i = low; i < high; i++)
	{
		if (a[i] > a[maxin])
		{
			secin = maxin;
			maxin = i;
		}
	}
	if (secin == maxin)
	{
		secin = low + 1;
		for (int i = low+1; i < high; i++)
		{
			
			if (a[i] > a[secin])
			{
				secin = i;
			}
		}

	}
	 
	if (maxin < secin)
	{
		int a = maxin;
		maxin= secin;
		secin= a;
	}
	return sum(a, secin, maxin) + maxindex(a, low, secin+ 1) + maxindex(a, maxin, high);
}

    int trap(vector<int>& height) {
	int n=height.size();
    if (n==0)
    return 0;
    else
	return maxindex(height, 0, n);
    }
   
        
};

```