![2019122901.PNG](https://pic.leetcode-cn.com/75e28e9dad54784591869f81bb9d32c8e79d3775f878db6bc79bfeac7b3a2ef2-2019122901.PNG)

### 解题思路
声明一个新字符串来记录无效IP地址
### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
        String out ="";
    	for(int i = 0;i<address.length();i++) {
    		if(address.charAt(i)=='.') {
    			out = out +'[';
    			out = out +address.charAt(i);
    			out = out + ']';
    		}else if(address.charAt(i)!='.') {
    			out = out +address.charAt(i);
    		}
    	}
        return out;
    }
}
```