### 解题思路
思路是关注最近的两个相同字符间距离，同时增加水位限制，水位始终为0或相同字符较旧那个位置的下一个位置。

水位用来限制计算重复元素的最小位置，不能低于水位去找重复元素来计算路径长度，因为水位所在的位置之前已经有其他重复元素了。

比如abca，初始为0，直到第二个a时水位更新为前一个a的下一个位置即1
再比如 kacbak
第一次遇到重复元素a时，将水位置为 1 + 1 = 2
第二次，又遇到重复元素k，此时因为上次重复的k的位置0在数位2之下，表示

同时本算法用256位的int数组代替了HashMap，速度再次提高
取256的原因是,char为8bit，即针最多2^8-1 个字符

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        // records elements` index
        int[] map = new int[256];

        // max substring length
        int max = 0;
        // keep the watermark next to the newly found old position
        int watermark = 0;
        // temporary count
        int tmp = 0;

        for(int i = 0; i < s.length(); i++){
            int old = map[s.charAt(i)];
            if(old == 0){
                // means the element has not appeared before
                
                // just need to increment the tmp
                tmp++;
            }else{
                // means the element has appeared before

                // need update the max
                max = Math.max(max,tmp);

                // old--: the char`s true index in the string
                old--;
                
                if(old < watermark){
                    // the old position is lower than the watermark,
                    // just need to update the tmp
                    tmp = i - watermark + 1;  
                } else {
                    // the old position is not lower than the watermark, need to update 
                    // the watermark to keep the watermark next to the newly found 
                    // old position
                    watermark = old + 1;

                    // update the tmp
                    tmp = i - watermark + 1;  
                }
            }
            // update the element`s position
            map[s.charAt(i)] = i+1;
        }
        return Math.max(max,tmp);
    }
}
```