![image.png](https://pic.leetcode-cn.com/eb1f887302b82c83ff51335c11056e5eefae157634728006285dd82555191ac3-image.png)
```
class Solution {
        public boolean judgeCircle(String moves) {
            if (moves.length()==0)
                return true;
            if ((moves.length()&1)==1)//奇数个总是不可能原点的
                return false;
            int[] cnt = new int[4];
            for (int i = 0; i <moves.length() ; i++) {
                if (moves.charAt(i)=='U')
                    cnt[0]++;
                else if (moves.charAt(i)=='D')
                    cnt[1] ++;
                else if (moves.charAt(i)=='L')
                    cnt[2] ++;
                else if (moves.charAt(i)=='R')
                    cnt[3] ++;
            }
            if (cnt[0]==cnt[1] && cnt[2]==cnt[3])
                return true;
            return false;
        }
}
```
