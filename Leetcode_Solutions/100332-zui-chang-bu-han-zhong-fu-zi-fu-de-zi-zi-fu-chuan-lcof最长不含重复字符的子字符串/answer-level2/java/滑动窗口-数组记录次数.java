### 解题思路

使用数组记录 出现情况 
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int max = 0;
        int low = 0,h=0;
        int[] arr = new int[256];
        int len = s.length();
        while(h<len){
            char str = s.charAt(h);
            arr[str]++;
            
            while(arr[str] > 1 ){
                //是当前字符 计数才减1
                if(s.charAt(low) == str){
                    arr[str]--;
                }else{
                    arr[s.charAt(low)] = 0;//把 low 前面的写为0，避免后面重复计算
                }
                low++;//缩小窗口
            }
           // System.out.print(low);
            h++;//扩大窗口
           // System.out.println(" "+h);
            max = Math.max(max,h-low);
        }
        return max;
    }
}
```