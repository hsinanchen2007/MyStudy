### 解题思路
1.放入所有0到队列中
2.然后对每个0的外围进行更新，此时会出现一个问题，外围的点满足什么条件要放入对列。答案是只要dist[x1][y1]>dist[x0][y0]+1就放入。为什么呢？当碰到dist[x1][y1]<=dist[x0][y0]+1的时，有两种可能，一是（x0,y0）和（x1,y1）由同一个0拓展来的那么（x0,y0）已经被放入过队列。二是（x1,y1）由别的0拓展而来也被放入过队列。而且当dist[x1][y1]<=dist[x0][y0]+1时dist[x1][y1]一定是正确的值，因为每个点（x,y）都是由0拓展来的，dist[x1][y1]<=dist[x0][y0]+1说明(x1,y1)在（x0,y0）接触他之前就已经被别的点接触了，别的点能先接触到他说明她离那个0更近。
3.简单点说：大海里有4个岛，每天给每个岛外围填一圈土方块（mc）并将这些新填的土方块的坐标入栈，以便明天在这些坐标的基础上继续填下一圈。dist[x1][y1]>dist[x0][y0]+1就说明这些x1,y1之前没被填土方块,反之被填过。最终这些岛的外围会相遇，相遇时并不会相互更新distance，因为他们的distance都是正确的，是到0最短的距离，原因是以每个0为圆心一圈圈画圆他所属的0最先画到他。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> matrix) {
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
        queue<pair<int,int>>q;
        //找到所有的0放入队列
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    dist[i][j]=0;
                    q.push(make_pair(i,j));
                }
            }
        }
        int offset[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        pair<int,int>temp;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x1=temp.first+offset[i][0],y1=temp.second+offset[i][1];
                if(x1>=0&&x1<row&&y1>=0&&y1<col){
                    if(dist[x1][y1]>dist[temp.first][temp.second]+1){
                        dist[x1][y1]=dist[temp.first][temp.second]+1;
                        q.push(make_pair(x1,y1));//如果这个点的distance被更新放入队列
                    }
                }
            
            }
        }
        return dist;
    }

};

```