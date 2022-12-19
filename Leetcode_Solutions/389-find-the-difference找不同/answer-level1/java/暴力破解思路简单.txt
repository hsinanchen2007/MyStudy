### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
    int[] nums = new int[26];
    char ans = ' ';
    for(int i= 0;i < t.length();i++){
    nums[t.charAt(i)-'a']++;
       }
    for(int j = 0;j < s.length();j++){
    nums[s.charAt(j)-'a']--;
       }
    for(int l = 0;l < nums.length;l++){
        if(nums[l]!=0){
            ans = (char)(97+l);
        }
    }
    return ans;
    }
}
```