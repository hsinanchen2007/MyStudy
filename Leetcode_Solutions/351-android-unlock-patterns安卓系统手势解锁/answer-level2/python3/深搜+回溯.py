```
        total = 0
        choices = {1: set([3,7,9]), 2: set([8]), 3: set([1,9,7]), 4: set([6]), 5: set([]), 6: set([4]), 7: set([1,3,9]), 8: set([2]), 9: set([1,3,7])}

        def isValid(pre_coord, curr_coord, choi):
            """
               判断不相邻的情况下, 中间是否经过未被访问的点
            """
            if curr_coord in choices[pre_coord]:
                middle = pre_coord + curr_coord
                
                if middle //2 < middle / 2:
                    # 表明是小数
                    return True
                if middle/2 not in choi:
                    return False
                return True
            
            return True

        def backtrack(index, path):
            nonlocal num
            # 提前终止条件
            if m <= len(path) <= n:
                # print(len(path))
                num += 1
            if len(path) > n:
                return
            
            # for循环递归
            for i in range(1, 10):
                # 判断下一个选择是否有效
                if i in path or not isValid(index, i, path):
                    continue
                
                # 作出选择
                path.add(i)
                # 进一步递归
                backtrack(i, path)
                # 撤销选择
                path.remove(i)
        
        # 四个角一样, 所以只需算1, 然后乘以4
        num = 0      
        backtrack(1, set([1]))
        total += num*4
        num = 0
        backtrack(2, set([2]))
        total += num*4
        num = 0
        backtrack(5, set([5]))
        total += num

        return total
```
