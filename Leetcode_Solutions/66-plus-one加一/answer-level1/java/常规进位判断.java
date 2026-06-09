### 解题思路

执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :35.4 MB, 在所有 Java 提交中击败了10.31%的用户

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        for(int i = len-1 ; i >= 0 ; i--){
            digits[i] += 1;
            if(digits[i] < 10){     //如果当前值小于0，则不存在进位的问题，直接更新后返回
                return digits;
            }else{      //否则，将当前位取10的模，然后继续进位
                digits[i] = digits[i]%10;
            }
        }
        //如果跳出了上面的for循环，代表整个数组需要进位，重新定义一个新数组，第一位设为1
        int[] ans = new int[len+1];
        ans[0] = 1;
        for(int i = 0 ; i < len ; i++){
            ans[i+1] = digits[i];
        }
        return ans;
    }
}
```