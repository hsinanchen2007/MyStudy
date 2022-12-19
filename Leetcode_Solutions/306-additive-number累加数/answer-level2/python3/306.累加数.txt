### 解题思路
妈耶，我太难了
理解了46题全排列的回溯思想我就飘了，就来找回溯算法的题目了。fine，累死我算了。

这题的前提是，得先找出前两个数字，固定他俩后面就好判断了啊喂。
我来学回溯算法的，当然第一步，我要想办法写个回溯。
和全排列不同的是，[1,2,3,4]全排列的话，假设第一次选了1，那么他的下一个节点可选数组为[2,3,4],路径数组为[1]
但对于这一题，1234 找出前两个累加数的话，假设第一次选了1，那么他的下一个节点可选数组为[2,23,234],路径数组为[1]
也就是下一个传递过去的可选数组应该是去掉前i个就行，也就是numstr[i:]，路径数组就是他的前i个temp+[numstr[:i]]。
结束条件呢？就是路径数组的长度等于2，并且相加起来的数字转化为字符串之后在可选数组里首部就可。
就把这两个数加入满足条件的两个数数组中去。
中间有个if需要判断，如果这两个数其中有以0开始并且不是0的数，那么就不加入数组。


fine，下一步，前两个数固定之后判断是否是累加数的回溯就容易多了。
但是值得注意的是，满足条件的前两个数不一定是一组，所以需要每一组都判断以下。比如（12122436） （1，21）和（12，12）都满足。
别问我怎么知道的，都是泪。

啊我也不知道我写的是啥。反正吭哧吭哧半天搞出来了。
我累死了，以上。
即使有什么更简单的方法我也不想琢磨了。
我太累了。
太累了。
累了。
了。

这只是一个中等题目啊啊啊。
我怎么那么菜鸡啊喂。

### 代码

```python3
import re
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        
        res = []
        len_num = len(num) + 2

        # 回溯法找出前两个数
        def traceback(numstr,temp):
            if len(temp) == 2 :
                if len(re.findall('^{}'.format(str(int(temp[0]) + int(temp[1]))),numstr)):
                    first,second = temp[0],temp[1]

                    '''减少搜索时间,842题超时想到的，回来补充一下'''
                    if len(first)>len_num or len(second)>len_num:
                        return

                    #如果前两个数不是以0开始的，如果以0开始，那么必须是0，才能加入数组
                    if not ((first.startswith('0') and len(first)>1) or (second.startswith('0') and len(second)>1)):
                        res.append( (first,second))
                return
            
            for i in range(1,len(numstr)):
                traceback(numstr[i:],temp+[numstr[:i]])
    
        traceback(num,[])

        # 在两个数固定的情况下，用回溯法判断是否是累加数
        def is_true(first,second,numstr):

            nextS = re.findall('^{}'.format(str(int(first)+int(second))),numstr)

            if len(nextS):
                if nextS[0] == numstr:
                    result.append(numstr)
                    return

                temp = nextS[0]
                first = second
                second = temp

                is_true(first,second,numstr[len(second):])

        # 可能前两个数有多种情况，每种都需要验证
        if res:
            result_all = []
            for i in range(len(res)):
                (first,second) = res[i]
                result = []
                is_true(first,second,num[len(first+second):])
                result_all += result

            #只要有一种情况成立即可
            if result_all:
                return True
            else:
                return False

        #找不到前两个数直接返回false
        else :
            return False


```

![image.png](https://pic.leetcode-cn.com/a438e0e55a9e1eef137bae5515f469eeae855d38111cb2ae90a71bca7378faed-image.png)
