//法一：
    //1.先转换为一个有序的数组
    //2.使用二分查找法查找
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     vector<int> ans;
    //     //这种时间复杂度为O（n）
    //     for(auto &each : matrix)
    //         for(auto &one : each)
    //             ans.push_back(one);
        
    //     int left=0;
    //     int right=ans.size()-1;
    //     while(left<=right)
    //     {
    //         int mid = left+(right-left)/2;
    //         if(ans[mid]== target)
    //             return true;
    //         else if(ans[mid]>target)
    //             right = mid-1;
    //         else
    //             left = mid+1;
    //     }
    //     return false;

    // }
    //法二：

    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.size()==0)
            return false;
        int rows=matrix.size();
        int columns = matrix[0].size();

        if( rows >0 && columns>0)
        {
            int row=0;
            int column= columns-1;
            while(row<rows && columns>0)
            {
                if(matrix[row][column]==target)
                {
                    return true;
                }else if(matrix[row][column]> target)
                    column--;
                else
                    row++;
            }
        }
        return false;
    }

求解，我第二种方法在leetcode提交会报错，在本地IDE都不会，希望大家可以帮忙看下