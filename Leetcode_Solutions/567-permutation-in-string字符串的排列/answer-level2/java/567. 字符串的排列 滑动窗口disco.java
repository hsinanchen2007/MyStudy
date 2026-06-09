### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
 // 转化数组
        char[] chars1 = s1.toCharArray();
        char[] chars2 = s2.toCharArray();
        // 建立字符表
        int[] charS1 = new int[26];
        int[] charS2 = new int[26];
        // 初始化字符表
        for (int i=0;i<s1.length();i++){
            charS1[chars1[i]-'a']++;
        }

        int left=0,
                right=0;
        // 滑动窗口
        while (right<s2.length()){
            int curR = chars2[right]-'a';
            charS2[curR]++;

            // 窗口缩小处理 当前窗口的字符的数量超过s字符串，所以缩小窗口
            while (charS2[curR]>charS1[curR]){
                charS2[chars2[left]-'a']--;
                left++;
            }
            // 窗口和字符长度匹配，个数匹配找到 满足条件
            if(right-left+1 ==  s1.length()){
                return true;
            }
            // 窗口增加
            right++;
        }
        return false;

    }
}
```