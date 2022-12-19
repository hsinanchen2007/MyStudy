先过滤掉数字和单词之外的字符，如果是回文串正序倒序应该相同
所以倒序比较一下就可以了（忽略大小写比较）
这里可以先把三个方法写好，也就是程序的思路，具体每一步代码的细节怎么实现不是很重要，也可以直接网上找，主要的是自顶向下的写题思路

```java
class Solution {
    public boolean isPalindrome(String s) {
        String filteredS = _filterNonNumberAndChar(s);//过滤掉数字和字符之外的
		
		String reversedS = _reverseString(filteredS);//倒序

		return reversedS.equalsIgnoreCase(filteredS);//忽略大小写比较
    }
    private String _reverseString(String str) {
		StringBuffer buffer = new StringBuffer(str);
		return buffer.reverse().toString();

	}

	private String _filterNonNumberAndChar(String s) {
		s = s.replaceAll("[^0-9a-zA-Z]","");
		return s;
	}
}
```