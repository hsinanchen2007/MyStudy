# 思路都在注释里了
在时间和内存上优化了很久

```c++
class Solution {
public:
	Solution() {}
	int minJumps(vector<int>& arr) {
		int n = arr.size();
		unordered_map<int, vector<unsigned short> > mp;//存储值为int的所有数组下标vector<unsigned short>，选择unsignedshort是因为下标范围是0到50000
		for (int i = 0; i < n; ++i) {
			mp[arr[i]].push_back(i);//记录相同值的下标集合
		}
		unordered_map<int, bool> searched;//看某个值有没有被搜索过
		queue<int> que;
		que.push(0);
		int step = 0;
		/*广度优先遍历*/
		while (!que.empty()) {
			int cursize = que.size();
			for (int i = 0; i < cursize; ++i) {
				int tmp = que.front();//出队
				que.pop();
				
				if (tmp == n - 1) return step;
				//可达点分为三种情况
				/*左邻居*/
				if (tmp - 1 >= 0 && searched[arr[tmp - 1]] == false) {
					que.push(tmp - 1);
				}
				/*右邻居*/
				if (tmp + 1 < n && searched[arr[tmp + 1]] == false) {
					que.push(tmp + 1);
				}
				/*同值可达点*/
				if (searched[arr[tmp]] == false) {
					vector<unsigned short>* tmp_pointer = &mp[arr[tmp]];//记下指针有利于提高速度，不然每次下标访问都要查找
					for (int j = 0; j < tmp_pointer->size(); ++j) {
						if ((*tmp_pointer)[j] != tmp - 1 && (*tmp_pointer)[j] != tmp + 1) {
							que.push((*tmp_pointer)[j]);
						}
					}
					searched[arr[tmp]] = true;//访问该点，意味着所有同值可达点均被访问过，不会有第二次找同值可达点的机会
				}
			}
			++step;
		}
		return step;
	}
};
```