
这道题一开始思路想用模拟，即遍历每一个字符digit，将前一个字符digit对应string按照字符拆分为string, 加入一个队列中。这样前一个字符对应的可能的结果就已经在队列中了。再执行一个循环，依次出队列，将结果和后一个digit对应的字符加入一个新队列。

上面的实现蛮复杂的，其实这个问题也存在子问题。即一个字符串str的结果，等于 str[0:len-2]的结果 × str[len-1]

暂存前len-1个字符组成的字符串结果List<String>, 然后结合最后一个digit对应的字符串，就可以组成最终结果。

```
class Solution {

    private static Map<Character, String> dicts = new HashMap<>();
    static {
        dicts.put('2', "abc");
        dicts.put('3', "def");
        dicts.put('4', "ghi");
        dicts.put('5', "jkl");
        dicts.put('6', "mno");
        dicts.put('7', "pqrs");
        dicts.put('8', "tuv");
        dicts.put('9', "wxyz");
    }

    private static List<String> res = new ArrayList<>();

    public List<String> letterCombinations(String digits) {
        return backtrack(digits);
    }

    public List<String> backtrack(String remains) {
        if ("".equals(remains)) {
            return new ArrayList<String>();
        }
        if (remains.length() <= 1) {        
            List<String> tm =  new ArrayList<>();
            String mapedValue = dicts.get(remains.charAt(0));
            // 对于mapedValue中的每一个字符都可能组成
            char[] chs = mapedValue.toCharArray();
            for (int i=0; i<chs.length; i++) {
                tm.add(String.valueOf(chs[i]));
            }
            return tm;
        } else {
             List<String> tm =  backtrack(remains.substring(0,remains.length()-1));
              List<String> tm2 =  new ArrayList<>();
            String mapedValue = dicts.get(remains.charAt(remains.length()-1));
              char[] chs = mapedValue.toCharArray();
            for (int i=0; i<chs.length; i++) {
                for (String iter : tm) {
                    tm2.add(iter + String.valueOf(chs[i]));
                }
            }
            return tm2;
        }
    }
}
```