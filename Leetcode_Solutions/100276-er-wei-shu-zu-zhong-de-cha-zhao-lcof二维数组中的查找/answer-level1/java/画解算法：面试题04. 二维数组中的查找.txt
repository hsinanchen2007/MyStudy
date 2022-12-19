## 解题方案

### 思路

- 标签：数组遍历
- 从矩阵的左下角看，上方的数字都比其小，右方的数字都比其大，所以依据该规律去判断数字是否存在
- 设当前数字为 cur，目标数字为 target，当 target < cur 时，cur 更新为其上面的数字，当 target > cur 时，cur 更新为其右侧的数字，直到相等则返回 true，否则到了矩阵边界返回 false
- 时间复杂度：O(m+n)

### 代码

```Java []
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix.length == 0)
            return false;

        int x = 0;
        int y = matrix.length - 1;

        while(x < matrix[0].length && y >= 0){
            if(matrix[y][x] > target) {
                y--;
            } else if(matrix[y][x] < target) {
                x++;
            } else {
                return true;
            }
        }

        return false;
    }
}
```

```JavaScript []
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    if(matrix.length == 0)
        return false;

    let x = 0;
    let y = matrix.length - 1;

    while(x < matrix[0].length && y >= 0){
        if(matrix[y][x] > target) {
            y--;
        } else if(matrix[y][x] < target) {
            x++;
        } else {
            return true;
        }
    }

    return false;
};
```

### 画解

<![offer4-1.png](https://pic.leetcode-cn.com/bf3a521951c5e6987d970317d43f2b917142cf8251b9063f7592693b50aaa238-offer4-1.png),![offer4-2.png](https://pic.leetcode-cn.com/8bc2d0cceb13896185e5f16dd6d51bacef5c8dd77f2986e724abf3c4ca7dfc5e-offer4-2.png),![offer4-3.png](https://pic.leetcode-cn.com/06f105ba3fca108fa16f8dfdea569f4cfed926c65be354b56526258e21fb1da9-offer4-3.png),![offer4-4.png](https://pic.leetcode-cn.com/a54798ca285e9a56002582fa6d90aa2a60820219e864c553728cb90a368e3a53-offer4-4.png),![offer4-5.png](https://pic.leetcode-cn.com/0955d6ac7ae23d2e165345465a52406228ced205e37e4874f60b80510f7539a6-offer4-5.png),![offer4-6.png](https://pic.leetcode-cn.com/a8294d3b2384a568ffc7967fb750e3cb5f1eb5f3194f27d00e75268ccf2c40c3-offer4-6.png),![offer4-7.png](https://pic.leetcode-cn.com/3dc76aa71587714a3800787f754418895f7c0f187804196797d6559dad20bb51-offer4-7.png),![offer4-8.png](https://pic.leetcode-cn.com/662add653dd38fedfd899875e70f6c37a9e89cd65542eb51bb971128e0009bfe-offer4-8.png),![offer4-9.png](https://pic.leetcode-cn.com/35c3f6c7fe4f8abcbf4c0d2ba03240fd871d682fe034280007b5034bfa0a7972-offer4-9.png),![offer4-10.png](https://pic.leetcode-cn.com/8950fec5d1ba71b3dafd636256fc5cc92fec72d9081e1800c1db57e27685a3a2-offer4-10.png)>
