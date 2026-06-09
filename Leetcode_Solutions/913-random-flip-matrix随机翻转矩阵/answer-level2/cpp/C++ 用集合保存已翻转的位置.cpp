```
class Solution {
public:
    unordered_set<long> matrix;
    int capa;
    int rows,cols;
    Solution(int n_rows, int n_cols) {
        capa = n_rows * n_cols;
        rows = n_rows, cols = n_cols;
        srand(time(0));
    }
    
    vector<int> flip() {
        long row,col,pos;
        do {
            pos = rand()%capa;
        }while(matrix.count(pos) != 0);
        matrix.insert(pos);
        row = pos/cols;
        col = pos - row*cols;
        return {row,col};
    }
    
    void reset() {
        matrix.clear();
    }
};

```
