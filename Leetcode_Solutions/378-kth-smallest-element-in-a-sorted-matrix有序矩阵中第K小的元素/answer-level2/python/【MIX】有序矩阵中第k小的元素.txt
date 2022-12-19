### 解题思路
1. 暴力排序, 时间复杂度$NlogN$
2. 大顶堆优先队列, 时间复杂度$O(KlgK)$, 空间复杂度$O(K)$
3. 二分法

### 代码
**最小堆**
```c++ []
class Solution {
private:
    // 定义结构体, 重载比较符号
    typedef struct _P{
        int x;
        int y;
        int v;
        bool operator< (const _P& p) const{
            return v < p.v;
        }
        bool operator> (const _P& p) const{
            return v >= p.v;
        }
    }P;

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // BFS+优先队列
        // 小顶堆优先队列
        // pair<POS, VALUE>
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0, matrix[0][0]});
        R = matrix.size();
        C = matrix[0].size();
        vector<vector<bool>> vis = vector<vector<bool>>(R, vector<bool>(C, false));
        vis[0][0] = true;
        int res = 0;

        for(int i=0; i<k; ++i){
            P p = pq.top();
            pq.pop();
            for(auto d: dirs){
                int nx = p.x+d[0];
                int ny = p.y+d[1];
                
                if(inArea(nx, ny) && !vis[nx][ny]){
                    pq.push({nx, ny, matrix[nx][ny]});
                    vis[nx][ny] = true;
                }
            }
            res = p.v;
        }

        return res;
    }

private:
    bool inArea(int x, int y){
        return 0<=x && x<R && 0<=y && y<C;
    }

private:
    int R, C;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}};
};
```
```java []
public class Solution {
    private class Node{
        int x,y,v;
        Node(int x, int y, int v){
            this.x = x; this.y = y; this.v = v;
        }
    }
    public int kthSmallest(int[][] M, int k) {
        PriorityQueue<Node> q = new PriorityQueue<>((Node n1, Node n2)->(n1.v-n2.v));
        int count = 0;
        int[] dx = {0,1}, dy = {1,0};
        int ans = 0;
        int n = M.length, m = M[0].length;
        boolean[][] visited = new boolean[n][m];
        q.add(new Node(0,0,M[0][0] ));
        visited[0][0] = true;
        while(count < k){
            Node p = q.poll();
            for(int i= 0; i<2;i++){
                int x = p.x+dx[i];
                int y = p.y+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y]){
                    q.offer(new Node(x, y, M[x][y]));
                    visited[x][y] =true;
                }
            }
            ans = p.v;
            count++;
        }
        return ans;
    }
}
```
**二分法**
```python []
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        from bisect import bisect_right
        R, C = len(matrix), len(matrix[0])
        l, r = matrix[0][0], matrix[-1][-1]
        while l<r:
            mid = l+(r-l)//2
            cnt = 0
            # 第k小表示列表中的第k-1个元素, 
            for i in range(R):
                cnt += bisect_right(matrix[i], mid)
            print(cnt)
            if cnt < k:
                l = mid+1
            else:
                r = mid
        
        return l
```
```c++ []
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int R = matrix.size();
        int C = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[R-1][C-1];

        // binary search
        while(l < r){
            int mid = l+(r-l)/2;
            int cnt = 0;
            for(int i=0; i<R; ++i){
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid)-matrix[i].begin();
            }
            if(cnt < k)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};
```

**暴力排序**
```python []
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        R, C = len(matrix), len(matrix[0])
        arr = []
        for i in range(R):
            for j in range(C):
                arr.append(matrix[i][j])

        arr.sort()
        return arr[k-1]
```
**优先队列**
```python []
from queue import PriorityQueue as PQ
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        # 优先队列
        R, C = len(matrix), len(matrix[0])
        pq = PQ()
        for i in range(R):
            for j in range(C):
                pq.put((-matrix[i][j], matrix[i][j]))
                if pq.qsize() > k:
                    pq.get()

        return pq.get()[1]

```