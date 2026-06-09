使用stack数据结构来实现DFS遍历所有能进入的房间，取到钥匙说明指向的房间能进入，直接放入visited。

使用set visited来记录已经走过的房间，set内的元素不重复，且能查找某个元素是否存在于集合内。

注意：房间从第0开始。
```
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set <int> visited; //记录能进入的房间
        visited.insert(0); //从第0房间开始逛
        stack <int> keys; //记录房间里的钥匙
        keys.push(0); //DFS从这里开始--------------
        while(!keys.empty())
        {
            int key = keys.top(); //取出钥匙走向房间
            cout << key;
            keys.pop();
            int rs = rooms[key].size();
            for(int i = 0; i < rs; ++i) //给这个房间里的钥匙做记录，
            {
                if(!visited.count(rooms[key][i])) //若钥匙通向已知能进入的房间，就不再次不把这个钥匙放进口袋
                {
                    visited.insert(rooms[key][i]);
                    keys.push(rooms[key][i]); //把这个房间中自己还没有的钥匙放入口袋
                }
            }
        }
        return visited.size() == rooms.size(); //如果遍历过的房间数等于实际房间数，返回true
    }
};
```