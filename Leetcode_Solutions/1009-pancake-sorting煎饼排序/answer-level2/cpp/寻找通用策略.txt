### 解题思路
有一个通用的策略，就是先从1所在位置翻转，这时1的位置在数组头，接着再将前size个元素翻转，使1到数组尾部，接着从2所在位置翻转，这时2的位置在数组头，接着再将前size-1个元素翻转，使2到数组倒数第二个，接着从3所在位置翻转，这时3的位置在数组头，接着再将前size-2个元素翻转，使3到数组倒数第三个，以此类推，直到数组呈现n，n-1，n-2，...,1时，再将数组的前size项翻转，就可以得到最终结果了，返回数组大小<=2*A.length()+1;

### 代码

```cpp
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
    vector<int>re;
    if(A.size()==1)
    return re;
    int size = A.size();
	int* numToPos = new int[size];
	for (int i = 0; i < A.size(); i++)
	{
		A[i]--;
		numToPos[A[i]] = i;
	}
	for (int i = 0; i < size; i++)
	{
		if (numToPos[i] == size - 1 - i)
			continue;
		else if (numToPos[i] == 0)
		{
			re.push_back(size-i);
			for (int j = 0; j <= (size-i-1)/2; j++)
			{
				int temp = A[j];
				A[j] = A[(size - i - 1) - j];
				A[(size - i - 1) - j] = temp;
				numToPos[A[j]] = j;
				numToPos[A[(size - i - 1) -j]] = (size - i - 1) -j;
			}
		}
		else
		{
			re.push_back(numToPos[i] + 1);
			re.push_back(size-i);
			int firstChange = numToPos[i];
			for (int j = 0; j <= firstChange / 2; j++)
			{
				int temp = A[j];
				A[j] = A[firstChange - j];
				A[firstChange - j] = temp;
				numToPos[A[j]] = j;
				numToPos[A[firstChange - j]] = firstChange- j;
			}
			for (int j = 0; j <= (size - i - 1) / 2; j++)
			{
				int temp = A[j];
				A[j] = A[(size - i - 1) - j];
				A[(size - i - 1) - j] = temp;
				numToPos[A[j]] = j;
				numToPos[A[(size - i - 1) - j]] = (size - i - 1) - j;
			}
		}
	}
	re.push_back(size);
     return re;
    }
};
```