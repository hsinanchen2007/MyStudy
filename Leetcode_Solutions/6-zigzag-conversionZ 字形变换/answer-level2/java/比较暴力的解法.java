### 解题思路
此处撰写解题思路
找到Z字自上而下的规律挨个遍历字符串
### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        String str[][] = new String[numRows][s.length()];
        int count = 0;
        for (int i=0; i<s.length();) {
            if(i == 0) {
                for (int j=0; j<numRows; j++) {
                    str[j][0] = s.charAt(j)+"" ;
                    i++;
                    if (i == s.length()) {
                        break;
                    }
                }
                count ++;
            } else if(i == ((2*numRows-2)*count) && i != 0) {

                for (int j=0; j<numRows; j++) {
                    str[j][count*(numRows-1)] = s.charAt(i) +"";
                    i++;
                    if (i == s.length()) {
                        break;
                    }
                }
                count ++;
            } else {
                int start = (numRows-1)*(count-1) + 1;
                for (int j=numRows-2; j>= 1; j--) {
                    str[j][start] = s.charAt(i)+"";
                    start ++;
                    i ++;
                    if (i == s.length()) {
                        break;
                    }
                }
            }

        }

        String result = "";
        for (int i = 0; i < str.length; i++) {
            String[] c = str[i];
            for (int j=0; j<c.length; j++) {
                if(c[j] == null) {
                    continue;
                }
                result += c[j];
            }
        }

        System.out.println(result);
        return result;
    }
}
```