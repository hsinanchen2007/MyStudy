```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0) {
			return "";
		}
        if(strs.length == 1) {
			return strs[0];
		}
        if(strs[0].equals("")) {
			return "";
		}
        int l = strs.length;
		for(int i=0;i<strs[0].length();i++) {
			for(int j=1;j<l;j++) {
				if(strs[j].length() >= i+1) {
					if(strs[j].charAt(i) != strs[0].charAt(i)) {
						return strs[0].substring(0, i);
					}
				}else {
					return strs[0].substring(0, i);
				}
			}
		}
		return strs[0];
    }
}
```

首先校验三连：
1. 数组是否为空
2. 第一个字符串是否为空字符串
3. 如果只有一个字符串就原路返回

我们以数组中的第一个元素，即第一个字符串作为基准，后面的元素（字符串）挨个与此元素相比较，看当前第i个字符是否相同

如果相同，继续
如果不同，return strs[0].substring(0, i);
如果后面的字符串长度小于i+1，return strs[0].substring(0, i);

如果一顿比较还没return，那么第一个字符串一定是最长的（之一）

return strs[0];

