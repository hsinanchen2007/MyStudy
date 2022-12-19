```python
# 相当于是根据所给式子构造运算二叉树的问题，
# 所以每次遍历其中的每个运算符作为根结点，
# 该运算符前后的内容分别递归得到左右子树可能的构造，每种左右子树组合得到一种构造结果

    def diffWaysToCompute(self, input: str) -> List[int]:
        # 获得数字列表和运算符列表，也可以不这么做直接递归处理字符串
        nums = []
        ops = []
        num = ''
        for i in input:
            if i in ['+', '-', '*']:
                nums.append(int(num))
                ops.append(i)
                num = ''
            else:
                num += i
        nums.append(int(num))
        
        # 递归运算
        def calc(nums,ops):
            if not ops:
                return [nums[0]]
            if len(ops) == 1:
                if ops[0] == '+':
                    return [nums[0]+nums[1]]
                elif ops[0] == '-':
                    return [nums[0]-nums[1]]
                else:
                    return [nums[0]*nums[1]]
            res = []
            for i in range(len(ops)):
                for num1 in calc(nums[:i+1], ops[:i]):
                    for num2 in calc(nums[i+1:], ops[i+1:]):
                        res.append(calc([num1, num2], [ops[i]])[0])
            return res

        return calc(nums, ops)
```
