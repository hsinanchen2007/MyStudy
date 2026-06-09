// ### 解题思路
// 还是回溯，遍历树的每一个枝叶，每个把字符串分隔长度为1，2，3的，然后进行深度遍历，增加一些剪枝条件。

// 注意：
// 不能存在大于10以0开头的地址，比如  【0.1.0.010】,因为010这个以0开头，这个IP地址分的不正确。

// 总结：
// emmmmmmm,时间和空间复杂度都凑活吧，嘿嘿😋。

// ### 代码

// ```java
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        if (s.length() > 12) {
            return result;
        }
        getResult(s, 0, 0, 4, result, "");
        return result;

    }
    public  void getResult(String s, int start, int curDepth, int depth, List<String> result, String oneResult) {
        if (start >= s.length() && curDepth == depth) {
            result.add(oneResult.substring(0, oneResult.length()-1));
            return;
        }
        if (start < s.length() && curDepth == depth) {
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (start+i > s.length() || Integer.valueOf(s.substring(start, start+i)) > 255 || Integer.valueOf(s.substring(start, start+i)) < 0 || (s.substring(start, start+1).equals("0") && s.substring(start, start+i).length()>1)) {
                continue;
            }
            getResult(s, start+i, curDepth+1, depth, result, oneResult+s.substring(start, start+i)+".");
        }
    }
}
// ```