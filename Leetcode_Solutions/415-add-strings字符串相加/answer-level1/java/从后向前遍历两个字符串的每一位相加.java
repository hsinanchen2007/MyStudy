### 解题思路
循环遍历，从num1、num2的后向前逐个获取对应的n1、n2的整数值，sum = n1+n2，sum/10即是进位，sum%10即是当前位的值，当前位的值就可以加入结果字符串，即res = (sum%10)+res,  上边的sum值还要加上上一次的进位。
遍历完num1和num2为止，循环结束。
注意：最后要判断一次进位是否大于0，如果大于0要加到结果字符串中。

### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int index1 = len1-1;
        int index2 = len2-1;
        String res="";
        int nextAdd = 0;
        while(index1 >=0 || index2 >=0){
            int n1 = index1>=0?Integer.valueOf(num1.substring(index1,index1+1)):0;
            int n2 = index2>=0?Integer.valueOf(num2.substring(index2,index2+1)):0;
            int sum = n1+n2+nextAdd;
            nextAdd = sum/10;
            int curAdd = sum%10;
            res = curAdd+res;
            index1--;
            index2--;
        }
        if(nextAdd>0){
            res = nextAdd+res;
        }
        return res;
    }
}
```