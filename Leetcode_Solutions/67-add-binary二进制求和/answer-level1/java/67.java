### 解题思路
此处撰写解题思路
![二进制求和-67.png](https://pic.leetcode-cn.com/aa4876b21ac0bd7648df38c64890238f15dfe1d51c93ec315a1f716d5466ba88-%E4%BA%8C%E8%BF%9B%E5%88%B6%E6%B1%82%E5%92%8C-67.png)

### 代码

```java
    class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();     
        int aLength = a.length();
        int bLength = b.length();
        int max = Math.max(aLength, bLength);
        StringBuilder ar = new StringBuilder(a).reverse();  //反转a，b
        StringBuilder br = new StringBuilder(b).reverse();
        //是否进位
        boolean isCarry = false;
        for (int i = 0; i < max; i++) {             //对齐两个字符串，不够的位数在后面补0
            char aChar = i >= aLength ? '0' : ar.charAt(i);
            char bChar = i >= bLength ? '0' : br.charAt(i);
            if (aChar == '1' && bChar == '1') {      //两个1相加 进位设为true
                sb.append(isCarry ? '1' : '0');
                isCarry = true;
            } else if (aChar == '0' && bChar == '0') {  //两个0相加 进位设为false
                sb.append(isCarry ? '1' : '0');
                isCarry = false;
            } else {
                sb.append(isCarry ? '0' : '1');     
            }
        }
        if (isCarry) sb.append("1");
        return sb.reverse().toString();    //再次反转得最终结果
    }
}


```