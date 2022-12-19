### 解题思路
用 （rand7（） - 1） * 7 + rand7() 生成0 ～ 49之内的数字

然后用拒绝采样的方法，只有在0 - 40以内的数字才会被接受

最后用这个数字 % 10 + 1 得到 rand10（）

### 代码

```java
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        while (true) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) return  num % 10 + 1;
        }
    }
}
```