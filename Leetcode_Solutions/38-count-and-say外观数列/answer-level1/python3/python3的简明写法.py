双重循环的解法，核心思想在内层循环对上一个数组的解读，这里写了一个单独的函数解决内循环。

    def count_last(last):
        i = 0
        res = ''
        while i < len(last):
            tmp_count = 0
            char = last[i]

            while char == last[i]:
                tmp_count += 1
                i += 1
                if i >= len(last): break
            res += (str(tmp_count) + str(char))
        return res

    if n == 1:
        return '1'

    for i in range(1, n + 1):
        if i == 1:
            last_count = '1'
        else:
            count = count_last(last_count)
            last_count = count