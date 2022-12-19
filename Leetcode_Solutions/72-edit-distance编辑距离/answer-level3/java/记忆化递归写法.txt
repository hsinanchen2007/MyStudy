### 解题思路
DTW 的 DP 写法应该写过很多次了
这次用记忆化递归来实现一次
实现上可能简单一点
效率的话因为涉及到是否访问到的判断以及更深的堆栈，还是不如DP的

把 word1 前 i 个字母和 word2 前 j 个字母对齐时需要的最小操作数记为 align(i,j)
那么显然有边界条件
align(i,0) = i
align(0,j) = j

对齐到 align(i,j) 的来源可能是 align(i-1,j), align(i,j-1) 或者是 align(i-1,j-1)
显然，前两种来源都会导致操作数 +1 
最后一种只在 word1[i-1] 和 word[j-1] 不相等时 +1

即 
align(i,j) = min(align(i - 1, j) + 1, 
                 align(i, j - 1) + 1, 
                 align(i - 1, j - 1) + (word[i-1]==word[j-1] ? 0 : 1))

需要的记忆空间为 memo[1 ~ word1.length()][1 ~ word2.length()]
思路完成


递归写起来一般还是可能比DP更快一点的
执行慢就没辙力

### 代码

```java []
class Solution {
    public int minDistance(String word1, String word2) {
        a = word1; b = word2;
        memo = new Integer[a.length()] [b.length()];
        return align(a.length(), b.length());
    }

    private String a, b;
    private Integer[][] memo;
    private int align(int i, int j){
        if (i == 0){
            return j;
        }else if (j == 0){
            return i;
        }
        
        if (memo[i-1][j-1] == null){            
            memo[i-1][j-1] = Math.min(
                Math.min(align(i - 1, j), align(i, j - 1)) + 1,
                align(i - 1, j - 1) + (a.charAt(i-1) == b.charAt(j-1) ? 0 : 1));                        
        }
        return memo[i-1][j-1];
    }
}
```