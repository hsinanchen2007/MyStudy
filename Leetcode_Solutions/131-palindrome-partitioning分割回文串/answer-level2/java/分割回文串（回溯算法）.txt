### 解题思路
套路写法，嘿嘿

### 代码

```java
class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        getResult(s, 0, result, new ArrayList<>());
        return result;
    }
    public void getResult(String s, int start, List<List<String>> result, List<String> oneResult) {
        if (start >= s.length()) {
            result.add(new ArrayList<>(oneResult));
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s.substring(start, i+1))) {
                oneResult.add(s.substring(start, i+1));
                getResult(s, i+1, result, oneResult);
                oneResult.remove(oneResult.size()-1);
            }
        }
    }
    private boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length()-1;
        while (left <= right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
```