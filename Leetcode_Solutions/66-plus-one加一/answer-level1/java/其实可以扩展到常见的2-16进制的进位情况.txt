### 解题思路
由个位向最高位依次操作

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int length = digits.length;
        for (int i = length - 1; i >= 0; --i) {
            if (digits[i] == 9) {
                digits[i] = 0;   //等效于加了1，只不过是进位了，进位的操作流给下一次循环
            } else {
                digits[i] += 1;    //个位不是9，则代表个位加1；如果个位是9，则代表进位进的1
                break;
            }
        }
        int[] reve;
        if (digits[0] == 0) {      //表示最高位进位了，例如digits由99 --> 00
        /*如果程序员只指定了数组的长度，那么系统将负责为这些数组元素分配初始值。指定初始值时，系统按如下规则分配初始值。
            数组元素的类型是基本类型中的整数类型（byte、short、int 和 long），则数组元素的值是 0。
            数组元素的类型是基本类型中的浮点类型（float、double），则数组元素的值是 0.0。
            数组元素的类型是基本类型中的字符类型（char），则数组元素的值是‘\u0000’。
            数组元素的类型是基本类型中的布尔类型（boolean），则数组元素的值是 false。
            数组元素的类型是引用类型（类、接口和数组），则数组元素的值是 null。*/
            reve = new int[length+1];
            reve[0] = 1;
        } else {
            return digits;
        }
        return reve;

        //以下代码不适用数字超过long的整数
        /*long num = 0;
        for(int i = 0; i < digits.length; ++i){     //数组转为long类型整数
            num = num * 10  +  digits[i];
        }
        ++num;
        int len = (int) Math.log10(num) + 1;           //获取整数的位数(长度)
        int[] add = new int[len];
        int j = 0;
        while(num/10 != 0){                         //将整数依次存入新创建的数组中
            add[j++] = (int)(num % 10);
            num /= 10;
        }
        add[j] = (int)num ;
        int[] reve = new int[len];;
        for(int i = 0 ; i <= j ; ++i){//数组反转，，，若不想再创建数组，也可以直接第i位与第len-i-1位交换(条件为i<len/2)
            reve[i] = add[j - i];
        }
        return reve;*/
    }
}
```