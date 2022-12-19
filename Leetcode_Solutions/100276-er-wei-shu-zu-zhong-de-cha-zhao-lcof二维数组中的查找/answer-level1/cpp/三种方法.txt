三种方法：
1.m+n复杂度，根据数组的具体排列，从某个角落出发，然后根据大小关系往对角跑
```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int x=matrix.size()-1,y=0;
        while(x>=0&&y<matrix[0].size()){
            if(matrix[x][y]==target)
                return true;
            matrix[x][y]>target?x--:y++;
        }
        return false;
    }
};
```
2.暴力二分，也就是每行进行二分处理
效率居然比上面高，LeetCode的判题结果感觉会随我的网络状况进行波动~
这个还是可以优化部分细节的，比如前一行第一个数都比目标数小，可以直接返回false了
```
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)
            return false;
        for(int i=0;i<matrix.size();i++){
            int left=0,right=matrix[0].size()-1;
            while(left<right){
                int mid = left+(right-left)/2;
                if(matrix[i][mid]<target)
                    left = mid+1;
                else
                    right = mid;
            }
            if(matrix[i][left]==target)
                return true;
        }
        return false;
    }
};
```
3.二维矩阵的二分，也就是二分的拓展，把矩阵分成4份，然后根据大小关系判断接下来应该搜索的部分。
因为可能部分维度只有一维，mid+1操作可能会使得那个一维的维度越界，因此需要加上边界的最大值作为参数。
```
class Solution {
public:
    bool search(vector<vector<int>>& matrix,int leftx,int lefty,int rightx,int righty,int boundaryx,int boundaryy,int target){    
        if(rightx>boundaryx||righty>boundaryy||leftx>boundaryx||lefty>boundaryy)
            return false;
        if(leftx<rightx||lefty<righty){
            int midx = leftx+(rightx-leftx)/2,midy = lefty+(righty-lefty)/2;
            if(matrix[midx][midy]>=target)
                return search(matrix,leftx,lefty,midx,midy,midx,midy,target)||search(matrix,midx+1,lefty,rightx,midy,boundaryx,midy,target)||search(matrix,leftx,midy+1,midx,righty,midx,boundaryy,target);
            else 
                return search(matrix,midx+1,lefty,rightx,midy,boundaryx,midy,target)||search(matrix,leftx,midy+1,midx,righty,midx,boundaryy,target)||search(matrix,midx+1,midy+1,rightx,righty,boundaryx,boundaryy,target);
        }

        return matrix[leftx][lefty]==target;
    }
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)
            return false;
        return search(matrix,0,0,matrix.size()-1,matrix[0].size()-1,matrix.size()-1,matrix[0].size()-1,target);
    }
};
```