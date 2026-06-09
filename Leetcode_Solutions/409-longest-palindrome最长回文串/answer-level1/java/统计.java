### 解题思路
此处撰写解题思路
某个字符出现双数本身就是回文不需要修改,如果是单数,就减1变为双数,但是回文字符串可以包含一共单数就是单数放在中间的时候所以最后需要加1,如果没有出现过单数就不用加1的操作
### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        //A-z一共58个数
        int[]nums=new int[58];
        for(int i=0;i<s.length();i++){
            nums[s.charAt(i)-'A']++;
        }
        int result=0;
        boolean flag=true;
        for(int i=0;i<nums.length;i++){
            if(nums[i]%2==0){
                result=result+nums[i];
            }else{
                //如果出现过奇数将标记置为false
                flag=false;
                result=result+nums[i]-1;
            }
            
        }
        return flag?result:result+1;
    }
}
```