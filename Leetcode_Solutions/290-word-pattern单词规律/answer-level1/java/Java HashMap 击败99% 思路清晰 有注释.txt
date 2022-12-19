# 哈希表


```
class Solution {
    public boolean wordPattern(String pattern, String str) {
        // 记录匹配
        HashMap<Character, String> match = new HashMap<Character, String>();  
        // 记录已经出现过的值
        HashSet<String> appear = new HashSet<String>();
        String[] words = str.split(" ");
        
        if( pattern.length() != words.length ) {
            return false;
        }
        
        int N = pattern.length();
        for( int i = 0; i < N; i++ ) {
            Character p = pattern.charAt(i);
            String curWord = words[i];
            String m = match.getOrDefault(p, null);
            // 如果这个key没有出现过，但这个单词出现过
            if( m == null && appear.contains(curWord) ) {
                return false;
            }
            // 如果这个key出现了，但是跟当前单词不匹配
            if( m!= null && !curWord.equals(m) ) {
                return false;
            }
            match.put(p, curWord);   
            appear.add(curWord);
        }
               
        return true;
    }
}

```  
  
时间复杂度: O(N)
空间复杂度：O(N)