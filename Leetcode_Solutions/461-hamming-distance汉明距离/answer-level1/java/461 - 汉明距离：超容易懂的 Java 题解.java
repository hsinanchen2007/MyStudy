> 有关更多题解，请访问 Gitee 中的项目【[myleetcode](https://gitee.com/guobinhit/myleetcode)】，欢迎大家共同参与此项目！

>

```
public class _461 {
    public int hammingDistance(int x, int y) {
        // 将 x 和 y 进行异或操作，讲题目转为求二进制结果中 1 的个数 
        int curr = x ^ y, count = 0;
        while (curr != 0) {
            count++;
            // curr & (curr - 1) 将最低位的 1 变为 0，其他位不变
            curr = curr & (curr - 1);
        }
        return count;
    }
}
```
