### 解题思路
**话不多说，上图！！！**
![题解.PNG](https://pic.leetcode-cn.com/003b3c7d11a5e651f34af7668f958df8837af4f1deccd6047bc3039ab0f89273-%E9%A2%98%E8%A7%A3.PNG)

看完图会发现，以这两步操作同样能达到效果，所以不需要辅助内存，直接一套整完。

【三连一手，快快快】
![双百.PNG](https://pic.leetcode-cn.com/93f0f0a5be590fffe260c5e1033d62a55e15872ab4ebbb0c5e7e3213babdd0bd-%E5%8F%8C%E7%99%BE.PNG)
![啥.jpg](https://pic.leetcode-cn.com/2b877f7b3be8914811ce6168d68c6612e1ee5c936dc2117513bdf5c282b2f5d8-%E5%95%A5.jpg)


`接下来，上代码！！！`

### 代码

```C++ []
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        //上下翻转
        for(int i=0;i<row/2;i++){
            for(int j=0;j<row;j++){
                //交换
                int change=matrix[i][j];
                matrix[i][j]=matrix[row-1-i][j];
                matrix[row-1-i][j]=change;
            }
        }
        //主对角线翻转
        for(int i=1;i<row;i++){
            for(int j=0;j<i;j++){
                //交换
                int change=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=change;
            }
        }
    }
};
```
```JAVA []
class Solution {
    public void rotate(int[][] matrix) {
        int row=matrix.length;
        //上下翻转
        for(int i=0;i<row/2;i++){
            for(int j=0;j<row;j++){
                //交换
                int change=matrix[i][j];
                matrix[i][j]=matrix[row-1-i][j];
                matrix[row-1-i][j]=change;
            }
        }
        //主对角线翻转
        for(int i=1;i<row;i++){
            for(int j=0;j<i;j++){
                //交换
                int change=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=change;
            }
        }
    }
}
```
