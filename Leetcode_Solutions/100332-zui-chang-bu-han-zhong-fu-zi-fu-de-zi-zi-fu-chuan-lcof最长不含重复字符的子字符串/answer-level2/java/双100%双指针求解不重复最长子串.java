### 双指针
对于一个字符串：pwabwacdpw
初始情况：左指针left指向第0个，右指针right指向第1个
每次判断的时候，需要依次从 [left,...,right-1] 的每一个元素分别和right的元素判断是否相等；
如果 s.charAt(i) ！= s.charAt(right) right++;
如果 s.charAt(i) == s.charAt(right)，left=i+1，right++
right更新之前都要用一个全局变量ans保存当前最大的子串长度，最后返回

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() <= 1){
            return s.length();
        }
        int left = 0;
        int right = 1;
        int ans = 0;
        while(right < s.length()){//循环终止条件
            for(int i = left; i < right; i++){
                if(s.charAt(i) == s.charAt(right)){
                    left = i + 1;//左指针更新
                    break;
                }
            }
            ans = Math.max(ans, right - left + 1);//保存当前子串最大长度
            right++;//右指针右移
        }
        return ans;
    }
}
```