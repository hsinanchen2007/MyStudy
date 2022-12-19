```
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z) return false;
        int curr = 0;
        int sum = x+y, a, b, c, d;
        unordered_set<int> visited = {curr};
        queue<int> bfs;
        bfs.push(curr);
        while(!bfs.empty())
        {
            curr = bfs.front();
            bfs.pop();
            if((a = curr-x)==z || (b = curr-y)==z || (c = curr+x)==z || (d = curr+y)==z) return true;
            if(a>0 && visited.insert(a).second) bfs.push(a);
            if(b>0 && visited.insert(b).second) bfs.push(b);
            if(c<sum && visited.insert(c).second) bfs.push(c);
            if(d<sum && visited.insert(d).second) bfs.push(d);
        }
        return false;
    }
};
```
