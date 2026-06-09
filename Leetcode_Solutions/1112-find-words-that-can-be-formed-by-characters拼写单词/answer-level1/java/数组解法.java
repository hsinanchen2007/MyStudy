### 解题思路
new int[26] 数组统计每个位置上的元素个数。
对于每一个单词，先新建一个数组统计好个数，再去判断是不是 chars 统计数组的子集，如果是，结果加上这个数组的值。
### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        // new int[26]
        int[] a = new int[26];
        for(int i = 0; i < chars.length(); i++) {
            ++a[chars.charAt(i) - 'a'];
        }
        int ans = 0;
        for(int i = 0; i< words.length; i++) {
            String cur = words[i];
            int[] target = new int[26];
            for(int j = 0; j < cur.length();j++) {
                int index = cur.charAt(j) -'a';
                ++target[index];
            }
            boolean isInclude = true;
            for(char c: cur.toCharArray()) {
                int curIndex = c - 'a';
                if(a[curIndex] < target[curIndex]) {
                    isInclude = false;
                    break;
                }
            }
            if(isInclude) {
                ans += cur.length();
            }
        }
        return ans;
    }
}
```