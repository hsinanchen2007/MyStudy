
好几个for循环：
```
def Anycall(string):
    S=[];target=[]
    dict_={2:"abc",
           3:"def",
           4:"ghi",
           5:"jkl",
           6:"mno",
           7:"pqrs",
           8:"tuv",
           9:"wxyz"            
            }
    if not string:
            return string
    if len(string)<2:
            return dict_[int(string)]
    for i in string:
        S.append(dict_[int(i)])
    for n in range(len(S)):
        for i in range (n+1,len(S)):
            for j in range (i+1,len(S)):
                for n_min in range(len(S[n])):
                    for i_min in range (len(S[i])):
                        for j_min in range (len(S[j])):
                            target.append(S[n][n_min]+S[i][i_min]+S[j][j_min])

```
当我这么写的话是只支持输入的字符串长度为3个的，如果字符串的长度是2个，就是4个，也就是说，for循环的结构的个数与输入字符串的长度关系是n=2*len(digits),现在我们可以去尝试写一下当字符串的长度为2时，for循环的代码：
```
def Anycall(string):
    S=[];target=[]
    dict_={2:"abc",
           3:"def",
           4:"ghi",
           5:"jkl",
           6:"mno",
           7:"pqrs",
           8:"tuv",
           9:"wxyz"            
            }
    if not string:
            return string
    if len(string)<2:
            return dict_[int(string)]
    for i in string:
        S.append(dict_[int(i)])
        for i in range (len(S)):
            for j in range (i+1,len(S)):
                    for i_min in range (len(S[i])):
                        for j_min in range (len(S[j])):
                            target.append(S[i][i_min]+S[j][j_min])

```
也就是说，这种方法当输出的字符串长度不是恒定值的话是不可取的，那么我们如何去解决这个没有记忆的上次的版本？
我们可以设想一下，在这段代码中：
```
for i_min in range (len(S[i])):
    for j_min in range (len(S[j])):
        target.append(S[i][i_min]+S[j][j_min])
```
我们一定要这么写吗？是不是可以有一个空列表，如果输入的是"23"的话，那么是不是可以挨个的先将"2"的字符串进入一个变量的内存里，然后再将"3"的所有字符串挨个的和上次进内存的所有字符串中的字符进行拼接。
好的，我们将代码转化一下，由于第一次进变量内存的"2"的所有字符串没有需要进行拼接的对象，因为这个变量内存中是空的，但是我们对于这个空的表达不是`[]`这样子的表达，因为这是定义了一块没有值的列表，我们这样定义`res=['']`,也就是说"2"中的所有字符串'a','b','c',都要与这个空的字符串''进行比较，我们按照这个思路走：
1.当"3"的所有字符串中的字符要进来与上次拼接的时候，我们就将上次的res=['a','b','c']中'a','b','c'分别看做一个整体
2."3"进来了，我们将'a','b','c'与 "3"中的 "d","e","f" 挨个的拼接，需要注意的是不分前后顺序，所以我们默认"2"中的数就在"3"前面，因此我们有3*3的拼接类别。
3.当下一个"4"进来时，我们将上次拼接的`['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']` 中的每一个元素看做一个整体，在用上面2的步骤继续操作。
下面是代码:
```
def Anycall(digits):
    dict_={"2":"abc",
           "3":"def",
           "4":"ghi",
           "5":"jkl",
           "6":"mno",
           "7":"pqrs",
           "8":"tuv",
           "9":"wxyz"            
            }
    if not digits:
       return []
        
    res=['']
    temp=[]
    for i  in digits:
        for j in res:
            for m in dict_[i]:
                print("m=",m)
                temp.append(j+m)
        res=temp
        temp=[]
```
注意这个临时变量temp的意义，如果我们就用`res.append(j+m)`的话,那么会导致一个问题：因为我们的res代表的就是上面所说的一个变量的内存，代表着的是输如的digits中的每一个字符串在进入内存后的拼接好的结果，而我们的temp起到的就是这个能将让res在处理一个digits中每一个字符串进入的时候能够凭借好的原因。
解释temp:
temp就像是一个装货的火车，处理每一次digits进内存的拼接工作，把挨个拼接好的装在自己的尾巴后面，当处理完digits中的一个字符串如"3"的时候，就会将自身清零，因为他还需要在上次的基础上(res)再次拼接，如果不清零的话，那么会导致:
当输入为"23",
"2"进去之后,res=['a','b','c'],由于temp要在res内存里面追加，但是temp上次把"2"中所有字符串与空字符串""拼接完后的状态也是['a','b','c']，这会导致"3"中所有进来的数要执行`temp.append(j+m)`的操作，j是res中的，m是"3"中的，temp就会一直追加：
['a','b','c','ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf'],下一次如果是"4"的话，可想而知，还会追加在后面...
所以当问题转化为:电话号码的所有组合可能性的时候，也许temp就不需要清零了。

补充一点，在评论区看到的一行中有2个for循环:其实关键的一点就是外围的`[ ]`符号，这个默认将上次的装载temp清零，而且可以返回一个list类型。
现在问题回到了一开始，我该如何去优化我的那份好几个for循环的代码？
其实可以不用去想了，主要的原因就是因为我通过n个指针去取值然后拼接，但是这n个指针的个人取决于我输入的digits的长度,如果用指针暴力遍历的话，一般都是目标是固定的。
现在有个问题遗留下来了:
这个temp就是一个指针，他每次装载完都会赋值给res，那么这个问题中一共有多少个指针？
因为python是面向对象的，所有的变量赋值就是指针的操作，那么我想问的是 ：
temp 就是一个指针,存储着列表的首地址，难道指针变量不仅存储着地址，他也有地址的吗？