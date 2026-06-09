### 解题思路
Java中有现成的栈结构，但他底层也是用的数组实现，所以我们在本题中用数组实现一个简单的栈结构，效率应该会更好一些。
首先定义一个字符数组，长度为输入参数的长度；
然后定义一个指针，用来表示数据真实的容量；
遍历字符串：如果遇到左括号，就存进当前指针的位置；否则与指针前一位置字符比较，如果能匹配上，指针减一，相当于出栈；
最后判断指针是否归零。
### 代码

```java
import java.util.Vector;
class Solution {
    public boolean isValid(String s) {
        char[] cs=new char[s.length()];
		int count=0;
		for(int i=0;i<s.length();i++) {
			char c = s.charAt(i);
			if(c=='('||c=='{'||c=='[') {
				cs[count++]=c;
			}else {			
				if(count==0) {
					return false;
				}
				char cc=cs[count-1];
				String x=cc+""+c;
				if(x.equals("()")||x.equals("[]")||x.equals("{}")) {
					count--;
				}else {
					return false;
				}
			}
		}
		
		return count==0;

    }
}
```