### 解题思路
![image.png](https://pic.leetcode-cn.com/1b60ad3c818c9943236efb59c0270cb28e079747e53792b6c2fc39fb741f98fd-image.png)

从46->306->842过来的。
代码和306没啥区别。
几点注意以下：
1.判断序列中的数字不要越界，math.pow(2,31)-1
2.不要超时，如果前两个数的长度已经大于一半了，可以及时停止搜索了。
3.返回的是序列，需要每次把数据加进去。
4.不能拆分的时候返回空数组[]而不是false。坑死我

根据第二点我去优化下306的时间问题。

### 代码

```python3
import re
import math
class Solution:
    def splitIntoFibonacci(self, S: str) -> List[int]:
       
        res = []
        max_num = math.pow(2,31)-1

        # 回溯法找出前两个数
        def traceback(numstr,temp):
            if len(temp) == 2 :
                if len(temp[0])>(len(S)/2+2) or len(temp[1])>(len(S)/2+2) or int(temp[0])>max_num or int(temp[1])>max_num:
                    return
                else:
                    if len(re.findall('^{}'.format(str(int(temp[0]) + int(temp[1]))),numstr)):
                        first,second = temp[0],temp[1]

                        #如果前两个数不是以0开始的，如果以0开始，那么必须是0，才能加入数组
                        if not ((first.startswith('0') and len(first)>1) or (second.startswith('0') and len(second)>1)):
                            res.append( (first,second))
                    return
            
            for i in range(1,len(numstr)):
                traceback(numstr[i:],temp+[numstr[:i]])
    
        traceback(S,[])

        # 在两个数固定的情况下，用回溯法判断是否是累加数
        def is_true(first,second,numstr):

            nextS = re.findall('^{}'.format(str(int(first)+int(second))),numstr)

            if len(nextS):
                if nextS[0] == numstr:
                    if not (int(second)>max_num or int(numstr)>max_num):
                        result.append(second)
                        result.append(numstr)
                    return

                result.append(second)

                temp = nextS[0]
                first = second
                second = temp

                if int(first)>max_num or int(second)>max_num:
                    return
                
                is_true(first,second,numstr[len(second):])
                
        # 可能前两个数有多种情况，每种都需要验证
        
        if len(res)>0:
            result_all = []
            for i in range(len(res)):
                (first,second) = res[i]
                result = [first]
                is_true(first,second,S[len(first+second):])
                
                len_result = 0
                
                for j in range(len(result)):
                    len_result += len(result[j])
                if len_result == len(S):
                    return result


        #找不到前两个数直接返回false
        else :
            return []
```