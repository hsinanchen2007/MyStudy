## 解题思路
参考https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/优化竖式版解法

## 代码

```java
class Solution {
    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")){
            return "0";
        }
        int[] ans = new int[num1.length() + num2.length()];
        for(int i = num1.length() - 1; i >= 0; i --){
            for(int j = num2.length() - 1; j >= 0; j --){
                int n1 = num1.charAt(i) - '0';
                int n2 = num2.charAt(j) - '0';
                int sum = ans[i + j + 1] + n1 * n2;
                ans[i + j + 1] = sum % 10;
                ans[i + j] = ans[i + j] + sum / 10;
            }
        }
        /*时间复杂度为  17ms
        String res = "0";
        for(int k = 0; k < ans.length; k ++){
            if(k == 0 && ans[k] == 0){
                continue;
            }
            res += ans[k];
        }
        return res;
        */

        //时间复杂度  7ms
        StringBuilder res = new StringBuilder();
        for(int k = 0; k < ans.length; k ++){
            if(k == 0 && ans[k] == 0){
                continue;
            }
            res.append(ans[k]);
        }
        return res.toString();
    }
}
```