![rwerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr.PNG](https://pic.leetcode-cn.com/f78e13fa634796f4b9f45abcdf4c7d9d49a481a43655c33ad5adae0bfadba7c6-rwerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr.PNG)
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0) return vector<vector<int>>();
        vector<vector<int>> my_vec;
        my_vec.push_back(vector<int>{1});
        if(numRows==1) return my_vec;
        my_vec.push_back(vector<int>{1,1});
        if(numRows==2) return my_vec;
        for(int n=3;n<=numRows;++n){
            vector<int> temp{1};
            for(int i=0;i<my_vec[n-2].size()-1;++i){
                temp.push_back(my_vec[n-2][i]+my_vec[n-2][i+1]);
            }
            temp.push_back(1);
            my_vec.push_back(temp);
        }
        return my_vec;
    }
};
```
