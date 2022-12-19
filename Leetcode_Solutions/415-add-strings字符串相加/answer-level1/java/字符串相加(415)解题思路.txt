### 解题思路
用变量strResult来记录所有的相加结果
用变量iResult来记录相同位数的相加结果。以88 + 56为例：
1.从最末位开始相加 iResult += (8+6) = 14。 
这时需要将iResult%10 = 4 存入strResult中。strResult = "4" 。又因为iResult = 14 大于10。 iResult = iResult/10 = 1
2. 从倒数第二位开始相加 iResult += (8+5) = 14。 
这时需要将iResult%10 = 4. 存入strResult中。strResult = "44" 。又因为iResult = 14。 iResult = iResult/10 = 1
3.此时相加结束，但是iResult为1，所以将iResult = 1 存入strResult中。strResult = "441"
4. 将strResult反转为"144"即为最终结果

### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder strResult = new StringBuilder();
        int iResult = 0;
        int i = num1.length()-1;
        int j = num2.length()-1;
        while(i >= 0 || j >= 0 || iResult != 0)
        {
            if(i>=0) 
            {
                iResult += num1.charAt(i)-'0';
                i--;
            }
            if(j>=0) 
            {
                iResult += num2.charAt(j)-'0';
                j--;
            }
            strResult.append(iResult%10);
            iResult /= 10;
        }
        return strResult.reverse().toString();
    }
}
```