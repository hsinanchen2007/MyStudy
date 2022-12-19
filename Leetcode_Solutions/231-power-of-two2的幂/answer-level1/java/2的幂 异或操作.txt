#  异或操作
同与操作，核心在于需要考虑到2的幂，其二进制内有且仅有一个1
如：
- 1 -> 1
- 2 -> 10
- 4 -> 100
- 8 -> 1000
- ... ...
那么我们设置一个int变量temp，将其移位放大到同n的二进制长度相同的2的幂次解
如 n -> 1101 二进制长度为4，那么我们的temp放大到1000，长度保持一致。
直接放代码

```
public class isPowerOfTwo {    
    public boolean isPowerOfTwo(int n) {
        //2的幂必大于0
        if (n <= 0) {
            return false;
        }
        //我们预设的变量
        int temp = 1;
        //根据n的二进制长度，移位将temp“放大”
        temp <<= Integer.toBinaryString(n).length() - 1;
        //直接异或操作（相当于只有当n同temp相等时，才返回true）
        return (temp^n) == 0;
    }
}
```

测试结果 时间：2ms 内存占用 33.5MB

