### 解题思路
就是需要处理一下首位的问题。长度的话可以最后看flag是否等于1来判断。并且如果长度加1那么一定首位是1.

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits){
        int flag = 0;
        if(digits.length == 0){
            int[] res = new int[1];
            res[0] = 1;
            return res;
        }
        digits[digits.length - 1] += 1;

        for(int i = digits.length - 1; i >= 0; i--){
            digits[i] += flag;
            if(digits[i] == 10){
                digits[i] = 0;
                flag = 1;
            }
            else{
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            return digits;
        else{
            int[] res = new int[digits.length+1];
            res[0] = 1;
            for(int i = 1; i < res.length; i++){
                res[i] = digits[i-1];
            }
            return res;
        }
    }
}
```