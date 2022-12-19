思路：建立二维映射表，统计每个字符的最小共同出现次数即可。
<br/><br/>
代码：
```
class Solution {
    public List<String> commonChars(String[] A) {
        if (A == null || A.length < 1) {
            return null;
        }
        
        List<String> ans = new ArrayList<>();
        
        int mapLetter[][] = new int[A.length][26];
        
        for (int i = 0;i < A.length;i++) {
            map(A[i],mapLetter[i]);
        }
        
        for (int i = 0;i < 26;i++) {
            int min = Integer.MAX_VALUE;
            for (int j = 0;j < A.length;j++) {
                if (min > mapLetter[j][i]) {
                    min = mapLetter[j][i];
                }
            }
            
            while (min-- > 0) {
                ans.add(String.valueOf((char) (i + 'a')));
            }
        }
        
        return ans;
    }
    
    private void map(String s,int a[]) {
        for (int i = 0;i < s.length();i++) {
            a[s.charAt(i) - 'a']++;
        }
    }
}
```

![image.png](https://pic.leetcode-cn.com/cf188c2917494ff8031ab39fc05c20c6232f0ca2bfa3dd23b3ba0e8a544a547e-image.png)