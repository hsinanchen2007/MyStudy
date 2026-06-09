没有用官解给的思路，但是时间有点慢啦


class Solution {
public:
    //最大面积
    int maxArea=0;
    int Rate=1;
    
    //找出最大面积的矩阵
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        vector<vector<char>> temp=matrix;
        
        while(Rate<=matrix.size()){
            for(int i=0;i<matrix.size()-Rate+1;i++){
                maxRowArea(temp[i]);
            }
            ZoomToSmall(temp);
            Rate++;  
        }
        return maxArea;
    }

    //计算每一行最大的都为1的长度
    void maxRowArea(vector<char>& Row){
        int maxLen=0,tempLen=0;
        int width=Row.size();
        for(int i=0;i<width;i++){
            if(Row[i]=='1'){
                tempLen++;
            } else {
                maxLen=max(maxLen,tempLen);
                tempLen=0;
            }
        }
        maxLen=max(maxLen,tempLen);
        maxArea=max(maxArea,maxLen*Rate);
    }
    
    //缩放，将两行之间合并
    void ZoomToSmall(vector<vector<char>>& matrix){        
        int length=matrix.size();
        int width=matrix[0].size();
        for(int i=0;i<length-Rate;i++){
            for(int j=0;j<width;j++){
                if(!(matrix[i][j]=='1' && matrix[i+1][j]=='1'))
                    matrix[i][j]='0';
            }
        }
    }
    
};


