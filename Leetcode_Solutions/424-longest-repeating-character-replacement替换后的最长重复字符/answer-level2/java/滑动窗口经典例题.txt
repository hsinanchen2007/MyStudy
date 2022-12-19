### 解题思路
滑动窗口适用于解决数组&字符串内子元素问题
原理双指针，设定左右指针
算法难点：左右指针滑动的边界条件，窗口内值变化要思考清晰



### 代码

```java
class Solution {
    public int characterReplacement(String s, int k) {
 char[] str = s.toCharArray();
        int[] charCount = new int[26];

        int left=0,
                right=0,
                maxCount=0,result=0;
        // 滑动窗口 解决数组和字符串子元素问题
        while (right<str.length){
            charCount[str[right]-'A']++;
            // 当前窗口的的重复字符最大数量
            maxCount  = Math.max(charCount[str[right]-'A'],maxCount);
            
            // 缩小当前窗口
            if(right-left+1-maxCount>k){
                // 窗口缩小,移除窗口的字符减1
                charCount[str[left]-'A']--;
                left++;
            }

            // 最长重复字符 等价 窗口滑动过程中的最大值
            result=Math.max(result,right-left+1);
            // 增加滑动窗口范围
            right++;
        }
        return result;
    }
}
```