## 思路
    
具体的思路就是记录相同状态时的最大长度，状态数共有2^5 = 32个，即每个元音奇偶情况。状态压缩中使用异或来翻转特定位。`dp[i]`表示**状态i最早出现的位置**，其中0特殊处理为`-1`.

## 代码
```Java
class Solution {
    public int findTheLongestSubstring(String s) {
        int n = s.length(), res = 0;
        int[] dp = new int[32];
        int cur = 0;
        Arrays.fill(dp, n);
        dp[0] = -1;
        for(int i = 0 ; i < n ; i++){
            int id = getIndex(s.charAt(i));
            if(id >= 0) {
                cur ^= (1 << id);
            }
            dp[cur] = Math.min(dp[cur], i);
            res = Math.max(res, i - dp[cur]);
        }
        return res;
    }
    
    private int getIndex(char c){
        if(c == 'a'){
            return 0;
        } else if(c == 'e'){
            return 1;
        } else if(c == 'i'){
            return 2;
        } else if(c == 'o'){
            return 3;
        } else if(c == 'u'){
            return 4;
        } else {
            return -1;
        }
    }
}
```