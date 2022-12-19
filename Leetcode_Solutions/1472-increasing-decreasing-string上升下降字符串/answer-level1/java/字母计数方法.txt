### 解题思路
计算字母个数
依次从小到大 和 从大到小 append
### 代码

```java
class Solution {
    public String sortString(String s) {
        StringBuilder sb = new StringBuilder();
		int[] ch = new int[26];
        //对字符串中出现的字母进行计数
		for(char c : s.toCharArray()) {
			ch[c - 'a']++;
		}
		int low = 0;
		int high = 25;
		int idx = low;
		while(sb.length() != s.length()) {
            //缩短下边界
			while(ch[low] == 0) {
				low++;
			}
            //缩短上边界
			while(ch[high] == 0) {
				high--;
			}
			//从小到大加入
			while(idx <= high) {
				if(ch[idx] != 0) {
                    ch[idx]--;
					sb.append((char)(idx+'a'));
				}
				idx++;
			}
            //越界修正
			idx--;
            //从大到小加入
			while(idx >= low) {
				if(ch[idx] != 0) {
                    ch[idx]--;
					sb.append((char)(idx+'a'));
				}
				idx--;
			}
            //越界修正
			idx++;
		}
		
		return sb.toString();
    }
}
```