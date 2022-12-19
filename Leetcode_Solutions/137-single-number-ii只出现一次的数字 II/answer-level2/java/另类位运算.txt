### 解题思路
https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-wei-yun-suan-ke-yi-tu/

得到的启发，把每个32位的位置都记录一遍，得到的统计%3就余下的数就可以组成出现一次的数。
这个方法可以推广在 在一堆数中，其他所有数都出现了m次，而一个数出现了n次。

### 代码

```java
class Solution {
    public int singleNumber(int[] nums) {
        int [] stat=new int[32];
        for (int num:nums){
            for (int i=31;i>=0;--i){
                if ((num&1)==1)
                    ++stat[i];
                num=num>>1;
            }
        }
        int number=0;
        for (int i=0;i<32;++i){
            number=number<<1;
            number+=stat[i]%3;
        }
        return number;
    }
}
```