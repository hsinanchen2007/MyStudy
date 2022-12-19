class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        //看来这道题对于时间的要求不高;
     map<int, vector<int>> map1;//储存蓝色边;
		map<int, vector<int>> map2;//储存红色边;
		map<int, int> map3;//记录当前结点所在层次;
		vector<int> ans(n,-1);
		//使用邻接表的形式储存边;
		for (int i = 0; i < red_edges.size(); i++) {
			map1[red_edges[i][0]].push_back(red_edges[i][1]);
			//加入连接点;
		}
		for (int i = 0; i < blue_edges.size(); i++) {
			map2[blue_edges[i][0]].push_back(blue_edges[i][1]);
		}
		ans[0] = 0;
		queue<int> queue1;//说明要加入红色边;
		queue1.push(0);//加入起点;
		queue<int> queue2;//说明要加入蓝色边;
		queue2.push(0);//加入起点;
		int level = 0;
		//不需要使用相同的边，即可保证路径是最短的;
		while (!queue1.empty() || !queue2.empty()) {
			level++;//当前层次;
			int size = queue1.size();
			int size1 = queue2.size();
			//需要加入红边;
			for (int i = 0; i < size; i++) {
				auto it_pre = queue1.front();
				queue1.pop();
				for (auto it : map2[it_pre]) {
					   // map2[it_pre].erase(map2[it_pre].begin());
						queue2.push(it);
						if (ans[it]==-1) ans[it] = level;
					
				}
                map2[it_pre].clear();//同下;
			}
			for (int i = 0; i < size1; i++) {
				//需要加入蓝边;
				auto it_pre = queue2.front();
				queue2.pop();
				for (auto it : map1[it_pre]) {
					    //map1[it_pre].erase(map1[it_pre].begin());
						queue1.push(it);
						if (ans[it] == -1) ans[it] = level;
					
				}
                map1[it_pre].clear();//避免重复，这些结点全部通过蓝边访问过了;
			}
		}
		return ans;
    }
};