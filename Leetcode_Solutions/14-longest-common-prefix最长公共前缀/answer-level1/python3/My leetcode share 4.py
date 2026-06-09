- **思路:**
- 重要用python中的**zip函数**, 它接收可迭代的对象, 把所有元素中,每个元素对应的元素,打包成元祖为元素的列表(现在是对象需要用list转换)
- **例如**:
- lis = ['fdss','frge']
- lisx = list(zip(*lis))
- print(lisx)   
- # 打印结果
- # [(f,f),(d,r),(s,g),(s,e)]  
- 如果之前不知道zip函数, 可以自己用pycharm打印一下, 印象更深刻.   

![111111.wmv](e69c9a55-7be4-480f-bcbd-d1a68575a3a8)








```
def length

    str = ''

    for i in zip(*strs):

        if len(set(i)) == 1:
            str += i[0]

        else:
            break

    return str



```

