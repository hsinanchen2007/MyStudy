### 解题思路
1.题目意思就是求A和B的二进制有多少位不一样
2.用异或，相同返回0，不同返回1，异或的结果中有多少个1，那么就需要改动几次
3.按位与，int是32位，所以循环32次即可，每次右移1位与上1，如果结果是1，那么改动的次数+1即可
### 代码

```java
class Solution {
    public int convertInteger(int A, int B) {
        //思考A变成B需要多少位变动
        //那么思考A和B的位运算 异或？相同的返回0 不同的反回1
        int c = A^B;
        //再判断C中有多少个1
        int result = 0;

        for (int i = 0; i < 32; i++) {
            if ((c&1)== 1) {
                result++;
            }
            c >>= 1;
        }
        return result;
    }
}
```