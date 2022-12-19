### 解题思路
1.识别现有字符串能够组成的ip，就是将现有字符串分隔成合法的四段ip，长度在4至12位之间。0.0.0.0~255.255.255.254
2.识别所有可能的组合，这种套路是采用回溯。
用backTrack(String s, int start, int deep, ArrayList<String> curIp)，start记录当前开始判定的索引，deep记录当前判定的第几个ip段，curIP保存之前已经加入的合法的ip段。
3.如何回溯呢?回溯的结束条件：加入队列的四段ip的长度等于s字符串的长度并且DEEP了4次（4段）。
4.从索引0开始，每段只需要3个字符(255),判定是否为合法的数字，合法则继续下一个点的DEEP的计算。
5.清除当前队列的最后一个。

### 代码

```java
class Solution {
  private static final String DELIMITER = ".";
    private List<String> res = new ArrayList<>();
    private static final int MAX_DEEP = 4;
    private static final int MAX_PERIOD = 3;

    public List<String> restoreIpAddresses(String s) {
        if (s.length() < MAX_PERIOD || s.length() > MAX_PERIOD * MAX_DEEP) {
            return Collections.emptyList();
        }

        backTrack(s, 0, 0, new ArrayList<String>());
        return res;
    }

    /**
     * 回溯查找合法的ip
     *
     * @param s     字符串
     * @param start 开始位置
     * @param deep  深度，最大为4，因为ip是四段
     * @param curIp 当前ip段
     */
    private void backTrack(String s, int start, int deep, ArrayList<String> curIp) {
        int len = s.length();

        // 最后一层的时候需要判定当前ip是否合法
        if (len == start && deep == MAX_DEEP) {
            res.add(String.join(DELIMITER, curIp));
            return;
        }

        String str;
        int remainLen = (MAX_DEEP - deep) * MAX_PERIOD;

        for (int i = start; i < start + 3 && i < len; i++) {
            str = s.substring(start, i + 1);
            if (isValidNum(str) && (len - i) <= remainLen) {
                curIp.add(str);
                backTrack(s, i + 1, deep + 1, curIp);
                curIp.remove(curIp.size() - 1);
            }
        }
    }

    private boolean isValidNum(String str) {
        if (str.length() > MAX_PERIOD || str.length() == 0) {
            return false;
        }
         // 需要增加一个开始字符为零，但是长度不为零的判定，因为parseInt会把“010”解析成“10”，判定就会出错
        if ('0' == str.charAt(0) && str.length() != 1) {
             return false;
        }

        int num = Integer.parseInt(str);
        if (num >= 0 && num <= 255) {
            return true;
        }

        return false;
    }
}
```