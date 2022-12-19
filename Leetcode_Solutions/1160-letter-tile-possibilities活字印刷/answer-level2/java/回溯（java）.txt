### 解题思路
类似全排列，利用set去重


### 代码

```java
class Solution {
    public int numTilePossibilities(String tiles) {
        if(tiles == null || tiles.length() == 0){
            return 0;
        }
        char[] ch = tiles.toCharArray();
        boolean[] used = new boolean[tiles.length()];
        Set<String> set = new HashSet<>();
        backtrack(ch, set, new StringBuilder(), used);
        return set.size();
    }
    public void backtrack(char[] ch, Set<String> set, StringBuilder sb, boolean[] used){
        for(int i=0; i<ch.length; i++){
            if(used[i]){
                continue;
            }
            sb.append(ch[i]);
            set.add(sb.toString());
            used[i] = true;
            backtrack(ch, set, sb, used);
            used[i] = false;
            sb.deleteCharAt(sb.length()-1);
        }
    }
}
```