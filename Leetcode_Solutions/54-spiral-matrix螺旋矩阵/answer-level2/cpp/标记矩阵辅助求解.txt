### 解题思路
![{~)OY5@EF8A\]~@KKZY1NL_5.png](https://pic.leetcode-cn.com/4933cb3edf578e95cf90b442bbe3bd1e317840726940b571ce22457c715a2315-%7B~\)OY5@EF8A%5D~@KKZY1NL_5.png)
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ans;//记录结果；
      if(matrix.size()==0||matrix[0].size()==0) return ans;
      int col=1,rol=matrix[0].size();//横，纵坐标
      vector<vector<int>> record(matrix.size()+2,vector<int>(matrix[0].size()+2,1));//记录被访问过的矩阵
        for(int i=0;i<record.size();i++){
            record[i][0]=0;
            record[i][record[0].size()-1]=0;
        }
        for(int i=1;i<record[0].size()-1;i++){
            record[0][i]=0;
            record[record.size()-1][i]=0;
        }
        /*2个for循环将外围一周变成0*/   
        for(int i=0;i<matrix[0].size();i++)
        {
           ans.push_back(matrix[0][i]);
           record[1][i+1]=0;
        }   
        

        while(record[col-1][rol]+record[col+1][rol]+record[col][rol-1]+record[col][rol+1]!=0)
        {
           if(record[col+1][rol]==1)
           {  
               col++;
              while(record[col][rol]==1)
              { 
                 record[col][rol]=0;
                 ans.push_back(matrix[col-1][rol-1]);
                 col++;
              }
              col--;//回退一格
           }
            if(record[col][rol-1]==1)
           {
               rol--;
               while(record[col][rol]==1)
               {
                   record[col][rol]=0;
                   ans.push_back(matrix[col-1][rol-1]);
                   rol--;
               }
               rol++;
           }

           if(record[col-1][rol]==1)
           {
               col--;
                while(record[col][rol]==1)
               {
                   record[col][rol]=0;
                   ans.push_back(matrix[col-1][rol-1]);
                   col--;
               }
               col++;
           }
          
            if(record[col][rol+1]==1)
           {
               rol++;
               while(record[col][rol]==1)
               {
                   record[col][rol]=0;
                   ans.push_back(matrix[col-1][rol-1]);
                   rol++;
               }
               rol--;
           }
        }
        
    return ans;
    }
};
```
![F6408289075E47C0A855EC1E9D0D5C65.jpg](https://pic.leetcode-cn.com/ae573bc15bf381c6660bdcea209fb14122adfd03653a22bbfaea604716787134-F6408289075E47C0A855EC1E9D0D5C65.jpg)
我们给m*n的矩阵设计一格标技数组，（m+1）*（n+1）4周为0，中间为1。访问的时候，从1开始访问，每访问一个元素就将该元素的标技数组的1置为0；
