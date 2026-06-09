class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
     	int tr = 0;
		int tc = 0;
		int dr = matrix.size()-1;
        int dc = matrix[0].size()-1;
        while(tr<dr)
        range(tr++,tc++,dr--,dc--,matrix);
    }
    void range(int tr,int tc,int dr,int dc,vector<vector<int>>& matrix) {
        int time=dr-tr;
        for(int i=0;i<time;++i) {
            int temp=matrix[tr][tc+i];
            matrix[tr][tc+i]=matrix[dr-i][tc];
            matrix[dr-i][tc]=matrix[dr][dc-i];
            matrix[dr][dc-i]=matrix[tr+i][dc];
            matrix[tr+i][dc]=temp;
        }
    }
};