```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        zidian1 = {"0,0":grid[0][0]}
        #for i in zidian1:
        #	print(i)
        while True:
            zidian2 = {}
            for i in zidian1:
                aa = i.split(",")
                if int(aa[0]) < m-1 and int(aa[1]) < n-1:
                    bb = str(int(aa[0])+1)+","+aa[1]
                    if bb not in zidian2.keys():
                        zidian2[bb] = zidian1[i]+grid[int(aa[0])+1][int(aa[1])]
                    else:
                        if zidian1[i]+grid[int(aa[0])+1][int(aa[1])] < zidian2[bb]:
                            zidian2[bb] = zidian1[i]+grid[int(aa[0])+1][int(aa[1])]
                    cc = aa[0] + ","+str(int(aa[1])+1)
                    if cc not in zidian2.keys():
                        zidian2[cc] = zidian1[i]+grid[int(aa[0])][int(aa[1])+1]
                    else:
                        if zidian1[i]+grid[int(aa[0])][int(aa[1])+1] < zidian2[cc]:
                            zidian2[cc] = zidian1[i]+grid[int(aa[0])][int(aa[1])+1]
                        else:
                            pass
                elif int(aa[0]) < m-1 and int(aa[1]) == n-1:
                    bb = str(int(aa[0])+1)+","+aa[1]
                    if bb not in zidian2.keys():
                        zidian2[bb] = zidian1[i]+grid[int(aa[0])+1][int(aa[1])]
                    else:
                        if zidian1[i]+grid[int(aa[0])+1][int(aa[1])] < zidian2[bb]:
                            zidian2[bb] = zidian1[i]+grid[int(aa[0])+1][int(aa[1])]
                        else:
                            pass
                elif int(aa[0]) == m-1 and int(aa[1]) < n-1:
                    cc = aa[0] + ","+str(int(aa[1])+1)
                    if cc not in zidian2.keys():
                        zidian2[cc] = zidian1[i]+grid[int(aa[0])][int(aa[1])+1]
                    else:
                        if zidian1[i]+grid[int(aa[0])][int(aa[1])+1] < zidian2[cc]:
                            zidian2[cc] = zidian1[i]+grid[int(aa[0])][int(aa[1])+1]
                        else:
                            pass
                else:
                    break
            if zidian2 == {}:
                return(list(zidian1.values())[0])
            else:
                zidian1 = zidian2
```
