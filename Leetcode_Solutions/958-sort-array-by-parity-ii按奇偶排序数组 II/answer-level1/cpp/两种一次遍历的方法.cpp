**方法一：
一次遍历，分别将奇数和偶数置于对应的位置。
**

```
vector<int> sortArrayByParityII(vector<int>& A)
{
	vector<int> v(A.size());
	int a = 0;
	int b = 1;

	for (vector<int>::iterator it = A.begin();it!=A.end();it++)
	{
		if (*it % 2 == 0)
		{
			v[a] = *it;
			a = a + 2;
		}
		if (*it % 2 == 1)
		{
			v[b] = *it;
			b = b + 2;
		}
	}
	return v;
}
```



方法二：


```
vector<int> sortArrayByParityII(vector<int>& A) {
	for (int i = 0; i < A.size(); i++)
	{
		int temp = i;
		while (true)
		{
			if (i % 2 != A[temp] % 2)
			{
				temp++;
			}
			else
			{
				if (i != temp)
				{
					swap(A[i], A[temp]);
				}
				break;
			}
		}
	}
	return A;
}
```





