按道理讲，用了两层循环应该不是高效的算法，但是提交结果却击败了100%用户，搞得我凌乱了...

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了14.08%的用户

### 代码

```cpp
class Solution {
public:
	int addDigits(int num) 
	{
		int sum ;
		do {
           		sum=0;
			while (num != 0)
			{
				sum += (num % 10);
				num = num / 10;
			}
			num = sum;
		} while (sum >= 10);
		return sum;
	
	}
};
```