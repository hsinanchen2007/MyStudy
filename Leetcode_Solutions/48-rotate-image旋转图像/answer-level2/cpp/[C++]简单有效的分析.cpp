
这个题就是在找规律。不难总结出移动前后的元素存在如下对应关系
a[i, j] -> a[j, n-1 -i]
a[j, n-1-i] -> a[n-1-i, n-1-j]
a[n-1-i,n-1-j]->a[n-1-j,i]
a[n-1-j,i] -> a[i,j]
因此使用一个tmp保存a[i,j]即可。

还有另外一个方法，既然a[i,j]->a[j,n-1-i],但两者直接swap又不行，可以取个折中办法，
a[i,j] -> a[j,i]
a[j,i]-> a[j, n-1 -i]
由于对称时进行swap互不影响，两个互不影响的操作最后可以达到目的

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() <= 1)
            return;
        
        auto size = matrix.size(); 

        for(auto i = 0; i <size; ++i)
        {
            for( auto j = i + 1; j <size; ++j)
            {
                if( i != j){
                    std::swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for(auto j = 0; j < size; ++j)
        {
            for(auto i = 0; i < (size + 1) / 2; ++i)
            {
                std::swap(matrix[j][i], matrix[j][size - 1 - i]);
            }
        }
    
    }
};
```