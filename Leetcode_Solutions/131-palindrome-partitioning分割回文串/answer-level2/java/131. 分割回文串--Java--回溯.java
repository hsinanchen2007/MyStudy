### 解题思路
[Leetcode-Java(250+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_131_partition.java)

### 代码

```java
class Solution {
    /**
     * 解题思路：DFS遍历+回溯
     * 1、DFS遍历，从s的第一位开始，逐步判断至最后一位
     * 2、定义一个skip=1，从1开始，代表从当前位加上skip的结果是否是回文
     * 3、定义一个循环，位置从0开始，得到所有的结果
     *
     * 执行用时 :8 ms, 在所有 java 提交中击败了20.05%的用户
     * 内存消耗 :38.1 MB, 在所有 java 提交中击败了97.34%的用户
     *
     * @param s
     * @return
     */
    public List<List<String>> partition(String s) {
        List<List<String>> retList = new ArrayList<>();
        dfs(retList,new ArrayList<>(),s,0);
        return retList;
    }

    private void dfs(List<List<String>> retList, List<String> itemList, String s, int index) {
        if (index > s.length()-1){
            retList.add(new ArrayList<>(itemList));
            return;
        }
        int skip = 1;
        while (skip + index <= s.length()) {
            String sub = s.substring(index, index + skip);
            if (isPlalindrome(sub)) {
                itemList.add(sub);
                dfs(retList, itemList, s, index + skip);
                if (itemList.size() > 0) {
                    itemList.remove(itemList.size() - 1);
                }
            }
            skip++;
        }
    }

    //是否是回文
    private boolean isPlalindrome(String s) {
        int si = 0, ei = s.length() - 1;
        while (si < ei) {
            if (s.charAt(si) != s.charAt(ei)) return false;
            si++;
            ei--;
        }
        return true;
    }
}
```