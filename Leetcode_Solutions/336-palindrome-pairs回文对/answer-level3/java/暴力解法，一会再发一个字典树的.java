### 解题思路
暴力破解
### 代码

```java
/*
 * Copyright (c) 2020
 * Author: xiaoweixiang
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        // 只想到了暴力解法 o n^2
        List<List<Integer>> resList = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
            for (int j = i+1; j < words.length; j++) {
                if (isPalindrome(words[i],words[j])) {
                    resList.add(Arrays.asList(i, j));
                }
                if (isPalindrome(words[j],words[i])) {
                    resList.add(Arrays.asList(j,i));
                }
            }
        }
        return resList;
    }

    private boolean isPalindrome(String s, String s1) {
        String s2=s+s1;
        int i=0;
        int j=s2.length()-1;
        while (i<j){
            if (s2.charAt(i)!=s2.charAt(j)) return false;
            i++;j--;
        }
        return true;
    }
}

```