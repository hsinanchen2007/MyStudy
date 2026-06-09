```
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0)
            return result;
        //最大宽度
        const int maxj=matrix[0].size();
        const int maxi=matrix.size();
        //定义四个方向
        int dir_i[4]={0,1,0,-1};
        int dir_j[4]={1,0,-1,0};
        //先将第一个插入答案中
        int count=1;
        int i=0;
        int j=0;
        int dir=0;
        result.push_back(matrix[0][0]);
        //访问过以后设为-999防止重复访问
        matrix[0][0]=-999;
        int max=maxi*maxj;
        while(count!=max){
            //下一个可能的位置
            int tryi= i + dir_i[dir];
            int tryj = j + dir_j[dir];
            //判断是否合法
            //不合法跳过
            if(tryi==maxi || tryj==maxj || tryi<0 || tryj<0 || matrix[tryi][tryj]==-999){
                dir=(dir+1)%4;
            //合法载入result
            }else{
                result.push_back(matrix[tryi][tryj]);
                matrix[tryi][tryj]=-999;
                i=tryi; j=tryj; 
                count++;
            }
        }
        return result;
    }
};
```
