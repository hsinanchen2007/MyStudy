
全部塞入队列，然后取出pq里的第k个元素
```c++
struct cmp{
    bool operator()(const int& a, const int& b){
        return a>b;
    }
};
class Solution{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k){
        int n = matrix.size();
        priority_queue<int, vector<int>, cmp> pq;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                pq.push(matrix[i][j]);
            }
        }
        int ans;
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        return ans;
        
    }
};
```