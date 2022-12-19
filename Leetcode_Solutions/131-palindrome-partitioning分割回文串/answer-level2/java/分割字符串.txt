### 解题思路
1. 解题思想是递归的方法，以第一个字符开始，考虑第一个字符后要不要切割，如果要，那就判断一下第一个字符到切割位置的字符串是否是回文串，如果不是，那就不能在这个位置切割，迭代去判断下一个位置；如果是的话，则将当前字符串放入暂存结果中，然后递归判断当前字符串的下一个字符。操作同上。
2. 直到当要判断的字符位置=s的长度时，说明我们已经将字符串s切割完，并且每个子字符串都为回文串，所以将暂存结果放入最终结果中。并将暂存结果中的最后一个字符串弹出，实现回溯操作，继续迭代。
3. 联系全排列的回溯方法，这种方法可以遍历所有的切割方案，所以结果能包含所有的回文串可能性。

### 代码

```java
class Solution {
    public List<List<String>> partition(String s) {
        if(s == null || s.length() == 0) return new ArrayList();
        List<List<String>> res = new ArrayList<>();
        List<String> r = new ArrayList<>();
        int length = s.length();
        boolean[][] isValid = new boolean[length][length];
        for(int i = 0; i < length; i++){
            prePro(s, i, i, isValid);
            prePro(s, i, i+1, isValid);
        }
        dp(s, 0, res, r, isValid);
        return res;
    }

    private void dp(String s, int first, List<List<String>> res, List<String> r, boolean[][] isValid){
        int length = s.length();
        if(first == length){
            res.add(new ArrayList(r));
            return;
        }
        for(int i = first; i < length; i++){
            if(!isValid[first][i]) continue;
            r.add(s.substring(first, i+1));
            dp(s, i+1, res, r, isValid);
            r.remove(r.size()-1);
        }
    }

    private void prePro(String s, int left, int right, boolean[][] isValid){
        while(left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)){
            isValid[left][right] = true;
            left--;
            right++;
        }
    }
}
```