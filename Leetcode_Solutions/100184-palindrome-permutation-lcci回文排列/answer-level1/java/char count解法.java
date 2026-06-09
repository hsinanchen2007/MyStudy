### 解题思路
2020-4-5 00:23:13
如果字符串长度是 奇数，那么 只有一个字符是 奇数个数，其余字符都是偶数个数。
如果字符串长度是 偶数，那么 所有字符都是偶数个数。
相当于是一个统计字符频率的char count。

### 代码

```java
class Solution {

    public boolean canPermutePalindrome(String s) {
        int len = s.length();
        char tmp ;
        Map<Character,Integer> charCount = new HashMap();
        for(int i = 0 ; i < len ; i++){
            tmp = s.charAt(i);
            if(charCount.containsKey(tmp)){
                charCount.put(tmp,charCount.get(tmp)+1);
                continue;
            }
            charCount.put(tmp,1);
        }

        //if( 0 == (charCount.size() % 2) ){
        if( 0 == (len % 2) ){
            for(char key : charCount.keySet()){
                if(0 != (charCount.get(key) % 2)){
                    return false;
                }
            }
            return true;
        }

        int count = 0 ;
        for(char key : charCount.keySet()){
            if( 1 == (charCount.get(key) % 2)){
                count++;
            }
            if(count >= 2){
                return false;
            }
        }
        return true;
    }
}
```