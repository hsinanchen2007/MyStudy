### 代码

```java
class Solution {
    public String compressString(String S){
		// 一次遍历，时间复杂度为O(n)
		if(S.length() == 0){
			return "";
		}
		StringBuilder sb = new StringBuilder();
		char curr = S.charAt(0);
		int count = 1;
		sb.append(curr);
		for(int i=1;i<S.length();i++){
			if(S.charAt(i) == curr){
				count++;
			}else{
				sb.append(count);
				curr = S.charAt(i);
				sb.append(curr);
				count = 1;
			}
		}
		sb.append(count);
		
		String newStr = sb.toString();
		if(newStr.length()>=S.length()){
			return S;
		}
		return newStr;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/5561c0fef9eedb7aa10ab91250acd5eff93812790340be5a71d0931abdb7e222-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/22058cea70331afb8d3ddd24b4893e712e9a5a59cd28fe6b9d316ebea7f2bc92-wechat.png)
