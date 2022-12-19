### 解题思路
两个步骤：1.水平翻转 2.1、0互换 遍历实现即可
![捕获.PNG](https://pic.leetcode-cn.com/4aabea11793b8c12c12875ad8b41960d3f1d99dca53c0e165ac803c27f2e7f92-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        //水平翻转
        vector<vector<int>> B = A;
        for(int i=0 ; i<A.size() ; i++){
            for(int j=0 ; j<A.size() ; j++){
                B[i][j] = !A[i][A.size()-j-1] ; //1、0互换
            }
        }        
        return B;
    }
};
```