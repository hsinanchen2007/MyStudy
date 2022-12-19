### 解题思路
前面的代码就是判断，然后连接到新的字符串上
而怎么判断一个字符串是否越界。是个问题

我输入很大的数字，运行的时候就发现了异常，由此，就想在异常处理中再处理这个字符串不就好咯
当发生异常时，虽然不能直接判断向上越界、还是向下越界，但是只有这两种情况
所以，只需判断这个字符串的首个字符是什么，就可以知道是什么越界了，然后再处理

感觉这个方法还不错嘛，哈哈哈！！！

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        int result = 0;
        StringBuilder stringResult = new StringBuilder();
        char temp;
        boolean haveDigit = false;
        boolean exist = false;

        for (int i = 0 ; i <str.length() ; i++) {
            temp = str.charAt(i);
            if (temp == ' ' && !haveDigit && !exist) {
                // 不处理
            } else if ((temp == '-' || temp == '+' ) && !haveDigit && !exist) {
                stringResult.append(temp);
                exist = true;
            }else if (Character.isDigit(temp)) {
                stringResult.append(temp);
                haveDigit = true;
            } else {
                break;
            }
        }
        boolean isMax = false;
        boolean isMin = false;

        try {
            if (!stringResult.toString().equals("")) {
                result = Integer.parseInt(stringResult.toString());
            }
        } catch (Exception e) {
            // 忽略异常
            // 然后判断是正数还是负数，排除只有单个符号的情况
            if (stringResult.charAt(0) == '+' || Character.isDigit(stringResult.charAt(0))) {
                if (stringResult.length() > 1) {
                    isMax = true;
                }

            } else if (stringResult.charAt(0) == '-') {
                if (stringResult.length() > 1) {
                    isMin = true;
                }
            }
            // 转换
            if (isMax) {
                result = Integer.MAX_VALUE;
            } else if (isMin){
                result = Integer.MIN_VALUE;
            }
        }
        return result;
    }
}
```