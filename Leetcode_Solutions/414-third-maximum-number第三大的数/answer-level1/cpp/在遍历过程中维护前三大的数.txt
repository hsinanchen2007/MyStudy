### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
    auto firstmax = nums.begin();
	auto secmax = nums.begin();
	auto thirdmax = nums.begin();

	for (auto iter = nums.begin(); iter != nums.end(); iter++)
	{
		if ((firstmax == secmax) || (firstmax == thirdmax) || (secmax == thirdmax))
		{
			if (*iter > *firstmax)
			{
				if (firstmax != secmax)
				{
					thirdmax = secmax;
					secmax = firstmax;
					firstmax = iter;
				}
				else
				{
					firstmax = iter;
				}

			}
			else if (*iter < *thirdmax)
			{
				if (firstmax == secmax)
					secmax = thirdmax;
				thirdmax = iter;

			}
			else if ((*iter < *firstmax))
			{
				if(firstmax==secmax)
				{
					if (*iter > *thirdmax)
					{
						secmax = iter;
					}
					else if(*iter < *thirdmax)
					{
						thirdmax = secmax;
						secmax = iter;
					}
				}
				else if (secmax == thirdmax)
				{
					if (*iter > *secmax)
					{
						secmax = iter;
					}
					else if(*iter < *secmax)
					{
						thirdmax = iter;
					}
				}
				
			}
		}
		else
		{
		if (*iter > *firstmax)
		{
			thirdmax = secmax;
			secmax = firstmax;
			firstmax = iter;
		}
		else if ((*iter < *firstmax))
		{
			if (*iter > *secmax)
			{
				thirdmax = secmax;
				secmax = iter;
			}
			else if (*iter < *secmax)
			{
				if (*iter > *thirdmax)
				{
					
					thirdmax = iter;
				}
			}

			
		}
		}
	}

	if ((firstmax != secmax) && (firstmax != thirdmax) && (secmax != thirdmax))
	{
		return (*thirdmax);
	}
	else
	{
		return (*firstmax);
	}
        }
};
```