### 解题思路
从数组左下角开始比较，如果target大，删除对应列，向右寻找；如果target小，删除对应行，向上寻找，不断查找，知道找到相等或数组删到空，找到返回true，未找到返回false

### 代码

```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size()-1;
        int m=0;
        while(n>=0&&m<matrix[0].size())
        {
            if(target>matrix[n][m])
                m++;
            else if(target<matrix[n][m])
                n--;
            else
                return true;
        }
        return false;
    }
};
```