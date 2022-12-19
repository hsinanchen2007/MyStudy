```
        result_list = []
        if strs:
            if len(strs) == 1:  # 只有一个字符串数组
                return strs[0]
            else:
                num_list = [len(one) for one in strs]
                d = min(num_list)  # 最短字符串的长度
                if d == 0:  # 存在空字符串
                    return ''
                else:
                    for i in range(1, d+1):
                        j = 1
                        flag = len(strs)
                        while j <= len(strs)-1:
                            if strs[0][0:i] == strs[j][0:i]:
                                j += 1
                            else:
                                j -= 1
                                break
                        if j == flag:  # 都有的公共前缀加入结果列表
                            result_list.append(strs[0][0:i])
                        else:
                            result_list.append("")  # 不能加入结果列表的就以空字符串加入，避免max判断出错
                    num_list = [len(one) for one in result_list]
                    m = num_list.index(max(num_list))
                    return result_list[m]
        else:  # 空数组
            return ''

```
