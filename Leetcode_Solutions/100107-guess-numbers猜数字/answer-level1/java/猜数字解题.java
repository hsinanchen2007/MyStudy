### 解题思路
此处撰写解题思路

### 代码

```java
        //计算猜对次数
        int count = 0;

        //借助JDK的API 来判断两个数组的内容及长度是否相同
        if (Arrays.equals(guess, answer)) {
            return 3;
        }

        //循环比较内容
        for (int i = 0; i < 3; i++) {
            if (guess[i] == answer[i]) {
                count++;
            }
        }

        return count;
}
```