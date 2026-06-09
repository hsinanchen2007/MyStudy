```
class Solution {
    public int strStr(String haystack, String needle) {
        int i = 0;
		if (needle.equals("")) {
			return i;
		}
		if (haystack.contains(needle)) {
			for (int k =needle.length(); k < haystack.length(); k ++) {
				String temp = haystack.substring(0, k);
				if (temp.contains(needle)) {
					break;
				}
				i ++;
			}
		} else {
			return -1;
		}
		
		return i;
    }
}
```
