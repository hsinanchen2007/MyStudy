### 解题思路
其实就是逻辑性强一点,代码如下

### 代码

```java
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {

		StringBuffer sb = new StringBuffer();
		List<String> list = new ArrayList<>();
		sb.append(words[0]);
		for (int i = 1; i < words.length; i++) {

			if (sb.length() + words[i].length() + 1 <= maxWidth) {
				sb.append(" ");
				sb.append(words[i]);
			} else {

				while (sb.length() < maxWidth) {
					int j = 1;
                    boolean single=true;
					while (j < sb.length()) {
						if (sb.charAt(j) != ' ' && sb.charAt(j - 1) == ' ') {
                            single=false;
							sb.insert(j, ' ');
							j++;
						}
						if (sb.length() == maxWidth) {
							break;
						}
						
                        if(single&&j==sb.length()-1){

while (sb.length() < maxWidth) {
			sb.append(" ");
		}
        break;
                        }j++;
					}
				}
//				System.out.println(sb.toString());
				list.add(sb.toString());
				sb = new StringBuffer(words[i]);
			}

		}
		while (sb.length() < maxWidth) {
			sb.append(" ");
		}
		list.add(sb.toString());
		return list;
	}
}
```