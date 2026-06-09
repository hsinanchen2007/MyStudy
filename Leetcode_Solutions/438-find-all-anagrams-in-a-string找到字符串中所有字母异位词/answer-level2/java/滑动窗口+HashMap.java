### 解题思路
1. 设置两个HashMap,mapP的用途是获得p中每个字符对应的次数；mapS的用途是在该滑动窗口时，对应于mapP还剩多少字符没有匹配上，如果完全匹配上，那么mapS应该为空，所以当mapS为空时说明该滑动窗口满足条件；
2. 当字符存在于mapP时，先将mapS中的字符次数减1，弱国字符次数为0，则删除该字符；当i>=p.length时，遍历每一个i时，需要进行添加操作，添加i-p.length位置处的字符。

### 代码

```java
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

/**
 * 复习
 * 滑动窗口
 */
public class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> retList = new LinkedList<>();

        if(p.length() > s.length()){
            return retList;
        }

        HashMap<Character, Integer> mapP = new HashMap<>();
        HashMap<Character, Integer> mapS = new HashMap<>();
        for(int i=0; i<p.length(); i++){
            char c = p.charAt(i);
            mapP.put(c, mapP.getOrDefault(c, 0) + 1);
            mapS.put(c, mapS.getOrDefault(c, 0) + 1);
        }

        // 遍历不断更新mapS，当mapS.size为0，则更新retList
        for(int i=0; i<s.length(); i++){
            // 进行删除
            char c = s.charAt(i);
            if (mapP.containsKey(c)) {
                mapS.put(c, mapS.getOrDefault(c, 0) - 1);
                if(mapS.get(c) == 0){
                    mapS.remove(c);
                }
            }

            // 进行添加 i-p.length
            if(i>=p.length()){
                char c2 = s.charAt(i-p.length());
                if(mapP.containsKey(c2)){
                     mapS.put(c2, mapS.getOrDefault(c2, 0)+1);
                     if(mapS.get(c2) == 0){
                         mapS.remove(c2);
                     }
                }
            }

            // 判断是否需要更新retList
            if(mapS.isEmpty()){
                retList.add(i-p.length()+1);
            }
        }

        return retList;

    }
}

```