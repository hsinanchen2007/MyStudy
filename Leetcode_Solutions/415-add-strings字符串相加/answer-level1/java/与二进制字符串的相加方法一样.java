### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder sb = new StringBuilder();
		int jw =0;//是否进位
		for(int i=num1.length()-1,j=num2.length()-1;i>-1||j>-1;i--,j--) {
			int sum =0;
			sum+=i>-1?num1.charAt(i)-48:0;
			sum+=j>-1?num2.charAt(j)-48:0;
			sum+=jw;
			jw=sum/10;
			sb.append(sum%10);
		}
		if(jw>0) {
			sb.append(1);
		}
        return sb.reverse().toString();
    }
}
```