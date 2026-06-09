思路：此题关键在于数字的二进制中出现1的位置，记录下该数字的二进制每次出现1的位置，算出其中两个相邻的1之间的间距即可。
<br/><br/>
代码：
```
class Solution {
    public int binaryGap(int N) {
        int ans = 0;
        int pos = 1;
        
        int start = 0;
        int end = 0;
        boolean flag = true;
        
        while (N > 0) {
            int m = N % 2;
            
            if (m == 1) {
                if (flag) {
                    start = pos;
                    flag = false;
                } else {
                    end = pos;
                    ans = Math.max(end - start,ans);
                    start = end;
                }
            }
            
            N /= 2;
            pos++;
        }
        
        return ans;
    }
}
```

![image.png](https://pic.leetcode-cn.com/84ec6de6e164ba1149119a86905763ed8c6f375f3f58073f3cf63cf0639e798d-image.png)