![2020010601.PNG](https://pic.leetcode-cn.com/40cdea22073bdbc19d425798aa6f4e58a4a3688b224f9a6ecc3879ce4225ddb8-2020010601.PNG)

### 解题思路
利用大写字母和小写字母的ASCII码差值实现大小写字母的转换
### 代码

```java
class Solution {
    public String toLowerCase(String str) {
        String out = "";
        for(int i =0;i<str.length();i++) {
        	if(str.charAt(i)-'a'<0&&Math.abs(str.charAt(i)-'a')<=32&&Math.abs(str.charAt(i)-'a')>=7) {
        		out = out + (char)('a'+Math.abs(str.charAt(i)-'a'+32));
        	}else {
        		out = out + str.charAt(i);
        	}
        }
        return out;
    }
}
```