def duplicateZeros3(arr):
    j = -1  # 每一次从负1开始，表示索引位置，也可以称之为哨兵位置
    flag = 2   #最后的0要1个，还是要2个，初始设置为2个
    zero = 0  #数组中的0的个数
    nonzero = 0 #数组中的非0的个数
    for i, item in enumerate(arr):   #i用于存放结束位置
        if item == 0:
            j += 2        #如果是此时的item是0，那么哨兵移动2个位置
            zero += 1     #0的个数添加一个
        else:
            j += 1   #如果是此时的item是非0，那么哨兵移动1个位置
            nonzero += 1  #非0的个数添加一个
        if j >= len(arr)-1:  #索引超出位置就要退出，在退出之前判断最后的那个item是否为0，如果是0，还要判断这个最后的0要1个还是2个
            if item == 0 and zero * 2 + nonzero == len(arr)+1:
                flag = 1
            break
    
    j = len(arr)-1
    for k in range(i, -1, -1):   #从后往前填充数组，从i开始
        if arr[k] == 0:
            if k == i and flag == 1:  #如果flag等于1，也就是表示最后的那个是0，并且是只要1个0
                arr[j] = 0
                j -= 1
            else:
                arr[j] = arr[j-1] = 0
                j -= 2
        else:
            arr[j] = arr[k]
            j -= 1
    print(arr)