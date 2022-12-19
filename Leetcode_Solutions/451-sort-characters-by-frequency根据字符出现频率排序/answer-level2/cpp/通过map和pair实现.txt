### 解题思路
通过map记录每个字母的次数，再通过pair与优先队列实现降序排列。

### 代码

```cpp
class Solution {
public:
    string frequencySort(string s) {
        string str;
        map<char, int> map;
        pair<int, char> p;
        pair<int, char> pi;
        priority_queue<pair<int, char> > pq;
        for(char x : s)
        {
            map[x]++;
        }
	    for (auto it = map.begin(); it != map.end(); it++)
        {
            p = make_pair(it->second, it->first);//按频率进行排序即it->second
		    pq.push(p);
        }
        int len = pq.size();
        for(int i = 0; i < len; i++)
        {
            pi = pq.top();
            for(int a = 0; a < pi.first; a++)
                str += pi.second;
            pq.pop();
        }
        return str;
    }
};
```