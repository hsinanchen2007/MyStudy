
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        j = len(arr)            #固定列表长度
        while i < j:
            if arr[i] == 0:
                arr.insert(i,0) #原地插入0
                arr.pop()       #删掉末项保持列表长度不变
                i += 2          #跳过插入项 
            else:
                i += 1
                

执行用时 :60 ms, 在所有 Python3 提交中击败了99.65%的用户
内存消耗 :13.3 MB, 在所有 Python3 提交中击败了100.00%的用户