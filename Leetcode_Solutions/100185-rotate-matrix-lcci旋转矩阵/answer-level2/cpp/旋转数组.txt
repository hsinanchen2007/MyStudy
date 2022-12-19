哈哈哈，又是暴力打卡的一天，刚才写完后去看了下官方题解，有四种方法，有几种很巧妙，O(1)内存
就可以处理掉。
我的这个方法其实很简单，观察给出的样例，自己在纸上画画就明白了，第一列旋转后跑到了第一行，第二列跑到了
第二行，第三列跑到了第三行。。。
这样一列一列的处理，最终得到旋转数组

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int > > tmp = matrix;   //辅助数组
        int N = matrix.size();
        for(int k = 0;k < N;k++){    //列数
            for(int j = N - 1;j >= 0;j--){       //行数
                tmp[k][N-j-1] = matrix[j][k];      //旋转
            }
        }
        matrix = tmp;
    }
};
```