这是一道实现起来很简单（代码行数少）但是需要非常细心才能避免出错的问题。
回顾下我们常用的数组下标索引问题，最常见的有两种，
1. 遍历一个一维数组，非常简单，用一个非常简单的for循环即可。
```
int array[N];
for(int i=0; i<N; i++)
    cout <<array[i] <<endl;
```


2. 遍历一个二维数组，双重for循环，也非常简单。
```
int array[M][N];
for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){
        cout << array[i][j] << endl;
    }
}
```
这个问题本质上考察的就是一个二维数组的索引问题，因为算法要求in place，则需要我们原地交换matrix中某些entry的值，达到顺时针旋转矩阵90°的效果。但是，没有现成的公式可以使用，为了解决这个问题，我们可以将这个问题简化为两个小问题，即
**顺时针旋转90° = 先沿竖直方向中心线翻转 + 再沿主对角线翻转**
如下图所示：
![photo20200329121118.jpg](https://pic.leetcode-cn.com/0cf080fe7b552eab601d91690803c54c9ecf774709bab9045b2bd67a60903ce1-photo20200329121118.jpg)

其中，沿竖直防线中心线翻转和沿主对角线翻转均是可以通过基本的数组下标索引实现，只是需要更加细心些，具体代码如下：
```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        int mid = (len-1)/2;
        //flip over x = len/2
        for(int i=0; i<len; i++){
            for(int j=0; j<=mid; j++){
                swap(matrix[i][j],matrix[i][len-1-j]);
            }
        }
        //flip over diag
        for(int i=0; i<len; i++){
            for(int j=0; j<len-1-i; j++){
                swap(matrix[i][j],matrix[len-1-j][len-1-i]);
            }
        }
    }
};
```
