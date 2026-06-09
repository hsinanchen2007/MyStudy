### 解题思路
先排序，在维护左右指针,对数组进行一次遍历，每次要么右指针与左指针同时向中靠拢，要么只有右指针向中靠拢，直到两指针重合，复杂度为O(nlogn)+O(n).

### 代码

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    int size = people.size();
	sort(&people[0], &people[0] + size);
	int left = 0;
	int right = size - 1;
	int result = 0;
	while (left <= right)
	{
        if(left!=right)
		if (people[left] + people[right] <= limit)
		{
			result++;
			left++, right--;
		}
		else
		{
			result++;
			right--;
		}
        else 
        {
            result++;
            left++;
            right--;
        }
	}
	return result;
    }
};
```