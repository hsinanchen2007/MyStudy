### 解题思路
1、按位判断
判断每一位是否为
2、N&N-1 
一个数n与一个比它小1的数(n-1)与(&)运算，会消除n中最低位的1

### 代码
#### 按位判断
```cpp
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count=0;
		for (int i=0;i<32;i++)
		{
			int t = 1 << i;
			if (t & n) count++;
		}
		return count;
	}
};
```

#### N&N-1
```cpp
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n!=0)
		{
			n &= n - 1;
			count++;
		}
		return count;
	}
};
```