看提示的意思，作者可能想将num的所有可能构造一个Trie树进行处理，这样每一次单词的查询差不多是`O(N)`，N为单词长度。

但是没有必要，直接**每个位置字母与该位置的数字相减，然后判断差值是否在[0,3)之间(7和9在[0,4)之间])**，这样也是`O(N)`的时间复杂度
~~~java
import java.util.LinkedList;
import java.util.List;

class Solution {
    final static int[] diffs = new int[]{3, 3, 3, 3, 3, 3, 4, 3, 4};
    final static char[] letters = new char[]{'!', 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};

    public List<String> getValidT9Words(String num, String[] words) {
        List<String> ans = new LinkedList<>();
        label:
        for (String word : words) {
            if (num.length() != word.length()) continue;
            for (int i = 0; i < num.length(); i++) {
                int index = num.charAt(i) - '1';
                int diff = word.charAt(i) - letters[index];
                if (diff < 0 || diff >= diffs[index]) {
                    continue label;
                }
            }
            ans.add(word);
        }
        return ans;
    }
}
~~~