### 解题思路
找出所有矩形的上边和下边，并为它们的大小标序号，也就是离散化操作，接着对每个序号维护一个x方向上的区间，有些区间是矩形上边，有些是下边，对于每个不同的上边，更新该上边同一个y坐标的区间的并，该区间的并的长度乘以下一个上边或下边的纵坐标之差即为扫描过后的面积，对下边亦是如此。

### 代码

```cpp
class Solution {
public:
typedef long long LL;
map<int, int>mp;
map<int, int>mpx;
struct interv
{
	int a, b;
	int y;
	bool up;
};
vector<interv>intervs[410];
const int MX = 409;
int posi[410];
LL sum[4*409];
int idtoh[409];
int idtox[409];
int nod[409];
#define lson (rt<<1)
#define rson (rt<<1|1)
#define gmid (l+r>>1)
void pushup(int rt)
{
	sum[rt] = sum[lson] + sum[rson];
}
void update2(int L, int R, int l, int r, int rt, int val)
{
	if (l == r)
	{
		if (nod[l + 1] != 0&&l!=R)
			sum[rt] = idtox[l + 1] - idtox[l];
		else sum[rt] = 0;
		//cout << l << " " << sum[rt] << " " << val << endl;
		return;
	}
	int md = gmid;
	if (L <= md)update2(L, R, l, md, lson, val);
	if (R > md) update2(L, R, md + 1, r, rson, val);
	pushup(rt);
}
void update3(int L,int R, int l, int r, int rt,int val)
{
	if (l == r)
	{
		nod[l] += val;
		return;
	}
	int md = gmid;
	if (L <= md)update3(L,R, l, md, lson,val);
	if(R>md) update3(L,R, md + 1, r, rson,val);
	pushup(rt);
	//nod[L] += val;
	//nod[R] += val;
	//update2(L, R, l, r, rt, val);
}
    int rectangleArea(vector<vector<int>>& rectangles) {
    int sz = rectangles.size();
	for (int i = 0; i < sz; i++)
	{
		mp[rectangles[i][1]] = 1;
		mp[rectangles[i][3]] = 1;
		mpx[rectangles[i][0]] = 1;
		mpx[rectangles[i][2]] = 1;
	}
	int cnt = 1;
	for (auto&it : mp)
	{
		idtoh[cnt] = it.first;
		it.second = cnt++;
	}
	int ysz = cnt - 1;
	cnt = 1;
	for (auto&it : mpx)
	{
		idtox[cnt] = it.first;
		it.second = cnt++;
	}
	int xsz = cnt-1;
	interv tp;
	for (int i = 0; i < sz; i++)
	{
		tp.a = mpx[rectangles[i][0]];
		tp.b = mpx[rectangles[i][2]];
		tp.up = false;
		tp.y = rectangles[i][1];
		intervs[mp[rectangles[i][1]]].push_back(tp);
		tp.up = 1;
		tp.y = rectangles[i][3];
		intervs[mp[rectangles[i][3]]].push_back(tp);
	}
	LL res = 0;
	for (int i = 1; i < ysz; i++)
	{
		for (int j = 0; j < intervs[i].size(); j++)
			if (intervs[i][j].up)
				update3(intervs[i][j].a+1, intervs[i][j].b, 1, xsz, 1, -1);
		for (int j = 0; j < intervs[i].size(); j++)
			if (intervs[i][j].up)
				update2(intervs[i][j].a, intervs[i][j].b, 1, xsz, 1, -1);
		for (int j = 0; j < intervs[i].size(); j++)
			if(!intervs[i][j].up)
				update3(intervs[i][j].a+1, intervs[i][j].b, 1, xsz, 1, 1);
		for (int j = 0; j < intervs[i].size(); j++)
			if (!intervs[i][j].up)
				update2(intervs[i][j].a, intervs[i][j].b, 1, xsz, 1, 1);
		update2(1, xsz, 1, xsz, 1, 1);
	//	for (int j = 1; j <= xsz; j++)cout << nod[j] << " ";
	//	cout << endl;
		res += (LL)sum[1] * (LL)(idtoh[i + 1] - idtoh[i]);
		//cout << sum[1] << " " << (idtoh[i + 1] - idtoh[i]) << endl;
		//cout << sum[1] << endl;
	}
    int mod=1e9+7;
	return res%mod;
    }
};
```