### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/641bed1f28e4ecdd436be53d902b3f52eb3a8dcb48863587c58b1bc98d92f296-image.png)
![image.png](https://pic.leetcode-cn.com/bc694c37ddfb50e3d2cda2128ae19fb8729f9125116b76adf2e2709cd612b7eb-image.png)

### 代码

```java
class Solution {
  
  public int myAtoi(String str) {
        String result = "";
        //去掉两边空字符
        str = str.trim();
        //初始检查
        if (null == str || str.equals("")) {
            return 0;
        }
        //是否可以用正则代替
        if (str.indexOf("+-") + str.indexOf("-+") +
                str.indexOf("+ ") + str.indexOf("- ") +
                str.indexOf("+0 ") + str.indexOf("-0 ") > 0
        ) {
            return 0;
        }

        //定义满足条件的字符
        List<Character> lists = Arrays.asList(new Character[]{'-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});
        for (int i = 0; i < str.length(); i++) {
            Character character = Character.valueOf(str.charAt(i));
            //如何判断空字符或者空格
            if ((character.charValue() == '+' && i == 0)) {
                continue;
            } else if (Character.isSpaceChar(character) || !lists.contains(character)
                    || (character.charValue() == '-' && i != 0)) {
                //中间有空格，直接break掉，后面的数据不在读取
                break;
            }
            result += character.toString();
        }
        //这里要避免处理后结果中是空字符串，是-，不是-打头的负数，还有多个段横杠问题
        result = result.equals("") ||
                result.equals("-")
                ? "0" : result;
        if (result.lastIndexOf("-") + result.lastIndexOf("+") > -1) {
            result = result.substring(0, result.length() - 1);
        }
        //如何确定数字已经超过了32位Integer的范围
        //先转换成比integer更大范围的数据类型Long
        Double temp = new Double(result);
        if (temp.longValue() > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        } else if (temp.longValue() < Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        } else {
            return temp.intValue();
        }
    }
}
```