### 
若是R则把标准++ 若是L则--
当重回为0时则对应一个目标子串

###

```java
class Solution {
    public int balancedStringSplit(String s) {
    	int count = 0;
    	int total = 0;
        for(char ch : s.toCharArray())
        {
        	if(ch == 'R') ++count;
        	else --count;
        	if(count == 0) ++total; 
        }
        return total;
    }
}
```