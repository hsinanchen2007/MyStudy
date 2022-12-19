题目规定了不允许使用额外空间，因此，必须计算转换关系，原地进行替换，根据二维旋转矩阵，转换前后满足下面的关系：

![捕获.PNG](https://pic.leetcode-cn.com/83de6e2bccbec162a0b9dc0716cbda24840a95f810d709adc32f5ee2edfdc873-%E6%8D%95%E8%8E%B7.PNG)

由于是顺时针旋转90度，因此θ在这里是90度：

![捕获2.PNG](https://pic.leetcode-cn.com/0ffbd0e53cbb499464c59a38d50564b1fddcd99e07bba7efc046b759618300c3-%E6%8D%95%E8%8E%B72.PNG)

加上列偏移，最终满足下面的关系：

![捕获3.PNG](https://pic.leetcode-cn.com/32f4deada2b52137d13abbf4b28c35596a1e25634a1bf7a9fa916355cccfe482-%E6%8D%95%E8%8E%B73.PNG)

有了这个关系，只需要从第一行开始，由外环向内环逐个元素替换即可，非常简单，代码如下

```
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = 0;
        int col = 0;
        
        int row_prev = 0;
        int col_prev = 0;

        int row_next = 0;
        int col_next = 0;

        int target_val = 0;
        int origin_val = 0;
    
        int corner = 0;

        for(row = 0; row < matrix.size() >> 1 ; row++)
        {
            for(col = row; col < matrix.size() - row - 1; col++)
            {
                corner = 0;
                col_prev = col;
                row_prev = row;
                origin_val = matrix[row_prev][col_prev];

                while(corner < 4) 
                {   
                    //计算目标位置
                    row_next = col_prev;
                    col_next = matrix.size() - 1 - row_prev;

                    //用当前位数字替换目标位数字
                    target_val = matrix[row_next][col_next];
                    matrix[row_next][col_next] = origin_val;
                    origin_val = target_val;
                    
                    //更新目标位置
                    row_prev = row_next;
                    col_prev = col_next;
                    corner++;
                }
            }
        }
    }
};
```

C++运行时间和内存消耗如下：
![image.png](https://pic.leetcode-cn.com/d186f4768f5e2470c689a602f0c157006d605ef5f697eb0efad48a968787380f-image.png)