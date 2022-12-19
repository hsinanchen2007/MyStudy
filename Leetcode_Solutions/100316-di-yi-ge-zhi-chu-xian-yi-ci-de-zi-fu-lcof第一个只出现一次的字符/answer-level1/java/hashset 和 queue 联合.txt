### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
         if (s == null || s.length() == 0)
            return ' ';
        HashSet<Character> hashSet = new HashSet<>();
        Queue<Character> queue = new LinkedList<>();
        char c ;
        for (int i = 0;i<s.length();i++){
            c = s.charAt(i);
            if (hashSet.isEmpty()){
                hashSet.add(c);
                queue.add(c);
            }
            else {
                if (hashSet.contains(c)){
                    queue.remove(c);
                }else {
                    queue.add(c);
                    hashSet.add(c);
                }
            }
        }
        if (!queue.isEmpty())
            return queue.peek();
        else return ' ';
    }
}
```