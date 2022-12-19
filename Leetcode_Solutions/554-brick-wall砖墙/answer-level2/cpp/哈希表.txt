### 解题思路
利用map记录每一行的空隙，然后在遍历的时候记录出最大的空隙层数，最后返回总层数减去最大的空隙层数。

### 代码

```cpp
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<unsigned int, int> wallTimes;
		int wallLength = 0;
		for (int i = 0; i < wall.size(); i++) {
            unsigned int lastLength = 0;
			for (int j = 0; j < wall[i].size() - 1; j++) {
                lastLength += wall[i][j];
				if (wallTimes.find(lastLength) == wallTimes.end()) {
					wallTimes[lastLength] = 1;
				} else {
					wallTimes[lastLength]++;
				}
				wallLength = max(wallTimes[lastLength], wallLength);
			}
		}
		return (wall.size() - wallLength);
    }
};
```