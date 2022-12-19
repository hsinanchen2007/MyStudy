class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > matrix(n); 
        for(int i=0;i<n;i++) 
        {
            matrix[i].resize(n);
        }
        generate(matrix,0,-1,0,n);
        return matrix;
    }

    void generate(vector<vector<int>> &matrix ,int start, int x,int y , int n){
        if(n == 0 ) return ;
        if(n == 1){
            matrix[y][x+1] = start+1;
            return ;
        }
        int x1 = x;
        int y1 = y;
        int start1 = start;
        for(int i = 0; i < n;i++){
            matrix[y1][++x1] = ++start1;
        }   
        for(int i = 0; i < n-1;i++){
            matrix[++y1][x1] = ++start1;
        } 
        for(int i = 0; i < n-1;i++){
            matrix[y1][--x1] = ++start1;
        } 
        for(int i = 0; i < n-2;i++){
            matrix[--y1][x1] = ++start1;
        } 
        return  generate( matrix,start1,x1,y1,n-2);
    }
};