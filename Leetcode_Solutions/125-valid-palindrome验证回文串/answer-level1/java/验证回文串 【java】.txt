### 解题思路

![image.png](https://pic.leetcode-cn.com/1e28edd7fa5b8b7f0e826d5cc774f1ecbaa31a9d71a17ba6a772f3759edb05a9-image.png)

写完自己的解答，又看了其他人的解答，感觉没我的简洁，思路清楚呀。就这样吧，先放着吧


--------------------------


看到这一题，首先想到去除标点符号，然后去除空格，转换为统一的大小写。

最后遍历字符串，如果出现不一致的情况则返回 false,

另外的返回 true;

感觉自己的代码已经写得很简洁了，不知道为什么只打败了18%的用户，醉了




### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
      	
		s=s.replaceAll("\\p{Punct}","");//完全清除标点
        
		s = s.replace(" ","").toLowerCase();//去除空格,并转换为小写
		
		for (int i =0; i < s.length() >> 1; i++) {
				
			if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
				return false;
			}	
			
		}
        
		return true;
    }
}
```