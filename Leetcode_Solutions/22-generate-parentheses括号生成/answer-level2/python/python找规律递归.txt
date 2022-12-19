一开始是找规律，发现n个括号实在n-1个括号的基础上在最外面添加一个大括号或者在最左边或最右边添加一个小括号。形如：'（' + n-1的return_list + '）' 或者 '()' +  n-1的return_list 或者  n-1的return_list + '()', 当然有一个特例就是没有嵌套的n-1 return_list。形如'()()()...()'，在左右添加是一样的。代码大致如下：`
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 1:
            return ['()']
        
        last_list = generateParenthesis(n-1)
        outcome = []
        
        for item in last_list:
            new_item1 = '(' + item + ')'
            new_item2 = '()' + item
            new_item3 = item + '()'
            outcome.append(new_item1)
            outcome.append(new_item2)
            if new_item3 in outcome:
                continue
            outcome.append(new_item3)
        
        return outcome`
但是不知道递归为啥会报错，generateParenthesis(n-1) is not defined. 希望有大佬能解答一下。