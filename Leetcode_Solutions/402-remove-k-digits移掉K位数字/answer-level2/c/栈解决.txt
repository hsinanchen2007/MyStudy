![leetcode402.png](https://pic.leetcode-cn.com/e7656aefeb9d54d1f3bca57bb4ddd4b9826a115675026efe15f8628cf28bba8f-leetcode402.png)
使用栈思想，栈顶元素和字符串元素相比，栈顶元素大的前提下出栈，否则入栈，此过程中需要注意出栈的数量等于K时，结束上述规则，全部入栈。
然后检测出栈数量，小于K时，从栈顶出栈，直到等于K时结束。
最后注意特殊情况处理。
