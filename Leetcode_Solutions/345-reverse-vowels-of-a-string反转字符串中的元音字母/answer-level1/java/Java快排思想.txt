```Java
package com.company;

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public String reverseVowels(String s) {
        char[] dicts = new char[]{'a', 'o', 'e', 'i', 'u', 'A', 'O', 'E', 'I', 'U'};
        List<Character> yuanyinList = new ArrayList<>();
        for (char temp : dicts) {
            yuanyinList.add(temp);
        }
        char[] newDicts = s.toCharArray();
        if (s.length() == 1) {
            return s;
        }
        int i = 0, j = s.length() - 1;
        while (i < j) {
            // 找到最左边的字母然后停下来
            while (i < j && !yuanyinList.contains(newDicts[i])) {
                ++i;
            }
            // 找到最右边的字母然后停下来
            while (i < j && !yuanyinList.contains(newDicts[j])) {
                --j;
            }
            // 两边都是元音字母
            if (i < j) {
                char temp = newDicts[i];
                newDicts[i] = newDicts[j];
                newDicts[j] = temp;
                i++;
                j--;
            }
        }
        return String.valueOf(newDicts);
    }
}
```
