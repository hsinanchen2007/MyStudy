### 解题思路
遍历字符串，没出现的字符就记录位置，一旦遇到了出现过的字母，就返回false

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        Map<Integer, Integer> counts = new HashMap<>(128);
        for (int i = 0; i < astr.length(); i++) {
            if (counts.get(Integer.valueOf(astr.charAt(i))) == null) {
                counts.put(Integer.valueOf(astr.charAt(i)), i);
            }else {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String leetcode = "leetcode";
        System.out.println(solution.isUnique(leetcode));
    }
}

```