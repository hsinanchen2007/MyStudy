### 解题思路
哈希表实现。只能存在一个为奇数，其它必须为偶数才行。

### 代码

```java
class Solution {
    // a-z:97-122,A-Z:65-90
    public boolean canPermutePalindrome(String s) {
        if(s.length() == 0)
            return true;
        //预处理
        //s = s.toLowerCase();
        s = s.replaceAll(" ", "");

        HashMap<Character, Integer> hashmap = new HashMap<>();
        char[] chars = s.toCharArray();

        for(int i = 0; i < chars.length; i++){
            if(!hashmap.containsKey(chars[i])){
                hashmap.put(chars[i], 1);
            }else{
                hashmap.put(chars[i], hashmap.get(chars[i])+1);
            }
        }
        
        Set<Character> keySet = hashmap.keySet();

        int count = 1;
        for(char key : keySet){
            if(hashmap.get(key) % 2 == 0){
                continue;
            }
            else{
                count -= 1;
            }
            if(count < 0)
                return false;
        }
        return true;

    }
}
```