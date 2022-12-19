### 解题思路
此处撰写解题思路
![1.png](https://pic.leetcode-cn.com/cbc943ab02d40cbccf5dc780493510398670c93524906dda74040e313df98505-1.png)
N行M列b个坏点
原本复杂度为 2^((N*M)/2)
压缩为层层处理 复杂度为  N * 2^(M)
本方法复杂度为 b^2

mtx 为地图，标记坏点为-2；
再在mtx上填一次骨牌
用一个数组记下未填骨牌的空点，不包括坏点
将空点通过移动骨牌两两合并
即可得到最大的填装状态
### 代码

```cpp
#define domino_debug
#undef domino_debug
class Solution {
	using point_t = vector<int>;
private:
	int n, m;
	const static size_t size = 8;
	int mtx[size][size];
	int road[size][size];

	void showMatrix(int (&mx)[size][size]) {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				cout.width(2);
				cout << mx[i][j] << ",";
			}
			cout << endl;
		}
		cout << "________________________________" << endl;
	}
public:
	int domino(int n, int m, vector<vector<int>>& broken) {
		if (broken.size() <= 0) { return n * m / 2; }
		init(n, m, broken);
#ifdef domino_debug
		fstream fs;
		fs.open("cout.txt", ios::out);
		cout.rdbuf(fs.rdbuf());
		cout << "init" << endl;
		showMatrix(mtx);
#endif // domino_debug

		
		vector<int> buff;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mtx[i][j] == -1) { buff.push_back(i*m+j); }
			}
		}
		int result = (n * m - broken.size() - buff.size()) / 2;
		for (int i = 0; i < buff.size();i++) {
			if (buff[i] < 0) { continue; }
			for (int j = i + 1; j < buff.size();j++) {
				if (buff[j]< 0) { continue; }
				int p1_r = buff[i] / m; int p1_c = buff[i] % m;
				int p2_r = buff[j] / m; int p2_c = buff[j] % m;
				if (!mergeToPoint(p1_r, p1_c, p2_r, p2_c)) { continue; }
#ifdef domino_debug
				cout << "change:(" << buff[i] / m << "," << buff[i] % m << ")(" << buff[j] / m << "," << buff[j] % m << ");" << endl;
				showMatrix(mtx);
#endif // domino_debug
				buff[i] = buff[j] = -1;
				result += 1;
				break;
			}
		}
		
#ifdef domino_debug
		//showMatrix(mtx);
		fs.close();
#endif // domino_debug

		return result;
	}


private:
	void init(int n, int m, vector<vector<int>>& broken) {
		this->n = n; this->m = m;
		const int flag = -1; const int bflag = -2;
		memset(mtx, flag, size * size * sizeof(int));
		memset(road, 0, size * size * sizeof(int));
		for (auto& p : broken) {
			mtx[p[0]][p[1]] = bflag;
		}
		vector<vector<int>> shade{ {0,1}, { 1,0 } };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (auto& sd : shade) {
					int nxI = i + sd[0];
					int nxJ = j + sd[1];
					if (inrow(nxI) && incol(nxJ) && mtx[i][j] == flag && mtx[nxI][nxJ] == flag) {
						mtx[i][j] = nxI * m + nxJ;
						mtx[nxI][nxJ] = i * m + j;
						break;
					}
				}
			}
		}
	}

	int odd(int x) {
		return x % 2;
	}
	int distance(int p1_r,int p1_c,int p2_r,int p2_c) {
		int difr = p1_r - p2_r;
		int difc = p1_c - p2_c;
		return difr * difr + difc * difc;
	}
	
	bool inrow(int x) {
		return 0 <= x && x < n;
	}
	bool incol(int x) {
		return 0 <= x && x < m;
	}

	bool mergeToPoint(int &p1_r, int &p1_c, int &p2_r, int &p2_c) {
		
		if (!(inrow(p1_r) && inrow(p2_r) && incol(p1_c) && incol(p2_c))) { return false; }
		if (odd(p1_r + p1_c) == odd(p2_r + p2_c)) { return false; }
		if (distance(p1_r, p1_c, p2_r, p2_c) == 1) { 
			mtx[p1_r][p1_c] = p2_r * m + p2_c;
			mtx[p2_r][p2_c] = p1_r * m + p1_c;
			return true;
		}
		int difc = p2_c - p1_c; int difr = p2_r - p1_r;
		double dirc = atan2(difr, difc);
		vector<vector<int>> opt{ {2,0} ,{1,1},{0,2},{-1,1},{-2,0},{-1,-1},{0,-2},{1,-1} };
		sort(opt.begin(), opt.end(), [&](vector<int>& a, vector<int>& b) {
			return abs(dirc - atan2(a[0], a[1])) < abs(dirc - atan2(b[0], b[1]));
		});
		for (auto& op : opt) {
			int dr = p1_r + op[0];
			int dc = p1_c + op[1];
			if (!(inrow(dr) && incol(dc))) { continue; }
			if (mtx[dr][dc] < 0) { continue; }
			if (road[dr][dc] == 1) { continue; }
			int id = mtx[dr][dc];
			int idr = id / m;
			int idc = id % m;
			if (distance(p1_r, p1_c, idr, idc) != 1) { continue; }
			road[p1_r][p1_c] = 1;
			mtx[idr][idc] = p1_r * m + p1_c; mtx[p1_r][p1_c] = idr * m + idc;
			mtx[dr][dc] = -1;
			int newp1_r = dr; int newp1_c = dc;
			bool ok = mergeToPoint(newp1_r, newp1_c, p2_r, p2_c);
			road[p1_r][p1_c] = 0;
			if (ok) {
				p1_r = newp1_r; p1_c = newp1_c;
				return true;
			}
			mtx[p1_r][p1_c] = -1;
			mtx[idr][idc] = dr * m + dc; mtx[dr][dc] = idr * m + idc;
		}
		return false;
	}

};
```