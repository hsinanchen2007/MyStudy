![python.png](https://pic.leetcode-cn.com/71a0e2383b368dfabef58dbc60b8371f6ad18a7b6d285e066e6b4e296ee0b1ec-python.png)
    


    class Solution:    
        def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
            l = len(words)
            i = 0
            new_list = []
            while i<l:
                x = len(words[i])
                stack = []
                k = 0
                while (x + k)<= maxWidth:
                    stack.append(words[i])
                    last = maxWidth - (x+k)
                    i += 1
                    k += 1
                    if i<l:
                        x += len(words[i])
                    else:
                        break
                if i<l:
                    while last:
                        if len(stack)==1:
                            stack[0] += ' '*last
                            break
                        else:
                            for j in range(len(stack)-1):
                                stack[j] += ' '
                                last -= 1
                                if last == 0:
                                    break

                    s = ''
                    ls = len(stack)
                    while stack!=[]:
                        if ls==1:
                            new_list.append(stack.pop(0))
                        else:
                            first = stack.pop(0)
                            if stack!=[]:
                                s += (first+' ')
                            else:
                                s += first
                    if ls!=1:
                        new_list.append(s)#处理非最后一个词组
                else:
                    while 1:
                        if len(stack)==1:
                            stack[0] += ' '*last
                            new_list.append(stack[0])
                            break
                        else:
                            s = ''
                            while stack!=[]:
                                first = stack.pop(0)
                                if stack!=[]:
                                    s += (first+' ')
                                else:
                                    s += first
                            s += ' '*last
                            new_list.append(s)
                            break#处理最后一个词组
            return new_list
                        
                    