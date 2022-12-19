### 解题思路
测试用例居然有一个[1,3,5]，我很诧异，不是说好的旋转数组嘛？ 这个是咋旋转出来的？
这个应该是暴力方法了吧，旋转数组只有两种可能，结合这个例子，最小值在中间或者开头就是
所以暴力一下，暴力美学。

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        for(int i = 0; i < numbers.length-1; i++)
        {
            if(numbers[i] > numbers[i+1] )
                return numbers[i+1];
        }
        return numbers[0];
    }
}
```