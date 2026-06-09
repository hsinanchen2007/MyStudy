第一种Python解法：**添加一个辅助元素，避免了`需要单独判断`。**

第二种Java解法：**快慢指针,`i为慢指针， j为快指针`。很巧妙的把慢指针和快指针的值进行比较。**



```Python3 []
class Solution:
    def compressString(self, S: str) -> str:
        ans = ""
        S += " "
        count = 1
        for i in range(1, len(S)):
            if S[i] != S[i-1]:
                ans += S[i-1] + str(count)
                count = 1
            else:
                count += 1
        return ans if len(ans) < len(S)-1 else S[:-1]
```
```Java []
class Solution {
    public String compressString(String S) {
        StringBuffer sb = new StringBuffer();
        int i = 0;
        while (i < S.length()) {
            int j = i + 1;
            while (j < S.length() && S.charAt(i) == S.charAt(j)) {
                j ++;
            }
            sb.append(String.valueOf(S.charAt(i)) + String.valueOf(j - i));
            i = j;
        }
        return sb.toString().length() < S.length() ? sb.toString() : S;
    }
}
```