### 解题思路
此处撰写解题思路
首先想到的是最暴力的方法，直接双重遍历每一个位置，左右扩散找到最长的；然后想着这种面试的时候肯定不合格，需要再改进改进。可以在原来的基础上进行剪枝，比如像aaabb这种的连续相同的，直接找到b这个位置就可以了，此时下一次遍历不再从第二个位置开始判断，而是直接从b这个位置开始；然后是常见的aabaacc这种的，先用前面的方法找到b的位置然后左右扩散，记录下最右边的位置，下一次也是从这开始。
### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        if(s==null||s.length()==0){
            return "";
        }
        char[] chars = s.toCharArray();
        int[] limit = new int[]{0,0};
        for(int i = 0;i<chars.length;i++){
            i = findlimit(chars,i,limit);
        }
        return s.substring(limit[0],limit[1]+1);
    }
    public int findlimit(char[] chars,int low,int[] limit){
        int high = low;
        while(low >= 0 && high < chars.length-1 && chars[low] == chars[high+1]){
            high++;
        }
        int res = high;
        while(low > 0 && high < chars.length-1 && chars[low-1] == chars[high+1]){
            high++;
            low--;
        }
        if(limit[1] - limit[0] < high-low){
            limit[0] = low;
            limit[1] = high;
        }
        return res;
    }
}
```