```java
// 约瑟夫环问题
// 有n个人，编号分别为0, 1, 2, ……, n - 1，每当报道第m个人时，就杀掉他，求最后胜利者编号
// f(n, m) = [f(n − 1, m) + m] % n
/*
    f(11, 3) = 6，从A开始报数，最后能活下来的是G
    0 1 2 3 4 5 6 7 8 9 10
    A B C D E F G H I J K
    从A开始报数，杀掉C之后，剩下10个人，接下来从D开始报数，最后能活下来的依然是G
    8 9 0 1 2 3 4 5 6 7
    A B D E F G H I J K
    从11个人变为10个人，G的编号减少了3，所以f(10, 3) = f(11, 3) - 3 = 3

    f(10, 3) = 3，从A开始报数，最后能活下来的是D
    0 1 2 3 4 5 6 7 8 9
    A B C D E F G H I J
    在A前面添加1个人K，从I开始报数，杀掉K之后，剩下10个人，接下来从A开始报数，最后能活下来的依然是D
    2 3 4 5 6 7 8 9 10 0 1
    K A B C D E F G H  I J
    ----------------------
    0 1 2 3 4 5 6 7 8 9 10
    I J K A B C D E F G H
    从10个人变为11个人，D的编号增加了3，所以f(11, 3) = f(10, 3) + 3 = 6
    为了防止下标越界，应该取模，所以f(11, 3) = [f(10, 3) + 3] % 11
 */

public int lastRemaining(int n, int m) {
    return (n == 1) ? 0 : ((lastRemaining(n - 1, m) + m) % n);
}

public int lastRemaining1(int n, int m) {
    int res = 0;
    for (int i = 2; i <= n; i++) {
        res = (res + m) % i;
    }
    return res;
}
```