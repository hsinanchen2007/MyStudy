### 解题思路
- 思路还是比较好想的，只要你了解异或位运算
- ^符号，代表异或，相同为0，不同为1
- 比如5^2=7  101^010=111 
- ~~
- 这里利用了异或一个数两次还等于它自身的性质
- a^b^b=a  a^b^a=b
- ~~
- 还需要注意这里i和j的判定是不同的，不然n为奇数的时候有些数会计算两次
- ![leetcode4-7.gif](https://pic.leetcode-cn.com/5c3d2cf4ba0ba8a3f0f4a80820e5af9e61cd170cea64c1012640e793cff49f6a-leetcode4-7.gif)

![image.png](https://pic.leetcode-cn.com/78377cc8e06acc7cc3c141f039284da899dd9da74c67f39d190c7cc72d02b143-image.png)


### 代码

```cpp
class Solution {
private:
    void swap(int& a,int& b){
        a=a^b;
        b=a^b;
        a=a^b;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        //swap(matrix[1][1],matrix[1][1]);
        int n=matrix.size();
        for(int i=0;i<(n+1)/2;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(matrix[i][j],matrix[n-1-i][n-1-j]);
                swap(matrix[i][j],matrix[n-1-j][i]);
                swap(matrix[n-1-i][n-1-j],matrix[j][n-1-i]);

            }
        }
        
    }
};
```![leetcode4-7.gif](https://pic.leetcode-cn.com/5648fcf79f136ab01185da16784aa3760a03c6a8a13b7195bf5dfe0206e6b007-leetcode4-7.gif)
