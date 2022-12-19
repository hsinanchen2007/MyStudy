# 解体思路
看了置顶的题解，个人觉得使用栈做这个题思路会非常清晰，说实话官方的双指针解法我实在是看不懂。

# 方法一：使用分组和Stack类
利用分组和java的Stack类，很容易就能写出来。
步骤：
1.定义Group类，里面封装一个字符c和计数count
2.遍历chars数组，逐个比较栈顶字符和遍历到的字符，如果相等count加1，不相等就入栈
3.遍历Stack，将字符和计数值写入到chars数组中，返回数组的新size

```
    class Group {
        char c;
        int count;

        Group(char c) {
            this.c = c;
            count = 1;
        }
    }

    public int compress(char[] chars) {
        Stack<Group> stack = new Stack<>();
        for (char c : chars) {
            if (stack.isEmpty() || stack.peek().c != c) {
                stack.push(new Group(c));
            } else {
                stack.peek().count++;
            }
        }
        int size = 0;
        for (Group group : stack) {
            if (group.count == 1) {
                chars[size++] = group.c;
            } else {
                chars[size++] = group.c;
                String s = Integer.toString(group.count);
                for (int i = 0; i < s.length(); i++) {
                    chars[size++] = s.charAt(i);
                }
            }
        }
        return size;
    }
```
# 复杂度分析
- 时间复杂度：O(N)，N 为 chars数组的长度
- 空间复杂度：O(N)，使用了外部栈Stack类


# 方法二：使用栈的思想原地修改数组
方法一不能达到题目的空间复杂度O(1)的要求，为了优化，我们可以把chars本身看作一个栈，使用栈的思想原地修改数组。把chars当作栈，我们需要手动指定栈顶索引top。考虑到栈顶不一定是字符，为了比较距栈顶最近的字符，还需要一个索引ctop记录栈顶字符的位置。
![无标题.png](https://pic.leetcode-cn.com/86a41b4aa1e9be3380509f3776c958dad9f0ac779b5b632f6afef9789596a930-%E6%97%A0%E6%A0%87%E9%A2%98.png)
其中：
入栈代码：` top++; chars[top] = chars[i];`
比较栈顶字符代码：`chars[ctop] != chars[i]`

步骤：
1.定义栈顶索引top、栈顶字符索引ctop以及计数值count
2.遍历chars数组，逐个比较栈顶字符和遍历到的字符，如果相等count加1，不相等就入栈
3.判断count值，如果大于1就让count值的字符形式从ctop后面开始入栈，最后返回栈的size，即top+1

```
public int compress(char[] chars) {
        int top = 0;//栈顶索引
        int ctop = 0;//字符栈顶索引
        int count = 1;
        //chars[ctop] = chars[0];       //入栈一个初始元素(其实不需要这一步)
        for (int i = 1; i < chars.length; i++) {
            if (chars[ctop] != chars[i]) {//比较字符栈顶与遍历到的字符
                top++;
                chars[top] = chars[i]; //不同，入栈
                ctop = top;            //记录新的字符栈顶
                count = 1;
            } else {
                count++;                //相同，计数+1
                if (count > 1) {        //count大于1，需要让count入栈
                    top = ctop;         //先让栈顶回到字符栈顶
                    for (char c : String.valueOf(count).toCharArray()) {
                        top++;
                        chars[top] = c; //将count分成字符入栈
                    }
                }
            }
        }
        return top + 1; //top+1就是栈的size
    }
```

# 复杂度分析
- 时间复杂度：O(N)，N 为 chars数组的长度
- 空间复杂度：O(1)，把chars当作栈，原地修改