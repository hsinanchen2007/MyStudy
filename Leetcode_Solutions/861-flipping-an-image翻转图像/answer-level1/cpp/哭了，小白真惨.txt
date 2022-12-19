### 解题思路
直接模拟，先逆置每一行，再对每个元素求反，时间爆炸O（n2）,暴风哭泣

### 代码

```cpp
class Solution {// 直接模拟
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int AL=A.size();
       //vector<vector<int>> matrix(AL,vector(AL,0));
        for(int i=0;i<AL;i++){
            for(int j=0;j<AL/2;j++){
                swap(A[i][j],A[i][AL-1-j]);
            }
        }//先逆置每一行
        for(int i=0;i<AL;i++){//对A中元素求反
            for(int j=0;j<AL;j++){
                if(A[i][j]==1) A[i][j]=0;
                else A[i][j]=1;
            }
        }
        return A;
    }
};
```