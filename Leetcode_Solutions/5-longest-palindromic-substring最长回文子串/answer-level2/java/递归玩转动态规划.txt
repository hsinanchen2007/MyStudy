[LeeCode5\. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

这题是leeCode非常今典的一道题，他的最优解法是`Manacher算法`，可以实现O(N)的平均时间复杂度。这里要呈现此题的动态规划解答，不对最优的解法详细阐述，后面仅提供一下Manacher的代码。

那么正式开始，动态规划的题型，最主要的步骤就是如何快速的构造记忆dp数组，但是往往dp数组的建议并不是特别容易，需要我们理解所记录的状态的具体含义，会给接替带来较大的难度。

面对动态规划的题，我一般尝试用暴力递归的方式去进行尝试，然后在暴力递归的基础上用动态规划思想去优化，往往解题变得简单明了。

**新手上路，详细写一下自己的思路，文笔有限，一方面分享，另一方面也总结给自己复习，如果错误的地方，欢迎大神批评指证。**
1. 首先需要找出字符串中的最长回文子串，也就是返回字符串从0 - n (字符串长度)之间的最长回文子串,暴力递归尝试如下;
2. 情况一： 如果当前字符串的头尾字符相等，那么有可能整体都是回文字符。在进入判别条件。
      - 子情况一： 头尾各缩进一位的子字符串如果是回文串，那么整体的s就是最长的回文子串。
      - 子情况二： 头尾各缩进一位的字符串如果不是回文串，那么整体的s肯定不是回文串，将此处的情况当成下面第3点的情况考虑。
3. 情况二： 如果当前的字符串头尾字符不相等 ，那么当前的字符串肯定不是回文字符。所以当前字符串的最大回文子串可能出自两个地方。
    - 左边缩进一个字符后的字符串的最大回文字符串。
    - 右边缩进一个字符后的字符串的最大回文字符串。
4. 好了，经过上面的三个步骤，暴力递归的思想就出来了，那么递归还要考虑结束条件。
5. 当缩进步骤发生后，如果成了只有一个字符的字符串，那么肯定是回文串，返回即可。

6. 暴力版的暴力递归代码如下：
```
    // 最长回文子串的暴力递归解法
    public String longestPalindrome(String s) {
        // 直接暴力一点返回结果
        return getRes(s,0,s.length() - 1);
    }

    // 真正的技术在这里
    private String getRes(String s, int l, int r) {
        // 两个边界条件首先放上
        if(l == r) return s.charAt(l) + "";
        if(l > r) return  "";
        // 分析出来的情况一（如果两头都缩进后的最大回文子串长度不等于缩进后字符串，那么子字符串肯定也不是回文字符串）
        if (s.charAt(l) == s.charAt(r) && getRes(s,l+1,r-1).length() == r - l - 1) {
            return s.substring(l,r+1);
        }else{
            // 分析对应的情况er
            String s1 = getRes(s,l+1,r);
            String s2 = getRes(s,l,r-1);
            String ans = s1;
            // 返回较长的结果
            ans = ans.length() < s2.length() ? s2 : ans;
            return ans;
        }
    }

```
7. 走到这里基本思想已经有了，但是这个代码在LeeCode上面AC了39个案列就报了超时。那么下面就是要进行优化了，这里也就正式表现出了动态规划的强大之处，也可以更直观的理解暴力递归的操作逻辑。
8. 观察暴力递归的代码，我们可以发现当前的字符串的最大回文子串的求解，是在子问题的基础上分析得出来的，那么现在我们将子问题罗列出来：
      -  求缩进字符串左右各一个字符后的字符串的最大回文子串（问题一样，只是求解的对象变了，这就是递归的本质）
      - 求左边缩进一个字符后的字符串的最大回文子串。
      - 求右边缩进一个字符后的字符串的最大回文子串。
9. 在暴力递归中我们是不断的递归下去，从大问题深入到子问题，一路走到底，然后计算再一路回传，那么这其中就回带来大量的重复计算。
     - 举一个例子： 求解s[1 - 4]位置时可能会计算s[ 2 - 4 ]位置的最大回文字符串，然而当求解s[2 - 5]的字符串时，又有可能要重新计算了一遍s[2 - 4]位置的字符串。这个就是严重的重复计算。
10. 有了上面例子的解释，那么动态规划的优化工作之一就可以看出来了，存储重复计算的结果，我们用户一张表记录下s[2 - 4]的结果就可以了，当然这里如果用HashMap存储中间结果也是可以的，时间复杂会也会降低，但是效率还是没有动态规划好。
11. 回到题目，起始我们就可以看出几个简单的结果， 比如当` l == r , r > r`的结果我门可以直观的看出来，那么我们动态规划的思想就是从这里出发去推导大的问题。
12. 这里直接对着暴力递归的代码直接来进行动态规划，我们将暴力递归中的l指针，看作是二维数组的行数，r指针看作是数组的列数，那么一张边长为s长度的二维数组就创建出来了，存储的结果就是暴力递归中返回的结果，不难看出，如果要求某个格子的最大回文子串的时候，我们只需要他左边格子的信息，下面格子的信息，以及左下角格子的信息。那么下面的工作就是把这么一张二维数组中的每一个位置都填上元素就可以了。
13. 很显然，在遍历数组填元素之前，有一半以上的格子我们可以明确的知道它的值，比如 当l > r时，此格子填空字符串，l == r 时，此位置填上单个字符串。然后根据暴力递归的判断条件填格子。

填格子的代码如下：
```
    // 暴力递归改动态规划
    public String longestPalindrome2(String s){
        if(s.length() < 2) return s;
        int n = s.length();
        String[][] dp = new String[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if(i > j){
                    dp[i][j] = "";
                }else if(i == j) {
                    dp[i][j] = s.charAt(i) + "";
                }else if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1].length() == j - i - 1){
                    dp[i][j] = s.substring(i,j+1);
                }else{
                    // 找出三个之中最长的
                    String s1 = dp[i+1][j];    // 左边缩进一位的结果
                    String s2 = dp[i][j - 1];  // 右边缩进一位的结果
                    String cur = s1;
                    cur = cur.length() < s2.length() ? s2 : cur;
                    dp[i][j] = cur;
                }
            }
        }
        return dp[0][n - 1];
    }
```
14. 这里就是动态规划的雏形了，很可惜leeCode上运行还是超时，不过AC过了119个案例，大大提升了性能。好了，那么后面就是通用的二维表格优化了。分析一下时间都浪费在哪里，整体代码遍历二维数组肯定没问题，那么问题肯定出在了计算s1, s2的长度以及比较大小上面了。
15. 考虑到这里遍历的每一个i,j都是元素的起始位置，那么我们可以不用直接将返回结果存档在数组中，我们直接用一个boolean数组记录，当前的位置是不是回文串就行了。
    - 在之前分析的情况一下； 如果头尾各缩进一个字符后的子字符串是回文串，那么当前字符也是回文串，一但确定了一个字符串是回文串，那么就用i ，j 的索引去定下他的长度和起始位置，不断更新即可。
    - 在之前分析的情况二下，该位置不是回文串，那么没有利用价值，直接false即可，避免了之前的比较字符串长度的操作

优化后的代码如下：
```
    // 优化动态规划
    public String longestPalindrome3(String s){
        if(s.length() < 2) return s;
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int maxLen = 0;
        int maxS= 0;
        int maxE = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if(i > j){
                    dp[i][j] = true;
                }else if(i == j) {
                    dp[i][j] = true;
                }else if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(maxLen < (j - i)){
                        maxLen = j - i;
                        maxS = i;
                        maxE = j;
                    }
                }
                // 其他情况下全部置为false
            }
        }
        return maxLen == 0 ? s.substring(0,1) : s.substring(maxS,maxE + 1);
    }
```
16. 好了，走到这里，顺利AC了，这个就是整个DP的推理过程，我的理解动态规划就是在暴力递归的思想上优化出来的，动态规划的题目基本上都可以用这套思路解出来，熟练之后效果会非常明显。
17. 最后，动态规划问题还可以在空间上作出优化，将使用到的二维数组进行降维，这里的关键就是分析当前的格子是根据什么位置推导出来。可以看出当前的格子只跟左下角的格子是否为true有关，那么我们从右向左进行遍历更新数组，每次只需要用到左边的格子信息即可，便成功的进行降维。

代码如下：
```
    // 优化动态规划(继续优化)
    public String longestPalindrome4(String s){
        if(s.length() < 2) return s;
        int n = s.length();
        boolean[] dp = new boolean[n];
        int maxLen = 0;
        int maxS= 0;
        int maxE = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if(i > j){
                    dp[j] = true;
                }else if(i == j) {
                    dp[j] = true;
                }else if(s.charAt(i) == s.charAt(j) && dp[j-1]){
                    dp[j] = true;
                    if(maxLen < (j - i)){
                        maxLen = j - i;
                        maxS = i;
                        maxE = j;
                    }
                }else{
                    dp[j] = false;
                }
                // 其他情况下全部置为false
            }
        }
        return maxLen == 0 ? s.substring(0,1) : s.substring(maxS,maxE + 1);
    }

```
18. 同样这段代码也AC过了，时间成本上没什么改变，空间降了4M的内存，还是有非常明显的提升。

19. 补充： 不知不觉写了这么多，以上展示的最优版本的代码虽然AC了，但是运行时间复杂还是比较高，这是我能用DP方法做的最好的效果了，欢迎大神批评指证，下面就附上这道题的最优解法Manacher算法，不过多解释，以后在写一个Manacher笔记好好理解一下，这里也给自己打个样。
```
    public String longestPalindrome4(String s) {
        if(s.equals("")) return s;
        String ret = tackleString(s);
        int n = ret.length();
        int[] bj = new int[n];   // 存放每个位置的回文半径
        int maxR = -1;           // 存放当前的最大回文右边界
        int cC = -1;             // 存放当前最大回文右边界对应的回文中心
        // 遍历s字符串
        for (int i = 0; i < n; i++) {
            // 如果当前位置在最大回文右边界内，则在当前位置与右边界之间的距离和前半部分的回文半径中去最小值
            // 如果在边界或者maxR外边，默认半径为1，然后进行中心扩展
            bj[i] = maxR > i ? Math.min(maxR - i,bj[(2 * cC) - i]) : 1;
            // 中心扩展
            while(i - bj[i] >= 0 && i + bj[i] < n){
                if(ret.charAt(i - bj[i]) == ret.charAt(i + bj[i])){
                    bj[i]++;
                }else{
                    break;
                }
            }
            // 扩展结束之后，更新maxR和cC
            if(i + bj[i] > maxR){
                maxR = i + bj[i];
                cC = i;
            }
        }
        // 找出当前半径数组中的最大半径
        int maxLen = bj[0];
        int center = 0;
        for (int i = 1; i < bj.length; i++) {
            if(bj[i] > maxLen){
                maxLen = bj[i];
                center = i;
            }
        }
        // 有了最大的回文半径和最大的回文中心，返回字符串即可
        int start = (center - maxLen + 1) / 2;
        int end = (center + maxLen) / 2;
        return s.substring(start,end);
    }

    // 改造字符串————给字符串加上虚轴
    private String tackleString(String s) {
        int n = s.length();
        String ret = "#";
        for (int i = 0; i < n; i++) {
            ret += s.charAt(i) + "#";
        }
        return ret;
    } 
```