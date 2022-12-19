### 解题思路
分为四步 1、输出上行 2、输出右列 3、输出下行(逆序) 4、输出左列(逆序)
然后设置一个计数器count，只要count和数组大小相等就返回vec即可


### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> vec;
        if(matrix.empty())
            return vec;
        int left=0;
        int top=0;
        int right = matrix[0].size()-1;
        int bottom = matrix.size()-1;
        int count=0;
        int size = matrix[0].size()*matrix.size();
        while(true){
            for(int i=left;i<right;i++){
                if(count==size)
                    break;
                vec.push_back(matrix[top][i]);
                count++;
            }
            for(int i=top;i<bottom;i++){
                if(count==size)
                    break;
                vec.push_back(matrix[i][right]);
                count++;
            }
            for(int i=right;i>=left;i--){
                if(count==size)
                    break;
                vec.push_back(matrix[bottom][i]);
                count++;
            }
            for(int i=bottom-1;i>top;i--){
                if(count==size)
                    break;
                vec.push_back(matrix[i][left]);
                count++;
            }
            left++;
            top++;
            right--;
            bottom--;
        }
        return vec;
    }
};
```