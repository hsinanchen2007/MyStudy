1. 什么是异或运算？
  相同的数进行异或运算为0， 所以将数组的里的数进行异或运算最终的结果就是答案。
```
public int singleNumber(int[] nums) {
        int flag = 0;
        for (int temp : nums) {
            flag = flag ^ temp;
        }
        return flag;
    }
```
