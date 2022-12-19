### 解法一
```
    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
    ]
```
- 可以看成是一个二维数组，我们可以在最下面加一行：
```
    [
         [2],
        [3,4],
       [6,5,7],
      [4,1,8,3]
     [a,b,c,d,e]
    ]
```
- a,b,c,d,e都是0，写成字母容易陈述。对于4来说，`minTotal(4)=4+minTotal(a)+minTotal(b)`，同理`minTotal(1)=1+minTotal(b)+minTotal(c)`，基于这样一个关系，我们从下往上开始遍历，最后到`minTotal(2)=2+minTotal(3)+minTotal(4)`，最后的结果就是我们想要的。
- 我们可以声明一个二维数组，比如`dp[i][j]`，表示第`i`行、第`j`列的`minTotal`，遍历到最后，`i=j=0`就是最终结果。
- 代码
```java
    public int minimumTotal(List<List<Integer>> triangle) {
        if(triangle == null || triangle.size() == 0){
            return 0;
        }
        int rows=triangle.size();
        int[] [] dp = new int [rows + 1][rows + 1];
        //最后一行
        for (int i = rows - 1; i >= 0; i--) {
            //最左侧
            for (int j = 0; j < triangle.get(i).size(); j++) {
                //minTotal[i][j] = 它下一行中最小的 + 它本身
                dp[i] [j] = Math.min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle.get(i).get(j);
            }
        }
        return dp[0][0];
    }
```
### 解法二
- 上面二维`dp`实际上也只和下一层的状态有关,所以我们可以重复的使用这个数组保存每一层的状态
```java
    public int minimumTotal(List<List<Integer>> triangle) {
        int rows=triangle.size();
        //dp[i]表示每层第i个元素的minTotal
        int[] dp=new int[rows+1];
        for (int i=rows-1;i>=0;i--) {
            for (int j=0;j<triangle.get(i).size();j++) {
                //minTotal[i] = 上次计算的两个中最小的那个 + 它本身
                dp[j]=Math.min(dp[j+1],dp[j])+triangle.get(i).get(j);
            }
        }
        return dp[0];
    }
```