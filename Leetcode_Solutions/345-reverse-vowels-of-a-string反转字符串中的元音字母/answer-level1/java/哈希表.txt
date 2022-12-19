### 解题思路
使用哈希表存储元音字母，然后设置双指针进行检索，遇到元音字母就进行交换。然后终止条件是left < right;

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        HashMap<Character, Integer> hashmap = new HashMap<>();
        hashmap.put('a', 1);hashmap.put('e', 1);hashmap.put('i', 1);
        hashmap.put('o', 1);hashmap.put('u', 1);
        hashmap.put('A', 1);hashmap.put('E', 1);hashmap.put('I', 1);
        hashmap.put('O', 1);hashmap.put('U', 1);
        char[] chars = s.toCharArray();

        for(int i = 0, j = chars.length - 1; i < j;){
            while(i < j){
                if(hashmap.containsKey(chars[i])){
                    break;
                }
                else
                    i++;
            }
            while(i < j){
                if(hashmap.containsKey(chars[j])){
                    break;
                }
                else
                    j--;
            }
            if(i < j){
                char c = chars[i];
                chars[i] = chars[j];
                chars[j] = c;
            }
            i++;j--;
        }
        return new String(chars);
    }
}
```