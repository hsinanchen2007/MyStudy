### 解题思路
十进制的话是0-9，这里如果看做是26进制则 范围 确实1-26,也就是 将整数转换为字符串的时候需要减1处理。
同理要考虑如果是26的话，取模的话会是0，则需要向商借用来表示这种特殊情况


### 代码

```java
class Solution {
    public String convertToTitle(int n) {
        int count = n;
        StringBuffer chars=new StringBuffer();
        while(count > 0){
            int num = count%26;
            count = count/ 26;
            if(num == 0){
                num = 26;
                count -= 1;
		    }
            chars.insert(0,(char)(65 + num -1));
        }
        return chars.toString();
    }
}
```