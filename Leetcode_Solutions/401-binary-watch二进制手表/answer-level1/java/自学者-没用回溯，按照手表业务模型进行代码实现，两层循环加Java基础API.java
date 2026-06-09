### 解题思路
* 业务模型，两层循环
* 二进制个数之和等于给定数值满足添加要求
* Integer.toString()转换整数为字符串

### 代码

```java
class Solution {
    public Solution() {
    }

    public List<String> readBinaryWatch(int num) {
       List<String> res = new ArrayList<>();
        //直接遍历  0:00 -> 12:00   每个时间有多少1
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (Integer.bitCount(i) + Integer.bitCount(j) == num) {
                    res.add(Integer.toString(i) + ":"+
                                  (j < 10 ? "0" + Integer.toString(j) : Integer.toString(j)));
                }
            }
        }
        return res;
    }     
}
```