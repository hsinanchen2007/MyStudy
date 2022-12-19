
解法1 使用方向偏移

You should use an array of direction offsets if you want to be a game developer. And you don't need to check the border because rows and cols always decrease. Here is my C++ code
以上是复制的美版leetcode某位用户的评论，借鉴他的思想，我对他的解法做了一些修改，提高了代码的可读性。
[https://leetcode.com/problems/spiral-matrix/discuss/20599/Super-Simple-and-Easy-to-Understand-Solution]()
```
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return {};
        
        int dir_i[4]={0,1,0,-1};
        int dir_j[4]={1,0,-1,0};
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> res;
        int cnt=0; //res当前存储的元素个数
       
        int idx=0;//方向索引
        int counts=rows*cols;
        int pos_i=0,pos_j=-1; //位置索引
        int len;
        
        while(cnt<counts){
            if(idx==0||idx==2)  //获得当前遍历行or列的长度
                len=cols;
            else
                len=rows;
            
            for(int i=0;i<len;i++){ //遍历行or列
                pos_i=pos_i+dir_i[idx]; //计算当前位置
                pos_j=pos_j+dir_j[idx];
                res.push_back(matrix[pos_i][pos_j]);  
                cnt++;
                if(cnt==counts) 
                    return res;
              
            }
            if(idx==0||idx==2)  //更新边界值，思想借鉴官方解法二
                rows--;
            else if(idx==1||idx==3)
                cols--;
            idx=(idx+1)%4; //转换方向
        }
        
        return res;
        
    }
```
解法2  更新边界值 官方解法二
```
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return {};
        
        vector<int> res;
        int left=0,right=matrix[0].size()-1,top=0,bottom=matrix.size()-1;
        while(left<=right&&top<=bottom){  
            
            for(int i=left;i<=right;i++) //从左到右
                res.push_back(matrix[top][i]);
            top++;
            if(top>bottom)
                break;
            
            for(int i=top;i<=bottom;i++)  //从上到下
                res.push_back(matrix[i][right]);
            right--;
            if(left>right)
                break;
            
            for(int i=right;i>=left;i--) //从右到左
                res.push_back(matrix[bottom][i]);
            bottom--;
            if(top>bottom)
                break;
            
            for(int i=bottom;i>=top;i--)  //从下到上
                res.push_back(matrix[i][left]);
            left++;
            if(left>right)
                break;
            
        }
        return res;
    }
```
