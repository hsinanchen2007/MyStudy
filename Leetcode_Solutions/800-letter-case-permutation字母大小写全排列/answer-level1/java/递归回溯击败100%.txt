```java
class Solution {
    public List<String> letterCasePermutation(String S) {
        ArrayList<String> list = new ArrayList<>();
        dfs(S.toCharArray(), 0, list);
        return list;
    }

    private void dfs(char[] arr, int i, ArrayList<String> list) {
        if (i == arr.length) {
            list.add(String.valueOf(arr));
            return;
        }
            if (isLetter(arr[i])) {
                // 转化为小写
                arr[i] |= 32;
                dfs(arr, i + 1, list);
                // 转化为大写
                arr[i] &= -33;
                dfs(arr, i + 1, list);
            } else {
                dfs(arr, i + 1, list);
            }
    }
    private boolean isLetter(char c) {
        return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }
}
```