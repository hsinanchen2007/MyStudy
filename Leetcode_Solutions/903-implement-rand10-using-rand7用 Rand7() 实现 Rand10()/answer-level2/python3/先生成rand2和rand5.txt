rand10可以当做rand5和rand2的组合。
为了减少重复随机，如果第一次随机出1-5，就当做rand5的一个实现；如果随机出rand2，就当做rand7的一个实现。
我们来看一下rand2和rand5的效率：
这是一个几何分布，rand2平均要调用7/6次rand7，rand5平均要调用7/5次。因此整个程序平均要用1+5/7*7/6+2/7*7/5=2.23次。
另一位同学写的答案我大致算了下，要2.57次（7/5+7/6）


class Solution:
    def rand10(self):
        """
        :rtype: int
        """

        def rand2():
            while True:
                num = rand7()
                if num in [1, 2, 3]:
                    return 0
                elif num in [5, 6, 7]:
                    return 1

        def rand5():
            while True:
                num = rand7()
                if num in [1, 2, 3, 4, 5]:
                    return num

        temp = rand7()
        if temp in [1, 2, 3, 4, 5]:
            num1 = temp
            num2 = rand2()
        else:
            num1 = rand5()
            num2 = temp - 6
        return num1 * 2 - num2