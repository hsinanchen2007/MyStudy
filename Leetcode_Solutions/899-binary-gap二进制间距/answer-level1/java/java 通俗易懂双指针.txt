### 解题思路
首先需要不断的移位，cnt就是计数器，同时也表示当前的位置。
第一次遇到1则记录begin为当前位置，表示这一次的起始位置，然后继续移位
再次遇到1就用当前位置减去记录的起始位置（cnt-begin）然后新的起点就是当前位置，继续找下一个1
如此往复

### 代码

```java
class Solution {
    public int binaryGap(int N) {
        int res = 0;
        int begin = 0;
        int cnt = 0;
        while(N!=0)
        {
            cnt++;   //第cnt位
            int temp = N&1;
            if(temp==1)
            {
                if(begin!=0)
                    res = Math.max(res,cnt-begin); //得到这一次的结果
                begin = cnt;//起始位变更
            } 
            N=N>>>1;
        }
        return res;
    }
}
```