![image.png](https://pic.leetcode-cn.com/f20499ed0e3ec0334c61b470ea02479d931b841881ef8ebde717f506df87dec0-image.png)

### 解题思路
**建立一个和二维一一映射的一维。**
在逻辑上将二维看成一维，然后使用二分法，实际比较的时候将一维映射到二维上，也就是比较的是二维数组的元素，但是元素下标是通过一维空间的二分来确定的。
· 二分一维空间，等价于二分二维空间。
· 取到一个一维上的mid，等价于取到一个二维上的matrix[mid/n][mid%n]


### 代码

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1;  
        while(left<right){
            int mid = left + (right-left)/2;
            if(matrix[mid/n][mid%n]==target){ // 实际比较的时候将二维映射到一维上，也就是说二维和一维之间是一一对应的。
                return true;
            }else if(matrix[mid/n][mid%n]<target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        if(matrix[left/n][left%n]==target){
            return true;
        }else{
            return false;
        }
    }
};
```
有收获请点赞