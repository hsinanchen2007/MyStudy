### 解题思路
翻转、反转 一个循环

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        for(int i = 0; i < A.size(); ++i)
        {
            int left = 0;
            int right = (int)A.at(0).size() - 1;
            while(left < right)
            {
                //翻转
                swap(A.at(i).at(left), A.at(i).at(right));

                //反转
                A.at(i).at(left) = (A.at(i).at(left) == 0 ? 1 : 0);
                A.at(i).at(right) = (A.at(i).at(right) == 0 ? 1 : 0);

                ++left;
                --right;
            }

            if(left == right) //列为奇数
            {
                A.at(i).at(left) = (A.at(i).at(left) == 0 ? 1 : 0);
            }
        }

        return A;
    }
};
```