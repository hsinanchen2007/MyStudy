### 写在前面
方法一：可以直接调用java.lang.String包自带的函数方法replace(CharSequence target, CharSequence replacement)

方法二：创建一个StringBuilder对象通过遍历字符串将字符串的字符拼接起来，遇到空格着拼接“%20”即可

提示：这两种方法对内存的消耗几乎一样

### 代码

```java
class Solution {

	// 方法一：
    public String replaceSpace(String s) {
		return s.replace(" ", "%20");
    }


	// 方法二：
    public String replaceSpace(String s) {
        StringBuilder sb = new StringBuilder();
		for(int i = 0;i<s.length();i++) {
			if(s.charAt(i) == ' ') {
				sb.append("%20");
			}else {
				sb.append(s.charAt(i));
			}
		}
		return sb.toString();
    }
}
```


