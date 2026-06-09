第一种 比较蠢的方法
```
class Solution {
    /**
     * (()
     * (()()
     * (()())
     * (()()()
     * @param s
     * @return
     */
    public int longestValidParentheses(String s) {
        int length = s.length();
        int[][] m = new int[length][length] ;
        // init
        for (int i =1;i<length;i++){
            if (match(s, i-1,i))
                m[i-1][i] = 2;
        }
        // step start  [start, start+step]
        for (int step=3;step<length;step+=2){
            for(int start=0;start+step<length;start++){
                // type1 连续成立
                int end = start+step;
                boolean match = false;
                for(int mid=start+1;mid<end;mid++){
                    if(m[start][mid]>0 && m[mid+1][end]>0){
                        match = true;
                        break;
                    }
                }
                // type2 内部成立
                if(!match && m[start+1][end-1]>0 && match(s, start, end)){
                    match = true;
                }
                if (match){
                    m[start][end] = end - start + 1;
                }
            }
        }
        // find max
        int max = 0;
        for (int i=0;i<length;i++){
            for (int j=0;j<length;j++){
                if (m[i][j] > max)
                    max = m[i][j];
            }
        }
        return max;
    }

    private boolean match(String s, int left, int right){
        if (s.charAt(left) == '(' && s.charAt(right) == ')')
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.longestValidParentheses("(()"));
        System.out.println(s.longestValidParentheses("(())"));
        System.out.println(s.longestValidParentheses("()()"));
        System.out.println(s.longestValidParentheses("(()()"));
        System.out.println(s.longestValidParentheses("(()())()"));
    }
}
```
第二种 然后我发现,没有必要用二维数组, 连续的字串中间必定全符合要求, 一维就可以

```
class Solution {
    /**
     * (()
     * (()()
     * (()())
     * (()()()
     * @param s
     * @return
     */
    public int longestValidParentheses(String s) {
        int length = s.length();
        int[] m = new int[length] ;
        // init
        for (int i =1;i<length;i++){
            if (match(s, i-1,i)) {
                m[i - 1] = 1;
                m[i] = 1;
            }
        }

        int last = -1;
        boolean goon = true;
        while (goon) {
            goon = false;
            for (int i = 0; i < length; i++) {
                if (m[i] == 1 && last == -1) {
                    last = i;
                } else if (m[i] == 1 || last == -1) {
                    // do nothing
                } else {
                    // 不是1了
                    int start = last - 1, end = i;
                    while (start >= 0 && end < length && start<end && m[start] == 0  && m[end] == 0 && match(s, start, end)) {
                        m[start--] = 1;
                        m[end++] = 1;
                        goon = true;
                    }
                    last = -1;
                    i = end - 1;
                }
            }
        }
        int max = 0,sum=0;
        for (int i=0;i<length;i++){
            if (m[i]==1){
               sum++;
            } else {
                if (sum > max){
                    max = sum;
                }
                sum = 0;
            }
        }
        if (sum > max){
            max = sum;
        }
        return max;
    }

    private boolean match(String s, int left, int right){
        if (s.charAt(left) == '(' && s.charAt(right) == ')')
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.longestValidParentheses(")))(()(())(()"));
//        System.out.println(s.longestValidParentheses("(())"));
//        System.out.println(s.longestValidParentheses("()()"));
//        System.out.println(s.longestValidParentheses("(()()"));
//        System.out.println(s.longestValidParentheses("(()())()"));
    }
}
```
