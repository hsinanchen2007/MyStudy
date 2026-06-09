### 解题思路
先采用二分查找找出小于目标值的最大左值行，再在此行中根据二分查找查看是否有目标值。
关于特殊情况的处理要仔细...
4 ms, 在所有 C++ 提交中击败了99.53%的用户


### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if(matrix[0][0]>target||matrix[m-1][n-1]<target) return false;
        int sh=0, ta=m-1;
        while (sh<=ta) {
            int mid = (sh+ta)/2;
            if(matrix[mid][0]>target){
                ta = mid - 1;
            }
            else if (matrix[mid][0]<target){
                sh = mid + 1;
            }
            else return true;
        }
        if(matrix[ta][0]<=target&&matrix[ta][n-1]>=target){
            int left=0,right=n-1;
            while (left<right) {
                int mid = (left+right)/2;
                if(matrix[ta][mid]>target){
                    right = mid - 1;
                }
                else if (matrix[ta][mid]<target){
                    left = mid + 1;
                }
                else return true;
            }
            if(matrix[ta][right]==target) return true;
        }
        return false;
    }
};

```
参考了官网一次二分查找，代码简洁多了，但是执行效率还是一般..

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        if(matrix.empty()||matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if(matrix[0][0]>target||matrix[m-1][n-1]<target) return false;
        int left=0, right=m*n-1;
        while (left<=right) {
            int mid = (left+right)/2;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]>target){
                right = mid - 1;
            }
            else if (matrix[i][j]<target){
                left = mid + 1;
            }
            else return true;
        }
        return false;
    }
};
```