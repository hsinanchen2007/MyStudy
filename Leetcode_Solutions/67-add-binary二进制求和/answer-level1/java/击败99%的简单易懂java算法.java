![TIM截图20190922183222.png](https://pic.leetcode-cn.com/1c51bbf9242d18e5344405cc77dec6dcd36dbd1cb27bbf277bf1cff0ca09fef5-TIM%E6%88%AA%E5%9B%BE20190922183222.png)

算法速度上还行，就是转化成数组其实感觉是有点多余的，不过为了方便明了，就不要太在意了。

思路就是先将字符串转化成数组，然后数组运算的进位是反着进，最后转化为字符串的时候再反过来就行了。

```java

class Solution {
    public String addBinary(String a, String b) {
        int len1 = a.length();
        int len2 = b.length();
        int max = Math.max(len1, len2);
        
        int[] nums1 = new int[max + 1];
        int[] nums2 = new int[max + 1];
        
        for(int i = len1-1; i >= 0; i--){
            nums1[i] = a.charAt(len1 - i - 1) - 48;
        }
        
        for(int i = len2-1; i >= 0; i--){
            nums2[i] = b.charAt(len2 - i - 1) - 48;
        }
        
        for(int i = 0; i < max; i++){
            nums1[i] += nums2[i];
            if(nums1[i] > 1){
                nums1[i] %= 2;
                nums1[i + 1]++;
            }
        }
        
        StringBuilder builder = new StringBuilder();
        for(int i = max; i >= 0; i--){
            if( i == max && nums1[max] == 0){
                continue;
            }
            builder.append(nums1[i]);
        }
        return builder.toString();
    }
}
```
