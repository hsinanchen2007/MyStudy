### 解题思路
类似十进制转换为二进制的过程，在转换表中选择尽可能大的面值并输出，直到该数被分配完全之后输出字符串。

### 代码

```java
public class Solution {

    public String intToRoman(int num) {
        // 把阿拉伯数字与罗马数字可能出现的所有情况和对应关系，放在两个数组中
        // 并且按照阿拉伯数字的大小降序排列，这是贪心选择思想
        int[] nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        StringBuilder stringBuilder = new StringBuilder();
        int index = 0;
        while (index < 13) {
            // 特别注意：这里是等号
            while (num >= nums[index]) {  //如果num大于表中数据 则选用这个面值 即最大面值
                // 注意：这里是等于号，表示尽量使用大的"面值" 
                stringBuilder.append(romans[index]);    //加入要输出的字符串中
                num -= nums[index];                     //num值相对应的减去已输出的面值
            }
            index++;             //向后遍历后面的面值重复上述操作
        }
        return stringBuilder.toString();    //返回字符串
    }
}


```