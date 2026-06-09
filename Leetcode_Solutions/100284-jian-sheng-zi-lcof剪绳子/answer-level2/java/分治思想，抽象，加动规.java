### 解题思路
来leetcode一周年了，今天完全独立做出了这道题。
刚开始没想出头绪，飞跃点出现在抽象思维上，有切割动作，但是不用想具体怎么切换，然后想到递归，进一步就是动态规划了。
代码如下，超简洁：关键是DP部分，阶跃函数是在上一步基础上，对当前数字做各种切割，试算最大值，找到最大值后填入；

### 代码

```java
class Solution {
    public int cuttingRope(int n) {
        //DP 我们会有具体的切割动作，但是不进一步切下去；
        //切割，必然是分成2部分，对于每个部分，取其最大值，然后O(n)循环一次可以得最大值，return就行
        int[] tmp = new int[60];
        tmp[2] = 1;
        tmp[3] = 2;
        tmp[4] = 4;
        tmp[5] = 6;
        tmp[6] = 9;
        tmp[7] = 12;
        tmp[8] = 18;
        tmp[9] = 27;
        tmp[10] = 36;
        if (n <= 10) return tmp[n];
        //开始dp步骤
        for (int dp = 11; dp <=n; dp++) {
            int max = Integer.MIN_VALUE;
           for (int i=2; i<=dp/2; i++) {
                int left = (i>tmp[i]) ? i: tmp[i] ;
                int right = ((dp-i)>tmp[dp-i]) ? (dp-i) : tmp[dp-i] ;
                //System.out.println(left +"|"+right+"|"+max);
                if (max < left * right) max = left * right;
            }
            tmp[dp] = max;
        }
        return tmp[n];
    }
}
```