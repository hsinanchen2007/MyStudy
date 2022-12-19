### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> results = new ArrayList<>();
        if(s == null || s.length() == 0){
            return results;
        }

        dfs(s, 0, new ArrayList<>(), results);

        return results;
    }

    private void dfs(String s, int index, List<String> subsets, List<List<String>> results) {
        if(index == s.length()){
            results.add(new ArrayList<>(subsets));
        }
        for (int i = index; i < s.length(); i++) {
            String substring = s.substring(index, i + 1);
            if(!isPalindrome(substring)){
                continue;
            }
            subsets.add(substring);
            dfs(s, i + 1, subsets, results);
            subsets.remove(subsets.size() - 1);
        }
    }

    private boolean isPalindrome(String s) {
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != s.charAt(s.length() - 1 - i)){
                return false;
            }
        }
        return true;
    }
}
```