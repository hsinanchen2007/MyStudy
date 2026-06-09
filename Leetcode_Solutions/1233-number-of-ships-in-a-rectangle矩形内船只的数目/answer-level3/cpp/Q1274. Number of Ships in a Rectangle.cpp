### 分治
将`[bottomLeft, topRight]`所包括的矩形区域进行二分，横着划分或者竖着划分都行，递归调用计算船舶的总数。那么，`nCountShips = nLeftCountShips + nRightCountShips = nTopCountShips + nBottomCountShips`。如果矩形区域内没有船，则返回0；如果有船，则递归求解；如果不能进行二分了，则返回1（该整数点有一艘船）。
```
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
	int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
		if (!sea.hasShips(topRight, bottomLeft))
			return 0;

		int nCountShips = 0;
		if (topRight[0] > bottomLeft[0]) {
			// 按横坐标划分成左右两部分
			int nMidX = (bottomLeft[0] + topRight[0]) / 2;
			vector<int> newTopRight;
			newTopRight.push_back(nMidX);
			newTopRight.push_back(topRight[1]);

			vector<int> newBottomLeft;
			newBottomLeft.push_back(nMidX + 1);
			newBottomLeft.push_back(bottomLeft[1]);

			nCountShips = countShips(sea, newTopRight, bottomLeft) + countShips(sea, topRight, newBottomLeft);
		}
		else if (topRight[1] > bottomLeft[1]) {
			// 按纵坐标划分成上下两部分
			int nMidY = (bottomLeft[1] + topRight[1]) / 2;
			vector<int> newTopRight;
			newTopRight.push_back(topRight[0]);
			newTopRight.push_back(nMidY);

			vector<int> newBottomLeft;
			newBottomLeft.push_back(bottomLeft[0]);
			newBottomLeft.push_back(nMidY + 1);

			nCountShips = countShips(sea, newTopRight, bottomLeft) + countShips(sea, topRight, newBottomLeft);
		}
		else {
			// 该整数点有一艘船
			nCountShips = 1;
		}

		return nCountShips;
	}
};
```
我果真不适合写题解，写文章啊！