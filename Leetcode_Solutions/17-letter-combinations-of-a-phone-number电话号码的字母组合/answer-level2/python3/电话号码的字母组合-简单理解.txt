
* **总思路**——每添加一个数字所形成的新组合,只是在上一数字所形成的所有组合上添加新的3种(4种,'pqrs'或'wxyz')新的字符

* **举例**——就像'23'。先是'2'('abc'),在原来[ ]的基础上添加成了['a','b','c']；
  然后是'3'('def'),给的 **a** 添加 **d**,**e**,**f** 变成[a**d**,a**e**,a**f**]
  给 b 添加**d**,**e**,**f**,变成[b**d**,b**e**,b**f**]
  给 c 添加**d**,**e**,**f**,变成[c**d**,c**e**,c**f**]
  最后一拼接就是['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']

* **实现**——那代码怎么实现能？ 两个循环即可.
  第一个循环取出digits数字
  第二个循环取出上一组合每一个字符添加那3种(4种)新字符即可
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        #特殊情况
        if(not digits):
             return []
        #用列表列出所有数字对应的字符串
        str_in_num=['abc','def','ghi','jkl','mno','pqrs','tuv','wxyz']
        end_list=['']   
        #第一个循环,取出每个数字
        for strnum in digits:
            #表示数字在列表的位置                                                                   
            num=int(strnum)-2
            tmp_list = list()
            #第二个循环,取出上次每一种组合分别添加字符
            for strs in end_list:                           
                tmp_list.append(strs + str_in_num[num][0])
                tmp_list.append(strs + str_in_num[num][1])
                tmp_list.append(strs + str_in_num[num][2])
                #num==5对应'pqrs',num==7对应'wxyz',此时要多添加一个
                if(num==5 or num==7):
                    tmp_list.append(strs+str_in_num[num][3])
            end_list=tmp_list
        return end_list
```
