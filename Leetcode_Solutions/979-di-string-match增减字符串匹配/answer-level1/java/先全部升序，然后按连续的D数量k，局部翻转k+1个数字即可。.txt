我的思路：先全部按升序排列0~N，然后扫描指令串，“I”就跳过不处理，碰到“D”就接着统计一共有多少个连续的D（假设有K个），然后翻转从当前位置开始的K+1个数字即可。
```
class Solution {
    public int[] diStringMatch(String S) {
        char[] c = S.toCharArray();
        int[] ans = new int[c.length + 1];
        for(int i = 0; i < ans.length; i++) ans[i] = i;
        for(int i = 0; i < c.length;) {
            if(c[i] == 'I') {
                i++;
                continue;
            } else {
                int countD = 1;
                int k = i + 1;
                while ((k <= c.length-1) && (c[k++] == 'D')){
                    countD++;
                };
                for (int j = 0; j < (countD + 1) / 2; j++) {
                    ans[i + j] = ans[i + j] ^ ans[i + countD - j];
                    ans[i + countD - j] = ans[i + countD - j] ^ ans[i + j];
                    ans[i + j] = ans[i + j] ^ ans[i + countD - j];
                };
                i += countD;
            };
        };
        return ans;
    }
}
```

