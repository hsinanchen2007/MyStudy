### 解题思路
##### 方法1
```text
1. String trim()后通过split转换成数组strs
2. 遍历数组，交换对应元素的位置（i与strs.length - i -1交换）
3. 将数组转换成字符串，去除数组中的空字符串
```
##### 方法2
```
方法2和方法1没有本质区别，只是用了java 集合中的一些原生方法，显得更精炼一些
1. split的时候，匹配正则' +',而不是' '
2. 交换对应元素位置的时候，使用collections.reverse(Arrays.asList(...))
3. 数组转换成String的时候，使用String.join(...)
```

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] strs = s.trim().split(" ");
        for (int i = 0; i < strs.length / 2; i++) {
            swap(strs, i, strs.length - i - 1);
        }
        StringBuffer sb = new StringBuffer();
        for (String str : strs) {
            if (!str.equals("")) {
                sb.append(str);
                sb.append(" ");
            }
        }
        return sb.toString().trim();
    }

    private void swap(String[] strs, int i, int j) {
        String tmp = strs[i];
        strs[i] = strs[j];
        strs[j] = tmp;
    }
}
```

### 测试用例
```java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void reverseWords() {
        String input1 = "the sky is blue";
        String expect1 = "blue is sky the";
        String output1 = solution.reverseWords(input1);

        assertEquals(expect1, output1);

        String input2 = "  hello world!  ";
        String expect2 =  "world! hello";
        String output2 = solution.reverseWords(input2);
        assertEquals(expect2, output2);

        String input3 = "a good   example";
        String expect3 =  "example good a";
        String output3 = solution.reverseWords(input3);
        assertEquals(expect3, output3);
    }
}
```