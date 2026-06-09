        row,res = len(mat),[]
        for i in range(row):
            res.append((int(i),mat[i].count(0)))
        return ([a for a,b in sorted(res,key=lambda x:(x[1]),reverse=True)])[:k]