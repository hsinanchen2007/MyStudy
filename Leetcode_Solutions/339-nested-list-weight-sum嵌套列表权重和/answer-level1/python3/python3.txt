        queue_list = []
        sum_list = 0
        for nest in nestedList:
            queue_list.append([nest, 1])
        while queue_list:
            curr = queue_list.pop(0)
            if curr[0].isInteger():
                sum_list += curr[0].getInteger() * curr[1]
            else:
                for c in curr[0].getList():
                    queue_list.append([c, curr[1] + 1])
        return sum_list