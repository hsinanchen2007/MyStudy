DFS,针对每个学生利用深度优先搜索直接朋友,并赋Mark数组表示已访问。java实现
```
class Solution {
    public int findCircleNum(int[][] M) {
        int ans = 0, N = M.length;
        int[] mark = new int[N];
        for(int i = 0; i < N; i++){
            if(mark[i] == 0){
                ans++;
                DFS(M,mark,i,N);
            }
        }
        return ans;
    }
    
    public void DFS(int[][] M, int[] mark, int si, int N){
        mark[si] = 1;
        for(int j = 0; j < N; j++){
            if(M[si][j] == 1 && mark[j] == 0){
                DFS(M,mark,j,N);
            }
        }
    }
}
```
并查集，开始时有N个学生，每个学生为一个朋友圈 circles[i]表示所有学生i所属的朋友圈，将是直接朋友且不属于同一个朋友圈的学生合并到同一个朋友圈
```
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size(), ans = N;
        vector<int> circles;
        for(int i = 0; i < N; i++){
            circles.push_back(i);
        }
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(M[i][j]){
                    join(circles,i,j,ans);
                }
            }
        }
        return ans;
    }
    
    //
    void join(vector<int> &circles, int si, int sj, int &ans){
        int ci = searchAndPathCompress(circles,si);
        int cj = searchAndPathCompress(circles,sj);
        if(ci != cj){
            // 合并朋友圈
            circles[ci] = cj;
            ans--;
        }
    }
    
    // 搜索所属的朋友圈（根）
    int searchAndPathCompress(vector<int> &circles,int si){
        int fi = si,tmp;
        while(si != circles[si]){
            si = circles[si];
        }
        // 路径压缩
        while(fi != si){
            tmp = circles[fi];
            circles[fi] = si;
            fi = tmp;
        }
        return si;
    }
};
```

