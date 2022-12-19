### 解题思路
推理一下：
i=1, count=5 =1个a,1个e，1个i，1个o，1个u
i=2, count=10 = (1+2+4+2) 得到 3个a, 2个e，2个i，1个o，2个u
i=3, count=19= (3*1+2*2+2*4+2*1+1*2) 得到 2+2+2个a,3+2个e，2+1个i，2个o，2+1个u
由此可见，每下一次的数量只和上一次的每个元素的个数相关
因此建立数组关系，设n=1时， ints_1 =new int[]{1, 1, 1, 1, 1};
推到出 n=x时 ints =new int[]{ints_x-1[1]+ints_x-1[2]+ints_x-1[4], ints_x-1[0]+ints_x-1[2], ints_x-1[1]+ints_x-1[3], ints_x-1[2], ints_x-1[2]+ints_x-1[3]};

### 代码

```java
class Solution {
    public int countVowelPermutation(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 5;
        }
        int count=1;
        int mod = (int)Math.pow(10,9) + 7;
        /**
         * 推理一下：
         * i=1, count=5 =1个a,1个e，1个i，1个o，1个u
         * i=2, count=10 = (1+2+4+2) 得到 3个a, 2个e，2个i，1个o，2个u
         * i=3, count=19= (3*1+2*2+2*4+2*1+1*2) 得到 2+2+2个a,3+2个e，2+1个i，2个o，2+1个u
         */
        long[] ints =new long[]{1, 1, 1, 1, 1};
        while (count<n){
            count++;
            ints=new long[]{(ints[1]+ints[2]+ints[4] )% mod, (ints[0]+ints[2])% mod, (ints[1]+ints[3])% mod,  (ints[2])% mod, (ints[2]+ints[3])% mod};
        }
        int res = 0;
        for(int i = 0;i < 5;i++){
            res += ints[i];
            res %= mod;
        }
        return res;
    }
}
```