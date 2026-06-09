使用栈思想，空栈时入栈，非空时判断，
1.方向相同，入栈
2.方向不同
    2.1相反方向，入栈
    2.2相同方向，即碰撞
        2.2.1栈内行星爆炸，出栈，即将入栈的行星进入下次循环
        2.2.2相撞的行星都爆炸，出栈

![commit.png](https://pic.leetcode-cn.com/d8cd2d044e7e8b3481951957472b8c90554924f6c1105240410ed8d5fcaaa81b-commit.png)
![leetcode.png](https://pic.leetcode-cn.com/02a735011f46a73d44ed1ae1032de2bf5d3e295ab260f34ed75334980c7dbe04-leetcode.png)

