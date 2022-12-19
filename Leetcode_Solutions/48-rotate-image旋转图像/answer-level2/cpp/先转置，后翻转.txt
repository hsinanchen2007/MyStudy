``` C++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //先转置，后翻转
        if(matrix.empty()) return;
        for(int i=0;i<matrix.size();i++)
        {  
            for(int j=i;j<matrix[0].size();j++)//此处为j=i
            {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
            reverse(matrix[i]);//翻转转置了的行
        }
    }
    //反转函数
    void reverse(vector<int> &arr)
    {
        int start=0,end=arr.size()-1;
        while(start<end)
        {
            int temp=arr[start];
            arr[start++]=arr[end];
            arr[end--]=temp;
        }
    }
};
```