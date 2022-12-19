**解法一：** 中心扩散法 + 双指针
    - 中心扩散法：遍历每一个中心，以这个中心往两边扩散，记录下以该中心扩散的最长回文子串。
    - 双指针法优化：以快指针和慢指针为起始中心。
 偶回文数：下图最长回文子串ADDA
![1.PNG](https://pic.leetcode-cn.com/cc98c2fa24004053dd7b6f80a52b7dcc2857dbf5e068b2fd9dea3239b7b31a1f-1.PNG)
奇回文数：下图最长回文子串ABA
![2.PNG](https://pic.leetcode-cn.com/f6f11a7785b3ac5068fb11dbaf13fd2a1a8d2bd55eb0a6ddb6eaa5222aecf246-2.PNG)
例子："asdadas"，先以0，1元素为中心，找出它的最大子回文串，再以0，2元素为中心，重复上述，再以1，2元素为中心，直至遍历结束。得到最大回文子串。

   ```     
    代码如下：
        class Solution {
    public String longestPalindrome(String s) {
        // 先转化为char数组
        char[] chars = s.toCharArray();
        int lenth = chars.length;
        
        if(lenth < 2 ) {
            return s;
        }
        // s初始化快指针和慢指针
        int quickPoint = 1;
        int slowPoint = 0;
        // 记录最长回文数的起始和结尾
        int[] arr = {0, 0};
        // 快指针大于等于字符串长度时，则循环结束
        while (quickPoint < lenth) {
            // 判断中心是否是回文数：是回文数，才调用方法找出以该中心扩散的最大回文子串。
            if(chars[slowPoint] == chars[quickPoint]) {
                isPalindrome(slowPoint,quickPoint,chars,arr);
            }
            // 当快指针-慢指针>1时，慢指针应当+1，
            if (quickPoint - slowPoint > 1) {
                slowPoint = quickPoint - 1;
                quickPoint--;
            }
            // 每次循环快指针+1
            quickPoint++;
        }
        // 返回最长回文子串
        return s.substring(arr[0],arr[1] + 1);
    }
    // 以快指针和慢指针为中心找出该中心的最大回文子串记录到arr数组中
     private  void isPalindrome(int slowPoint, int quickPoint, char[] chars, int[] arr) {
        while (chars[slowPoint] == chars[quickPoint]) {
            if(quickPoint - slowPoint + 1 > arr[1] - arr[0]) {
                arr[0] = slowPoint;
                arr[1] = quickPoint;
            }
            if(--slowPoint < 0 || ++quickPoint >= chars.length) {
                return;
            }
        }
    }
}
```
**解法二**：动态规划
- 状态：dp[j][i] 表示s[j-i]是否是回文子串，true：是，false：否。
- 初始化：当i==j时 dp[j][i] == true. 是回文子串。当s[i] == s[j], 且i - j <= 2, 是回文子串。
- 状态递推：由dp[j + 1][i - 1]==true && s[j] == s[i] ---> dp[j][i]==true 是回文子串
- 返回值 最长回文子串
- 容器 boolean[][] dp = new boolean[len][len] 相当于表 用于记录子问题中子串是否是回文数，避免重复计算。
```
 public String longestPalindrome(String s) {
        char[] chars = s.toCharArray();
        int len = chars.length;
        if(len < 2) {
            return s;
        }
        int begin = 0;
        int end = 0;
        int max = 1;
        boolean[][] dp = new boolean[len][len];
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if(chars[i] == chars[j]) {
                    if(dp[j + 1][i - 1] || i - j <= 2) {
                        dp[j][i] = true;
                        if(i - j + 1 > max) {
                            begin = j;
                            end = i;
                            max = end - begin + 1;
                        }
                    }
                }
            }
        }
        return s.substring(begin, end + 1);
    }
```
**综合分析：中心扩散比动态规划要快**
1. 比如 abca  中心扩散法已经知道bc不是回文子串，不会去判断abca是否是回文子串了。而动态规划不管bc是不是回文子串还是会继续判断abca是否是回文子串。
