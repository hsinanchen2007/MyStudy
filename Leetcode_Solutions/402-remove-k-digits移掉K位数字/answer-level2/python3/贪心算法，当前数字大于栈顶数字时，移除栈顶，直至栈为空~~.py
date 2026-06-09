**从头开始遍历字符组，如果当前数字大于栈顶则将其放入栈中，否则使用贪心算法移除栈顶元素。若未遍历完字符串k就已经减小为0，可以提前挑出循环以节省时间；若遍历完字符串k仍不为0，因为此时栈中数字是升序排列，所以可以依次去除栈顶的元素，更新k直至其为0，此时栈中剩余元素就是最终结果（当然还需要去除开头的‘0’）**

def removeKdigits(self, num: str, k: int) -> str: 
      
      #考虑一般情况：
      if len(num) == k:
        return '0'
      if k == 0:
        return num
        
      #定义栈和返回结果：
      stack = []
      res = ''
      
      '''贪心算法：将字符串中的数字依次入栈，若当前字符大于栈顶数字，
        弹出栈顶并更新k值直至k为0。若循环结束还k还不为0，则去掉栈顶
        剩余的k个元素。'''
        
      #定义遍历结束点：
      end_point = -1
        
      #遍历字符串：
      for index, value in enumerate(num):
        if len(stack) == 0 or int(value) >= int(stack[-1]):
          stack.append(value)
        else:
          while len(stack) > 0 and int(value) < int(stack[-1]):
            stack.pop()
            k -= 1
            if k == 0:
              break
          stack.append(value)
        #当k为0时可以提前结束循环
        if k == 0:
          end_point = index
          break
            
      #讨论k的不同情况：
      if k == 0:
        res = ''.join(stack) + num[end_point+1:]
      else:
        while k != 0:
          stack.pop()
          k -= 1
        res = ''.join(stack)
      
      #去掉开头的‘0’：
      if res == '':
        return '0'
      else:
        index = 0
        while res[index] == '0':
          if index == len(res)-1:
            return '0'
          index += 1
      return res[index:]
