### 解题思路
并查集模板题。将二维坐标映射到一维坐标就可以用并查集了。映射关系（x，y）->x*w+y
其中x为横坐标，y为纵坐标。
![image.png](https://pic.leetcode-cn.com/375bff8c53b4d87d4842a7f56e98a0f7b32fc9c904f3122e592be584e6c3013e-image.png)


### 代码

```cpp
class Solution {
public:
int f[250005];
int sz;
void init(){
	for (int i = 0; i < sz; i++)
		f[i] = i;
	f[250004] = 250004;//由于250004永远接触不到
}
int find(int x){
	return (x == f[x] ? x : f[x] = find(f[x]));
}
void merge(int x, int y){
	f[find(y)] = find(f[x]);
}
int isolate = 250004;
    int numEnclaves(vector<vector<int>>& A) {
        if(A.size()==1||A[0].size()==1)
        return 0;
    int w = A[0].size();
	int h = A.size();
    sz=w*h;
    init();
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
            if(!A[i][j])continue;
			if (i == 0 || i == h - 1)
				merge(isolate, i*w + j);
			else {
				if (i != 0&&A[i-1][j])
					merge(i*w + j, (i - 1)*w + j);
				if (i != h - 1 && A[i + 1][j])
					merge(i*w + j, (i + 1)*w + j);
			}
			if (j == 0 || j == w - 1)
				merge(isolate, i*w + j);
			else {
				if (j != 0 && A[i][j - 1])
					merge(i*w + j, i*w + j - 1);
				if (j != w - 1 && A[i][j + 1])
					merge(i*w + j, i*w + j + 1);
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (find(i*w + j) != find(isolate)&&A[i][j])
				cnt++;
    return cnt;
    }
};
```