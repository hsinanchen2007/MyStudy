### 其他答案中的当s[j]==t[i]时候的dp[i][j]=dp[i-1][j-1]+dp[i][j-1]，虽然能够通过画图推出来，但是本人愚笨，无法将这个公式与现实意义形成映射。映射不了的我就理解不了，就算背下来也没有意义，下面给出本人的算法，效率不高，但是穷举好理解。
* 首先，把相等的字符标上1，不相等的标上0
* 然后，穷举法画出T匹配S所有路径如下图，计算匹配问题转化为计算所有不同路径问题
![image.png](https://pic.leetcode-cn.com/21c205bc5a49cb236c7ab9f740a7b63ee41f74c86fa9a015c73ed656b311045c-image.png)
* 计算不同路径采用自底向上方法，先初始化最后一行，然后从倒数第二行开始，一旦s[j]==t[j]，那么它向下匹配的路径个数是下一行右边的路径数的和。
* 最后统计第一行的和就是结果
```
class Solution {
    public int numDistinct(String s, String t) {
        char[] sc = s.toCharArray();
        char[] tc = t.toCharArray();
        int[][] dp = new int[tc.length][sc.length];
        for(int j=0;j<sc.length;j++){
            if(tc[tc.length-1] == sc[j]){
                dp[tc.length-1][j] = 1;
            }
        }
        for(int i=tc.length-2;i>=0;i--){
            for(int j=sc.length-1;j>=0;j--){
                if(sc[j]==tc[i]){
                    // find next row nums of 1
                    for(int k=j+1;k<sc.length;k++){
                        if(tc[i+1]==sc[k]){
                            dp[i][j] += dp[i+1][k];
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<sc.length;i++){
            res += dp[0][i];
        }
        return res;
    }
}
```
