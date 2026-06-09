### 解题思路
列举各种情况BFS即可

### 代码

```cpp
class Solution {
public:
	bool canMeasureWater(int x, int y, int z){
		if (z > x + y){
			return false;
		}
		map<pair<int, int>, int> mp;
		vector<pair<int, int>> queue;
		pair<int, int> p(0, 0);
		if (p.first == z || p.second == z || (z == p.first + p.second)){
			return true;
		}
		queue.push_back(p);
		mp[p] = 1;
		p.first = x;
		p.second = 0;
		if (p.first == z || p.second == z || (z == p.first + p.second)){
			return true;
		}
		queue.push_back(p);
		mp[p] = 1;
		p.first = 0;
		p.second = y;
		if (p.first == z || p.second == z || (z == p.first + p.second)){
			return true;
		}
		queue.push_back(p);
		mp[p] = 1;
		for (int i = 0; i < queue.size(); i++){
			pair<int, int> p1 = queue[i];
			//1.第一个倒空
			p1.first = 0;
			if (p1.first == z || p1.second == z || (z == p1.first + p1.second)){
				return true;
			}
			if (mp.find(p1) == mp.end()){
				queue.push_back(p1);
				mp[p1] = 1;
			}
			//2.第一个装满
			p1.first = x;
			if (p1.first == z || p1.second == z || (z == p1.first + p1.second)){
				return true;
			}
			if (mp.find(p1) == mp.end()){
				queue.push_back(p1);
				mp[p1] = 1;
			}
			//3.第一个向第二个倒
			p1 = queue[i];
			if (p1.first > y - p1.second){
				p1.first -= (y - p1.second);
				p1.second = y;
				if (p1.first == z || p1.second == z || (z == p1.first + p1.second)){
					return true;
				}
				if (mp.find(p1) == mp.end()){
					queue.push_back(p1);
					mp[p1] = 1;
				}
			}
			else {
				p1.second += p1.first;
				p1.first = 0;
				if (p1.first == z || p1.second == z || (z == p1.first + p1.second)){
					return true;
				}
				if (mp.find(p1) == mp.end()){
					queue.push_back(p1);
					mp[p1] = 1;
				}
			}
			//4.第二个倒空
			p1 = queue[i];
			p1.second = 0;
			if (p1.first == z || p1.second == z || (z == p1.first + p1.second)){
				return true;
			}
			if (mp.find(p1) == mp.end()){
				queue.push_back(p1);
				mp[p1] = 1;
			}
			//5.第二个装满
			p1 = queue[i];
			p1.second = y;
			if (p1.first == z || p1.second == z || (z == p1.first + p1.second)){
				return true;
			}
			if (mp.find(p1) == mp.end()){
				queue.push_back(p1);
				mp[p1] = 1;
			}
			//6.第二个向第一个倒
			p1 = queue[i];
			if (p1.second > y - p1.first){
				p1.second -= (y - p1.first);
				p1.first = x;
				if (p1.first == z || p1.second == z || (z == p1.first + p1.second)){
					return true;
				}
				if (mp.find(p1) == mp.end()){
					queue.push_back(p1);
					mp[p1] = 1;
				}
			}
			else {
				p1.first += p1.second;
				p1.second = 0;
				if (p1.first == z || p1.second == z || (z == p1.first + p1.second)){
					return true;
				}
				if (mp.find(p1) == mp.end()){
					queue.push_back(p1);
					mp[p1] = 1;
				}
			}
		}
		return false;
	}
};
```