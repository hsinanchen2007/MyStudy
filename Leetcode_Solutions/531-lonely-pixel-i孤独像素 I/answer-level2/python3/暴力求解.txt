```
        size_row = len(picture)
        size_col = len(picture[0])
        # candidate记录了哪些行只包含一个B, 然后后续的操作就是在这些记录上进一步判断列上有没有之前出现过B
        candidates = {}
        col_set = set()

        for i in range(size_row):
            count = 0
            candidate_i, candidate_j = 0, 0
            # 首先找出所有行中具有唯一一个B的行
            for j in range(size_col):
                if picture[i][j] == "B":
                    count += 1
                    candidate_i, candidate_j = i, j
            
            # 对于每一个具有唯一的一个B的行, 如果最后发现该列上有多余一个B, 那么直接pass
            if count == 1:
                if candidate_j in candidates:
                    candidates.pop(candidate_j)
                else:
                    # col_set记录了之前的行中，哪些列包含B, 如果该列在之前的行中也出现了, 那么不用记录
                    if candidate_j not in col_set:
                        candidates[candidate_j] = candidate_i 
            
            for j in range(size_col):
                if picture[i][j] == "B":
                    col_set.add(j)
        
        return len(candidates)
```
