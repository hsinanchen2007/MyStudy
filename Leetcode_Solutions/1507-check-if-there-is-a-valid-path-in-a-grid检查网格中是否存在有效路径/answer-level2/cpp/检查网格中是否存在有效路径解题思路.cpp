### 解题思路
此处撰写解题思路
1.用二维坐标表示 位置  和方向
2.定义上下左右四个方向
3.初始化原始方向，这里注意  第四种street有2个方向。
4.根据上一个方向以及street类型，枚举判断出能不能到达这个street，从而获得下一个方向，否则就获得0向量
	当一个人从按一个方向过来，人可以到达哪几种street，从而简化了street之间的通行匹配
5.位置+方向又可以推导出下一个位置，判断方向是否为0向量以及位置是否越界或者到达目的地 ，从而得出结果
### 代码

```cpp
struct vector2 {
	int mx;
	int my;
	vector2() {}
	vector2(int x,int y) {
		mx = x;
		my = y;
	}
	bool operator==(const vector2& v2) {
		return this->mx == v2.mx&& this->my == v2.my;
	}
	vector2 operator+(const vector2& v2) {
		return vector2(this->mx+v2.mx,this->my+v2.my);
	}


};


class Solution {
private:
	vector2 mleft;
	vector2 mright;
	vector2 mup;
	vector2 mdown;

public:
	Solution() {
		mleft=vector2(0, -1);
		mright= vector2(0, 1);
		mup= vector2(-1, 0);
		mdown= vector2(1, 0);
	}
	bool hasValidPath(vector<vector<int>>& grid) {
		if (grid.size() == 0)return true;
		if (grid.size() == 1&&grid[0].size() == 1)return true;
		vector<vector2> thisdirs;
		switch (grid[0][0]) {
		case 1:
		case 6:thisdirs.push_back(mright);break;
		case 2:
		case 3:thisdirs.push_back(mdown);break;
		case 4:
			thisdirs.push_back(mright);
			thisdirs.push_back(mdown);
			break;
		default:break;
		}

		for (auto it = thisdirs.begin();it < thisdirs.end();it++) {
			vector2 thispos(0, 0);
			auto dir = *it;
			while (!(dir == vector2(0, 0)))
			{
				if (thispos.mx == grid.size() - 1 && thispos.my >= grid[0].size() - 1)return true;
				vector2 nextpos = thispos + dir;
				if (nextpos.mx < 0 || nextpos.mx >= grid.size() || nextpos.my < 0 || nextpos.my >= grid[0].size())break;
				dir = getNextDir(grid[nextpos.mx][nextpos.my], dir);
				thispos = nextpos;
			}
		}
		
		return false;
	}

	vector2 getNextDir(int streettype,vector2 lastdir) {
		if (lastdir ==mleft) {
			switch (streettype)
			{
			case 1:return mleft;
			case 4:return mdown;
			case 6:return mup;
			default:
				break;
			}
		}
		else if (lastdir == mright) {
			switch (streettype)
			{
			case 1:return mright;
			case 3:return mdown;
			case 5:return mup;
			default:
				break;
			}
		}
		else if (lastdir == mup) {
			switch (streettype)
			{
			case 2:return mup;
			case 3:return mleft;
			case 4:return mright;
			default:
				break;
			}
		}
		else if(lastdir == mdown) {
			switch (streettype)
			{
			case 2:return mdown;
			case 5:return mleft;
			case 6:return mright;
			default:
				break;
			}
		}

		return vector2(0, 0);

	}


};
```