### 题解来自博客：[https://blog.csdn.net/wuzhongqiang/article/details/103221743](https://blog.csdn.net/wuzhongqiang/article/details/103221743)
<br>
#### 思路一： 矩阵转置+镜像翻转
这个题拿过来的第一个思路，就是矩阵转置和镜像水平翻转， 类似下面的图像，拿样例中的第二个举例：
![在这里插入图片描述](https://pic.leetcode-cn.com/56d26d3c23ef47a0c137fef94f35c8d039777f38ff1494afd00d9ab865f897ae.png)
所以这个题比较容易理解的方式就是转置和水平镜像翻转了，实现起来也比较简单， 遍历一遍二维数组，先进行转置，然后遍历一遍行，每一行逆序即可，代码如下：

```cpp
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int rownum = matrix.size();
        int colnum = matrix[0].size();

        // 将矩阵转置
        for (int i=0; i<rownum; i++)
        {
            for (int j=0; j<i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 每一行对称翻转
        for (int i=0; i<rownum; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```
时间复杂度： O(n^2)   空间复杂度O(1)  没有额外的空间开销

#### 思路二： 直接翻转
上面的思路使用了两次矩阵翻转，其实只需要遍历一遍矩阵，进行一次翻转就可以， 我们看看应该怎么翻转：
![在这里插入图片描述](https://pic.leetcode-cn.com/0f01c8a5b772ef1882569feda68eef6b85f1fa64684d84066c7e3917a52633f6.png)
所以这个思路的关键就是遍历的时候取好终止条件，和交换的时候，下标的对应位置。  这个其实还是有点麻烦的
* 对于matrix1来说，我们遍历的下标，行的范围是第0行-第1行，列的范围是第0列即可， 即元素1和4打头。 如下图：
![在这里插入图片描述](https://pic.leetcode-cn.com/e12507e51094f7a196d4287bfd4aa60fcda99e08e47583d00c3639043c3a3514.png)
*对于matrix2来说，我们遍历的下标，行的范围第0行和第1行，列的范围下标是第0列和第1列。 如下图：
![在这里插入图片描述](https://pic.leetcode-cn.com/fb0999a8c8d22ed96f302d387c398772d33a7e29f02fd79553a97db7422929db.png)
交换的时候，下标的对应位置如上图所示，这个理解的时候，可以在原矩阵标出ij的位置，然后找到转置的ji的位置，然后在看交换是下标的对应位置。

所以一次遍历即可实现，最终的代码如下：

```cpp
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        
        for (int i=0; i<(n+1)/2; i++)    // 行的遍历范围
        {
            for (int j=0; j<n/2; j++)     // 列的遍历范围
            {
             // 由于是旋转赋值，所以temp记录的是最后一个位置上的元素
             //然后逆时针进行覆盖，见上面的图。
                int temp = matrix[n-1-j][i];    
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};

```
这个的效率要比第一个思路的效率高一些，时间复杂度和空间复杂度和上面的那个一样。 但是只用一次遍历即可。
这个的关键就是行列遍历的终止条件和元素交换的下标对应。

#### 小总：
这个题的第二种思路虽然效率高一些，但是比较难想到，并且如果对应不好终止条件，有可能转多了，下标也比较难对应，所以有的时候，第二种思路作为一种小拓展，第一种思路比较好理解一些。 这是旋转90度，如果逆时针旋转90或者是多少度的时候，也最好先从第一个思路开始出发，看看能不能简单的转置加逆序搞定，搞不定的时候，再考虑第二种思路。