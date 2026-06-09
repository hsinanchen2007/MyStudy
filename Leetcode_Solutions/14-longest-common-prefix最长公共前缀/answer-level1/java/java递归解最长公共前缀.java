使用递归循环遍历并筛选
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        boolean b = true;
		String s0 = "";
		if (strs.length == 0) return "";
		if (strs.length == 1) return strs[0];
		if (strs.length>1) {
			s0 = strs[0];
			List<String> list = new ArrayList();
			haha(strs,s0,1,b,list);
			if (list.size() == 0) return "";
			return list.get(0);
		}else {
			return strs[0];
		}
    }
  
  private static void haha(String[] strs, String s0, int a, boolean b, List<String> list) {
		for (int i = a; i < strs.length; i++) {
            String string = strs[i];
            if (!string.startsWith(s0)) {
                s0 = s0.substring(0, s0.length()-1);
                a = i;
                b = false;
                haha(strs, s0, a, b, list );
                break;
            }
            b = true;
            if (b && i == strs.length-1) {
                list.add(s0);
            }
        }
	}
}
```
