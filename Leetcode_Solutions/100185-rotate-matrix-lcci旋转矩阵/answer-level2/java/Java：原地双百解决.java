![image.png](https://pic.leetcode-cn.com/8f7b882b3353d1fe9a9d6b4943db608e3452375076b984615033fd79b2c32d43-image.png)

### 解题思路
见代码注释，写的已经很详细了，有疑问或者问题的欢迎大家提出或指出！

### 代码

```java
//int n = N - 1;
//matrix[i][j]旋转后得位置matrix[j][n - i]
//本题的解决方式是从外到内一层一层的旋转

class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix[0].length;       //数组matrix对应的N的值
        int floor = 0;                  //需要旋转的层数
        int n = N - 1;                  //对应到数组matrix最大的下标
        int cir = N;

        //判断出旋转的层数
        if(N % 2 == 1) {
            floor = N / 2 + 1; 
        } else {
            floor = N / 2;
        }

        for(int i = 0; i < floor; ++i) {        //旋转操作
            cir = N + i - 1;                    //最核心的一步：得到该层的最大下标
            /* 上面一步可分解为：
                cir = N;
                cir += i;
                cir -= 1;
            */
            for(int j = i; j < cir; ++j) {     //在该层进行旋转的时候取不到最大下标处，cir-j为当前层内需要旋转的组数
                //四个方位进行旋转交换，需要用到两个中间变量temp1，temp2
                int temp1 = matrix[j][n - i];
                matrix[j][n - i] = matrix[i][j];
                int temp2 = matrix[n - i][n - j];
                matrix[n - i][n - j] = temp1;
                temp1 = matrix[n - j][i];
                matrix[n - j][i] = temp2;
                matrix[i][j] = temp1;
            }
            N -= 2;     //进入下一层，下一层的长度比上一层小2
        }
    }
}
```