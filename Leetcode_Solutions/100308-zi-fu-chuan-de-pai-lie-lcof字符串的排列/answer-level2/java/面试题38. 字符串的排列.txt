### 题目
面试题38. 字符串的排列
输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]

### 解题思路
回溯算法：
注意点：
采用数组做标记比使用哈希做标记快很多


### 代码

```java
class Solution {
    Set<String> set2 = new HashSet<>();
    int count = 0;

    public String[] permutation(String s) {

        if (s.length() == 0) {
            return new String[0];
        }
        
        char[] stringArr = s.toCharArray();
        String now = "";
        // Set<Integer> set = new HashSet<>();
        int[] visited = new int[stringArr.length];
        
        for (int i=0; i<stringArr.length; i++) {
            visited[i] = 1;
            addCount(now + stringArr[i], 1, stringArr.length, stringArr, visited);
            visited[i] = 0;
        }
        
        String[] strs2 = new String[count];
        Iterator<String> iterator = set2.iterator();
        for (int i=0; i<count; i++) {
            strs2[i] = iterator.next();
        }
        return strs2;
    }

    public void addCount(String now, int depth, int length, char[] stringArr, int[] visited) {

        if (depth == length) {
            if (!set2.contains(now)) {
                set2.add(now);
                count++;
            }
            return;
        }
        for (int i = 0; i<length; i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                addCount(now + stringArr[i], depth+1, length, stringArr, visited);
                visited[i] = 0;
            }
        }
        
        return;
    }
}
```