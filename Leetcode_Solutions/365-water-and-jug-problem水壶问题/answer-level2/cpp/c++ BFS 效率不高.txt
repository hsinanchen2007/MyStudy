### 解题思路
此处撰写解题思路
BFS,六种情况扩展，集合记录已经遍历过的状态。
pair作为unordered_set时遇到一些问题，顺利解决：加上结构体，自定义hash函数。
### 代码

```cpp
class Solution {
public:
struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};
    bool canMeasureWater(int x, int y, int z) {
        std::pair<int,int>init(0,0);
        std::unordered_set<std::pair<int,int>, pair_hash>lmh;
        lmh.emplace(init);
        std::queue<pair<int,int>>que;
        que.push(init);
        while(que.size()>0) {
            std::pair<int,int>cur = que.front();
            que.pop();
            std::pair<int,int>expa[6];
            expa[0] = std::pair<int,int>(std::max(cur.first+cur.second-y,0),std::min(y,cur.first+cur.second));
            expa[1] = std::pair<int,int>(std::min(cur.first+cur.second,x),std::max(0,cur.first+cur.second-x));
            expa[2] = std::pair<int,int>(0, cur.second);
            expa[3] = std::pair<int,int>(cur.first,0);
            expa[4] = std::pair<int,int>(x,cur.second);
            expa[5] = std::pair<int,int>(cur.first,y);
            for(std::pair<int,int>exp:expa) {
                if(exp.first==z||exp.second==z||exp.first+exp.second==z) {
                    return true;
                }
                if(lmh.find(exp)==lmh.end()) {
                    lmh.emplace(exp);
                    que.push(exp);
                }
            }
        }
        return false;
    }
};
```