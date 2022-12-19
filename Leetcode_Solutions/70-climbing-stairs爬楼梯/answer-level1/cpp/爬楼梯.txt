70.爬楼梯
学过奥数的人对爬楼梯一定不陌生
fibonacci数列就用在这个问题上
公式是：f(n)=f(n-1)+f(n-2)
可以使用递归，但数太大就会溢出(系统分配只有2MB的空间),调用自己会花时间,建议使用死循环,
用上面的公式
![捕获.PNG](https://pic.leetcode-cn.com/94797e119c27f6b28a282b746394966de6075b81515292efee0af108b9c6cf89-%E6%8D%95%E8%8E%B7.PNG)
![捕获2.PNG](https://pic.leetcode-cn.com/a745276c0640e5f6c03850a8dd9699b14a4636e01b0dd5f2721c710d8da8c564-%E6%8D%95%E8%8E%B72.PNG)
循环到
![捕获3.PNG](https://pic.leetcode-cn.com/d2ab461af4dc35e411a1b2b3e465bdd79b1cd58c0db55b362e99aee5190d2cea-%E6%8D%95%E8%8E%B73.PNG)
之后return t(结果)

注意:a是下标，n的下标是(n-1)!
