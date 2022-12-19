![image.png](https://pic.leetcode-cn.com/469f42333f31365ab3eb0fb562a97b86f69e198e6ee7c579fb98cbf739d2eb57-image.png)
按照题目要求直接模拟，简单粗暴。
构建一个char[][]来存字符串，然后按行读出。读的时候记一下最后一个非空字符的位置idx，如果最后一个空字符在idx之后，
那就截取到idx，否则不截取。
```
class Solution {
    public List<String> printVertically(String s) {
        String[] temp = s.split("\\s+");
        int maxLen = 0;
        for (String t:temp) {
        	if (t.length() > maxLen)
        		maxLen = t.length();
        }
        char[][] ans = new char[maxLen][temp.length];
        int i, j;
        for (i = 0; i < temp.length; i++) {
        	for (j = 0; j < temp[i].length(); j++)
        		ans[j][i] = temp[i].charAt(j);
        	while (j < maxLen) {
        		ans[j][i] = ' ';
        		j ++;
        	}
        }
        List<String> result = new ArrayList<String>();
        int idx = 0;
        for (int m = 0; m < maxLen; m++) {
        	StringBuilder sb = new StringBuilder();
        	for (int n = 0; n < temp.length; n ++) { 
        		sb.append(ans[m][n]);
        		if (ans[m][n] != ' ')
        			idx = n;
        	}
        	String tempSb = sb.toString();
        	if (tempSb.lastIndexOf(' ') > idx)
        		result.add(tempSb.substring(0, idx+1));
        	else
        		result.add(tempSb);
        }
        return result;
    }
}
```

