### 解题思路
从1开始迭代

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
	if (n == 1) return "1";
	char primitive = '1';
	std::string list[2];
	list[0].push_back(primitive);
	short currentListIdx;
	short currentLength;
	char temp;
	char counter;
	for (int i = 0; i < n; i++)
	{
		currentListIdx = i % 2;
		currentLength = list[currentListIdx].size();
		temp = (list[currentListIdx])[0];

		short j = 0;
		counter = '0';
		list[(currentListIdx + 1) % 2].clear();

		while (j< currentLength)
		{
			if (temp ==(list[currentListIdx])[j])
			{
				counter++;
			}
			else
			{
				list[(currentListIdx + 1) % 2].push_back(counter);
				list[(currentListIdx + 1) % 2].push_back(temp);
				temp = (list[currentListIdx])[j];
				counter = '1';
			}
			
			j++;
		}
		list[(currentListIdx + 1) % 2].push_back(counter);
		list[(currentListIdx + 1) % 2].push_back(temp);
	}
	return list[currentListIdx];
    }
};
```