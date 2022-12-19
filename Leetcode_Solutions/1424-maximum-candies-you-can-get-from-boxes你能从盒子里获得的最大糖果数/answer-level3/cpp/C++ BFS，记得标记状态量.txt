个人感觉这道题目和上次167场周赛最后一题很相似，在普通的广度优先搜索的基础上引入新的状态。
首先我们考虑，如果没有钥匙的限制，是不是就是一道很普通的搜索题目了？只需要考虑我是否拥有盒子，寻常的bfs即可。
所以这道题其实状态量是二维的，分别是是否拥有盒子，是否拥有钥匙，可以考虑用vector<pair<bool,bool>>存储状态，当然用一维也是一样的。
下面贴代码：
```
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        //book标记当前盒子的状态，0代表未拥有且没钥匙，1代表已拥有且没钥匙，2代表未拥有且有钥匙，3代表已拥有且有钥匙
        vector<int> book(status.size(),0);
        for(int i=0;i<status.size();i++)
        {
            //默认打开的箱子视为未拥有，有钥匙
            if(status[i]==1)
                book[i]=2;
        }
        for(int i:initialBoxes)
        {
            if(status[i]==1)
                book[i]=3;
            else
                book[i]=1;
        }
        //visited标记已打开过的箱子，防止重复访问
        vector<bool> visited(status.size(),false);
        queue<int> q;
        //将所有一开始能打开的箱子入队
        for(int i=0;i<status.size();i++)
        {
            if(book[i]==3)
            {
                q.push(i);
                visited[i]=true;
            }
        }
        int count=0;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            //拿走里面的糖
            count+=candies[cur];
            //拿到所有当前盒子里的钥匙
            for(int j:keys[cur])
            {
                if(book[j]==0)
                    book[j]=2;
                if(book[j]==1)
                    book[j]=3;
            }
            //将其中的盒子标记为已出现
            for(int j:containedBoxes[cur])
            {
                if(book[j]==0)
                    book[j]=1;
                if(book[j]==2)
                    book[j]=3;
            }
            //将现在可以打开且没有访问过的盒子入队
            for(int i=0;i<status.size();i++)
            {
                if(book[i]==3&&!visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        return count;
    }
};
```
