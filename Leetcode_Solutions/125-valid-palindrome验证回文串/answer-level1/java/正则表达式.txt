### 解题思路
利用正则表达式去精简字符串之后将其放进ArrayList里进行判断

### 代码

```java
class Solution {
public boolean isPalindrome(String s) {
		String str=s.replaceAll("[\\pP\\pZ\\pS\\pM\\pC‘ ’“'”]", "").toLowerCase();
		ArrayList list = new ArrayList();
		for (int i = 0; i < str.length(); i++) {
			list.add(str.charAt(i));
		}
		ArrayList<String> listCopy = new ArrayList<String>(list);  
		Collections.reverse(listCopy);
		for (int i = 0; i < str.length(); i++) {
			if(!list.get(i).equals(listCopy.get(i))) {
				return false;
			}
		}
		return true;
	}
}

```