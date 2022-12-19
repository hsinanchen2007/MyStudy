### 代码

```java
class Solution {
    public String countAndSay(int n){
		if(n == 1){
			return "1";
		}else if(n == 2){
			return "11";
		}
		String str = countAndSay(n-1);
		char pre = str.charAt(0);
		int count = 1;
		StringBuilder sb = new StringBuilder();
		for(int i=1;i<str.length();i++){
			char curr = str.charAt(i);
			if(curr==pre){
				count++;
			}else{
				sb.append(count);
				sb.append(pre);
				count = 1;
				pre = curr;
			}
		}
		sb.append(count);
		sb.append(pre);
		return sb.toString();
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/ee2a7380e94205e49e4c00dccee57770660312e873323b81943725d1a74cc578-1.png)
