用一个vector标记房间状态，1为解锁，0 为未解锁
在一个队列中放入钥匙，然后弹出钥匙的同时打开对应的房间，把在新打开房间找到的钥匙放入袋子中（重复的不放，因为我们有一个计数器，在队列弹出钥匙的时候计算已经打开的房间数量，要是重复放入相同的钥匙计数器会出错）
结束条件：当队列已经空了的时候，看看打开的房间数目是否等于房间总数
```
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size()-1; //n为未打开房间数量，0号房间一开始就是打开的，所以减1
        vector<int> keys(n+1,0);
        keys[0]=1; //第一个房间本来就是可以打开的
        queue<int> unlocked;
        for(int a: rooms[0])
        {
            if(keys[a]==0){ //如果已经有了一个房间的钥匙，就不要重复放入，因为看到用例里面有[[1,1],[]]这样的例子
                keys[a]=1;
                unlocked.push(a);
                n--;
            }
            
        }
        while(!unlocked.empty()){
            int b=unlocked.front();
            unlocked.pop();
            for(int c: rooms[b])
            {
                if(keys[c]==0)
                {
                    keys[c]=1;
                    unlocked.push(c);
                    n--;
                }
            }
        }
        return n==0;
        
    }
};
```
