
对于每一个房屋,寻找最近的供暖器的距离
这些距离中的最大值就是所求半径

```
s_max = 0
for i in houses:
    s_i = 10e9
    for j in heaters:
        s = abs(i - j)
        if s < s_i:
            s_i = s
    if s_i > s_max:
        s_max = s_i
return s_max
```
结果暴力算法直接超时。。。



用滑动思路寻找最小距离
```
s_max = 0 
houses_tmp = sorted(houses) # 先排序
heaters_tmp = sorted(heaters)
heaters_point = 0 # 建立加热器指针
for i in houses_tmp: # 对房间作循环：
    # 如果出现指针所在加热器在房间之前,而且下一个加热器的位置也在房间之前,且指针不是指向最后一个加热器
    # 则说明这个加热器需要的加热半径一定大于下一个加热器,故将指针直接指向下一个加热器
    while heaters_point != len(heaters) - 1 and heaters_tmp[heaters_point] < i and heaters_tmp[heaters_point + 1] < i:
        heaters_point += 1

    # 如果指针已经在最后一个加热器上,则后面的所有房间只能通过该加热器加热
    if heaters_point == len(heaters) - 1:
        s_len = abs(i-heaters_tmp[heaters_point])
    
    # 通过上面的while循环可以保证房间i在两个加热器之间.通过取绝对值的最小值来判断距离最近的加热器
    else:
        s_len = min(abs(i-heaters_tmp[heaters_point]),
                    abs(i-heaters_tmp[heaters_point+1]))
    
    # 选择这些距离中的最大值
    if s_len > s_max:
        s_max = s_len
return s_max
```
