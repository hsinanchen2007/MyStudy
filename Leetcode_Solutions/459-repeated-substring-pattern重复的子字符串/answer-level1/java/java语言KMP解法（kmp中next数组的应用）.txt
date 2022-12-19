时间复杂度为O(n)
```
class Solution {
    public boolean repeatedSubstringPattern(String s) {
		int len = s.length();
        if(len == 1) {
			return false;
		}
        
		int[] next = getNext(s);
		int k = next[len-1];
		if(len%(len-k) == 0 && k != 0) {
			return true;
		}
		return false;
		
	}

	private int[] getNext(String s) {
		int len = s.length();
		int[] next = new int[len];
		next[0] = 0;
		int pre = 0, cur = 1;
		
		while(cur < len) {
			if(s.charAt(cur) == s.charAt(pre)) {
				next[cur++] = ++pre;
			} else if(pre > 0){
				pre = next[pre-1];
			} else {
				next[cur++] = 0;
			}
		}
		return next;
	}
}
```
getNext()方法返回的数组 下标加一后 为KMP算法中的next数组。
