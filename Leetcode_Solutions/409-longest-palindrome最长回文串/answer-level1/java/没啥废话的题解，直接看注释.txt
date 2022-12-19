### 解题思路
溜了溜了，不要在意手打的细节

### 代码

```java
class Solution {
    // 如果是偶数的话，全部加进去
    // 如果是奇数的话，减一加进去
    // 如果没有加完，说明有奇数的存在，可以将奇数放在中间位置
    public int longestPalindrome(String s) {
        int n = s.length();
        HashMap<Character,Integer> map = new HashMap<>();
        for(int i = 0; i< n; i++){
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c,0)+1);
        }
        int res = 0;
        for(Character key: map.keySet()){
            Integer val = map.get(key);
            if((val & 1) == 1) res+=val-1;
            else res+=val;
        }
        if(res < n) return res+1;
        else return res;
    }
}
```