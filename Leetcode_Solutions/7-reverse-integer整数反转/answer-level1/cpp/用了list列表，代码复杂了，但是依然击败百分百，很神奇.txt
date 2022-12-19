### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int reverse(int x) {
		list<int> a;
		int y = x, z = 1;
		while (y != 0) 
		{
			z = y % 10;
			if (y != 0) 
			{
				a.push_back(z);
			}
            y = y / 10;
			
		}
		x = 0;
		while (!a.empty()) 
		{
            if (x>INT_MAX/10 or x<INT_MIN/10)
			{
                return 0;
            }
			x = x * 10 + a.front();
			a.pop_front();
		}

		return x;

	}
};

```