### 解题思路
1.首先遍历是肯定的，另外要元素以及个数 ，同时统计双数的元素个数
2.下面的优化其实itemList 没必要开辟内存，用一个int计数 就ok了 

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
          // 用LIst存取双数的
        ArrayList<Character> itemList = new ArrayList<Character>();
        char[]sChars = s.toCharArray();
        Character sC = null;
        HashMap<Character,Integer> map = new HashMap<>();
        for(int i = 0;i < sChars.length;i++){
            Character c = sChars[i];
            if(map.containsKey(c)){
                int size = map.get(c);
                if(size == 2){
                    map.put(c,1);
                } else{
                    itemList.add(c);
                    map.put(c,2);
                }
            } else {
                map.put(c,1);
            }
        }
        int size = itemList.size() * 2;
        return size < sChars.length ? size + 1 : size;
    }
}
```