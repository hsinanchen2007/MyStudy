```
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        # 新建new_push,用来存储pushed中的元素，一个个解决popped中的元素
        # 拿到popped中的元素ele：先判断new_push中的最后一个元素是不是==ele
        # 情况1：等于，将最后一个元素pop掉，继续下一个ele，如果已经没有ele了，结束，返回true
        # 情况2：不等于，判断新元素==ele：
            # 等于，直接下一个ele，将pushed中新元素舍弃，如果已经没有ele了，结束，返回true
            # 不等于，将pushed中的元素push到new_push中，如果pushed元素都用完了，结束，返回False
        if len(pushed)==len(popped) and len(pushed)>0:
            #
            index=0
            length=len(pushed)
            new_push=[]
            i_pop=0
            for ele in popped:
                i_pop=i_pop+1
                print ("解决元素",ele)
                # 判断new_push中的最后一个元素是不是==ele
                if len(new_push)>0:
                    if (ele==new_push[len(new_push)-1]):
                        print(new_push[len(new_push)-1])
                        judge=True 
                    else:
                        judge=False
                else:
                    judge=False

                if (judge): #push中有
                    print("直接pop OK")
                    new_push.pop()
                    if i_pop==length:
                        return True
                elif (index<length): #新增元素，并判断有没有
                    print("need new one")
                    while(ele!=pushed[index]):#不等于继续新增
                        print("新增元素",pushed[index])
                        new_push.append(pushed[index])
                        index=index+1
                        if (index>=length):
                            return False
                        print("index=",index)
                    #等于,新增 再 pop，无需对new_push操作，index+1
                    if i_pop==length:
                        return True
                    else:
                        index=index+1
                        print("index=",index)
                else:
                    return False
        elif len(pushed)!=len(popped):
            #
            return False
        else:
            return True
```
