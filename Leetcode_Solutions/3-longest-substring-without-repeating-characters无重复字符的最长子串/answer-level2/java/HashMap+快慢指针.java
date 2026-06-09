![2020012301.PNG](https://pic.leetcode-cn.com/50ae43aa9498dbcf32c01a302337574ad4b797e1390721100bfe6b72edb04fba-2020012301.PNG)

### 解题思路
声明max记录当前最大的子串长度
慢指针--left;
快指针--i;
声明哈希表--reMap, reMap的Key为字符串中的字符,value为字符在字符串中的索引;
用reMap.containsKey(s.charAt(i)),来判断到当前索引i为止是否出现重复字符;
没有出现重复字符,则快指针继续往前走;
若出现重复字符,则对重复字符在哈希表中记录的索引与left大小进行判断;
若重复字符在哈希表中记录的索引大于left,则更新left;
计算(i-left)的值,比较max与(i-left),取最大值,更新max的值
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
    	Map<Character,Integer> reMap = new HashMap<>();
    	int max=0;
        int left = 0;
        int i =0;
    	while(i<s.length()) {
    		if(reMap.containsKey(s.charAt(i))) {
    			if(reMap.get(s.charAt(i))>=left) {
        			left = reMap.get(s.charAt(i))+1;
    			}
    		}
			reMap.put(s.charAt(i), i);
			i++;
            if((i-left)>max){
                max = (i-left);
            }
    	}
        return max;
    }
}
```