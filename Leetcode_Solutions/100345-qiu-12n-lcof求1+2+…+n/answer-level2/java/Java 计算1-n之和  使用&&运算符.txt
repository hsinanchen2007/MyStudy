### 解题思路
递归思想，if语句转换为&&实现的短路语句。

### 代码

```java

//利用boolean实现两个函数，第一个函数判断递归终止的条件，第二个函数充当递归函数
class Solution {
    public int sumNums(int n) {
        if (n > 0) {
            n += sumNums(n - 1);
        }
        // boolean b = (n > 0) && (n += sumNums(n - 1)) > 0;//&&左右两边均为boolean类型
        return n;//返回int类型
    }
}
```