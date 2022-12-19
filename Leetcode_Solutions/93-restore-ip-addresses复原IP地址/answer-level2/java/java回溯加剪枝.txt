```
public class Solution {

    public List<String> restoreIpAddresses(String s) {

        List<String> ans = new ArrayList<>();
        if (s == null || s.isEmpty() || s.length() < 4) {
            return ans;
        }

        dfs(ans, s, "", 0, 0, s.length() - 1);
        return ans;
    }

    private void dfs(List<String> ans, String s, String temp, int count, int start, int end) {

        if (count == 4) {
            if (start > end) {
                ans.add(new String(temp.substring(0, temp.length() - 1)));
            }
            return;
        }

        for (int i = start; i <= end && start + 3 > i; i++) {
            String substring = s.substring(start, i + 1);
            if (checkValidIp(substring)) {
                dfs(ans, s, temp + substring + ".", count + 1, i + 1, end);
            }
        }

    }

    public boolean checkValidIp(String str) {

        int m = str.length();
        if (m > 3) {
            return false;
        }
        if (str.charAt(0) == '0') {
            return m == 1;
        }
        return Integer.valueOf(str) <= 255;

    }
```

我们知道,ip地址会被逗号分隔为4部分,每部分都是大于等于0小于等于255,注意不能出现011,01这种的格式,
checkValidIp方法用于判断每一段是不是符合要求的ip地址格式。
所以回溯的时候记录下已经添加了几部分,发现添加了4部分并且正好到达字符串末尾的时候,就将产生的结果添加结果列表。
dfs方法用于回溯。