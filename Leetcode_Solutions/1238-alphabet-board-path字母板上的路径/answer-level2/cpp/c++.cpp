```
class Solution {
public:
    string alphabetBoardPath(string target) {
        int curX = 0;
		int curY = 0;
		if (target.empty()) return string{};
		
		string strResult = "";
		for (size_t i = 0; i < target.length(); ++i)
		{
			int tarY = (target.at(i) - 'a') / 5;
			int tarX = (target.at(i) - 'a') % 5;

			int difX = tarX - curX;
			int difY = tarY - curY;

			if (difX == 0 && difY == 0)
			{
				strResult.push_back('!');
				continue;
			}

			bool tarIsZ = false;		
			if (tarX == 0 && tarY == 5)
			{
				difY--;
				tarIsZ = true;
			}

			for (size_t j = 0; j < abs(difY); j++)
			{
				strResult.push_back(difY > 0 ? 'D' : 'U');
			}

			for (size_t j = 0; j < abs(difX); j++)
			{
				strResult.push_back(difX > 0 ? 'R' : 'L');
			}

			if (tarIsZ)
			{
				strResult.push_back('D');
			}

			strResult.push_back('!');

			curX = tarX;
			curY = tarY;
		}

		return strResult;
    }
};
```
![QQ截图20191206164220.png](https://pic.leetcode-cn.com/b54599e409760234fdbfd1ba80365465433ce4fbba566f7cd3b1a393d8214ffd-QQ%E6%88%AA%E5%9B%BE20191206164220.png)

