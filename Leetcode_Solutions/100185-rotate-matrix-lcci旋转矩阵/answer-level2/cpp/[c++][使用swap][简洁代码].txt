### 解题思路
设置一个换成变量t，在交换时使用swap(要放置的值，t))，可以同时更新t与要放置的值。

### 代码

```cpp
using namespace std;

class Solution{
    public:
        void rotate(vector<vector<int>>& matrix){
            int l1 = 0, c1 = 0;
            int l2 = matrix.size()-1, c2 = l2;
            int t;
            while(l1 < l2){
                for(int i = 0;i <l2-l1;i++){
                    t = matrix[l1][c1+i];
                    swap(matrix[l1+i][c2],t);
                    swap(matrix[l2][c2-i],t);
                    swap(matrix[l2-i][c1],t);
                    swap(matrix[l1][c1+i],t);
                }
                l1++;
                c1++;
                l2--;
                c2--;
            }
        }
};

```