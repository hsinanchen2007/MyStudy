### 解题思路

中间还有不能将1到n全部循环,会时间超时，从map的开始到end循环

### 代码

```cpp
class Solution {
public:
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		//sort(reservedSeats.begin(), reservedSeats.end());
		int result = 0;
		int pre = 0;
		int now = reservedSeats[0][0];
		unordered_map<int,int> seatBiaoJi;
		int left = 0b0111100000;
		int right = 0b0000011110;
		int middle = 0b0001111000;
		
		for (int i = 0; i < reservedSeats.size(); i++)
		{
			seatBiaoJi[reservedSeats[i][0]] = seatBiaoJi[reservedSeats[i][0]] | (1 << (10 - reservedSeats[i][1]));
		}
		unordered_map<int,int> ::iterator it = seatBiaoJi.begin();
		while (it != seatBiaoJi.end())
		{
			int temp = 0;
			if ((it->second & left) == 0)
				temp++;
			if ((it->second & right) == 0)
				temp++;
			if ((it->second & middle) == 0&& (it->second & left)!=0&& (it->second & right) != 0)
				temp++;
			temp = temp > 2 ? 2 : temp;
			result += temp;
			it++;
		}

		return result + (n - seatBiaoJi.size()) * 2;
	}
};
```