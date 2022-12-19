### 解题思路
如注释

### 代码

```cpp
class Solution {
public:
int all;
int step;
int m;
int n;
int getsumbit(int num)
{
	return num%10 + num/10;//二位数不需要循环算
}
void dfs(bool status[][100], int x, int y)
{
	if (x < 0 || x >= m || y < 0 || y >= n || status[x][y] || getsumbit(x) + getsumbit(y) > all)
		return;

	++step;
	status[x][y] = true;
	//dfs(status, x - 1, y);
	dfs(status, x + 1, y);
	//dfs(status, x, y - 1);//这两行是可以省的..因为起点是0,0 ,不需要往回走
	dfs(status, x, y + 1);
}
int movingCount(int mm, int nn, int k) 
{
    m=mm;
    n=nn;
	all = k;
	step = 0;
	bool status[100][100] = { 0 };//用int在vs上好像会提示栈溢出,,bool就够了
	dfs(status, 0, 0);

	return step;
}
};
```