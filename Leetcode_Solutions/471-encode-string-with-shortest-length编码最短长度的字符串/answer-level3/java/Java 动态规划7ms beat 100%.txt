![image.png](https://pic.leetcode-cn.com/2c450b000f009a96f7489e705e35bb4f93e798993e6e537988b5a02fc2318d07-image.png)

断断续续想了一天，代码有点长，为了性能，中间数组不保存字符串，保存的是切割的位置：

```java
class Solution {
    public String encode(String s) {
        char[] cs=s.toCharArray();
        // hp数组保存的是从i到j的字符串，从第i个位置开始连续重复出现了多少次，最小为1：
        int[][] hp = new int[cs.length][cs.length];
        // dp数组保存窗口大小为w，起点为j的子串编码后的最短长度：
        int[][] dp = new int[cs.length+1][cs.length];
        // dp2数组保存的是窗口大小为w，起点为j的子串切割的最佳位置，默认为j+w-1：
        int[][] dp2 = new int[cs.length+1][cs.length];

        // 首先初始化hp数组：
        for (int i=0; i<cs.length; i++) {
            for (int j=i; j<cs.length; j++) {
                int len=(j-i+1);
                int k=j+1;
                while (cs.length-k>=len) {
                    int m=0;
                    for (;m<len;m++) {
                        if (cs[i+m]!=cs[k+m]) {
                            break;
                        }
                    }
                    if (m==len) {
                        k+=len;
                    } else {
                        break;
                    }
                }
                hp[i][j]=1+(k-j-1)/len;
            }
        }

        // 构建dp数组和dp2数组：
        for (int w=1; w<=cs.length; w++) {
            for (int j=0; j<cs.length-w+1; j++) {
                dp[w][j]=w;
                dp2[w][j]=j+w-1;
                int minLen=w;
                for (int k=j; k<j+w/2; k++) {
                    if (w%(k-j+1)==0 && hp[j][k]>=(w/(k-j+1))) {
                        int tmp=w/(k-j+1);
                        if (2+help(tmp)+dp[k-j+1][j] < w) {        
                            dp[w][j]=2+help(tmp)+dp[k-j+1][j];
                            dp2[w][j]=k;
                            break;
                        }
                    }
                }
                for (int k=j; k<j+w-1; k++) {
                    if (dp[w][j] > (dp[k-j+1][j]+dp[w-k+j-1][k+1])) {
                        dp[w][j]=dp[k-j+1][j]+dp[w-k+j-1][k+1];
                        dp2[w][j]=k;
                    }
                }
            }
        }

        // 根据dp数组和dp2数组构建编码后的字符串：
        StringBuilder sb=new StringBuilder();
        help2(s, 0, cs.length-1, hp, dp, dp2, sb);
        return sb.toString();
    }

    public void help2(String s, int start, int end, int[][] hp, int[][] dp, int[][] dp2, StringBuilder sb) {
        
        int wnd=end-start+1;
        if (dp[wnd][start] == wnd) {
            sb.append(s.substring(start, end+1));
            return;
        }
        int sp = dp2[wnd][start];
        int n1 = end-start+1, n2 = sp-start+1;
        if (n1%n2==0 && hp[start][sp]>=n1/n2) {
            sb.append(n1/n2);
            sb.append("[");
            help2(s, start, sp, hp, dp, dp2, sb);
            sb.append("]");
            return;
        }

        help2(s, start, sp, hp, dp, dp2, sb);
        help2(s, sp+1, end, hp, dp, dp2, sb);
    }

    public int help(int count) {
        if (count<10) {
            return 1;
        }
        if (count<100) {
            return 2;
        }
        return 3;
    }
}
```

