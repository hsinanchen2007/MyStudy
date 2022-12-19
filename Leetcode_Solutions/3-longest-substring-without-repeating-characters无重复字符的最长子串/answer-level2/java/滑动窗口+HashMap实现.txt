### 解题思路
思路见代码处

### 代码

```java
import java.util.HashMap;

/**
 * 复习
 * 思路：滑动窗口
 * 1.设置一个长度，初值为0；设置一个滑动窗口map，用来存储在该位置的字符以及数目，需不断更新
 * 2.使用双指针，left和right指针，每次移动right就添加更新，每次移动left就删除更新。
 * 3.什么时候更新长度呢？map的大小等于right-left+1;
 */
public class Solution {

    public int lengthOfLongestSubstring(String s) {
        int longestLength = 0;
        HashMap<Character, Integer> map = new HashMap<>();

        int left=0;
        int right=0;
        while(left < s.length()){
            if(map.size() == right-left){
                // 此时更新longestLength以及添加元素
                longestLength = Math.max(longestLength, right-left);
                if(right >= s.length()){
                    break;
                }
                char c = s.charAt(right++);
                map.put(c, map.getOrDefault(c, 0)+1);
            }else {
                // 需要删除元素
                char c = s.charAt(left++);
                int count = map.getOrDefault(c, 0);
                if(count == 1){
                    map.remove(c);
                }else {
                    map.put(c, count-1);
                }
            }
        }

        return longestLength;
    }
}

```