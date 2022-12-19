### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        if (str.length() == 0) {
            return 0;
        }
        //用于记录结果
        StringBuilder result = new StringBuilder();
        char[] chars = str.toCharArray();
        //标记有没有出现正负号
        boolean flag = false;
        for (int i = 0; i < str.length(); i++) {
            //如果是' '并且result.length()==0去掉开始的' '如果result.length()>0说明开始' '出现在中间位置，则不需要continue；
            if(chars[i]==' '&&result.length()==0){
                continue;
            }
            //判断字符是否在'+'、'-'或0-9之间，如果没在这个范围直接跳出循环取结果
            if (chars[i] != '-' && chars[i] != '+' && (chars[i] < '0' || chars[i] > '9')) {
                break;
            }
            //如果字符是'-'或者'+'
            if (chars[i] == '-' || chars[i] == '+') {
                //如果已经出现过正负号，或者字符已经有记录，说明不满足直接跳出
                if (flag||result.length()>0) {
                    break;
                } else {
                    //如果没出现过'+''-'并且result.length()==0说明第一位的符号出现，放到result中
                    result.append(chars[i]);
                    flag = true;
                }
            } else {
                //如果是0-9的数字直接加入
                result.append(chars[i]);
            }

        }
        //如果result.length()==0或者只有'+'或'-'说明不满足直接返回0
        if (result.length()==0||"-".equals(result.toString()) || "+".equals(result.toString())) {
            return 0;
        }
        //使用double为了避免越界
        double d = Double.valueOf(result.toString());
        //判断边界
        if (d > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        } else if (d < Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        }
        return (int) d;
    }
}
```