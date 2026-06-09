### 代码

```java
class Solution {
    public String gcdOfStrings(String str1,String str2){
		// 枚举法
		int length1 = str1.length();
		int length2 = str2.length();
		int maxLength = Math.max(length1, length2);
		for(int i=maxLength;i>=1;i--){
			if(length1%i==0 && length2%i==0){
				String X = str1.substring(0,i);
				if(check(str1,X) && check(str2,X)){
					return X;
				}
			}
		}
		return "";
	}
	
	public boolean check(String str,String substr){
		int lenx = str.length() / substr.length();
		String ans = "";
		for(int i=1;i<=lenx;i++){
			ans = ans + substr;
		}
		return str.equals(ans);
	}
}
```

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/5617091e9e2aa905ca63d0907225149f981729bba986cc84283995793052fbde-wechat.png)
