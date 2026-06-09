### 解题思路
#### 何为回文
一个字符串前后能对称！ 
#### 构造回文
有重复的字符，依次放到前后位置
#### 所以
最大回文长度等价于有多少个成对的字符。

> 注意: 中点位置可不重复

### 代码

```java
import java.util.Map.Entry;
import java.util.*;

class Solution {
   public int longestPalindrome(String s) {
        Map<Character,Integer> map = new HashMap();

        for(Character c : s.toCharArray()){
            if(null != map.get(c)){
                map.put(c,map.get(c) + 1);
            } else {
                map.put(c,1);
            }
        }
        int result = 0;
        boolean hasSingle = false;
        for(Entry<Character,Integer> entry : map.entrySet()){
            result += (entry.getValue()/2) * 2;
            if(entry.getValue()%2 != 0){
                hasSingle =true;
            }
        }
        
        if(hasSingle){
            result++;
        }
        
        return result;
    }
}
```