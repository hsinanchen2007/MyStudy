### 解题思路
此处撰写解题思路
基本思路：先判断是否存在这样的字符串，再用辗转相除法，得到最大公因子的长度
细节部分：==比较引用值，equals()比较两个对象的值
### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // 判断是否存在
        if (!(str1 + str2).equals(str2 + str1)){
            return "";
        }else{
            int length = gcd(str1.length(),str2.length());
            return str1.substring(0,length);
        }
    }
    //辗转相除法
    private int gcd(int a, int b){
        if (b == 0){
            return a;
        }else{
            return gcd(b, a%b);
        }
    }

}
```