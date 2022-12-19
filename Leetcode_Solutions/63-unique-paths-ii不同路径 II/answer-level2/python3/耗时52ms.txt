```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n1 = len(obstacleGrid)
        n2 = len(obstacleGrid[0])
        if obstacleGrid == [[0]]:
            return(1)
        elif obstacleGrid == [[1]]:
            return(0)
        elif obstacleGrid[0][0] == 1:
            return(0)
        n3 = n1 + n2 - 2
        zidian1 = {"0,0":1}
        for i in range(n3):
            zidian2 = {}
            for j in zidian1:
                list1 = j.split(",")
                aa = int(list1[0])
                #print(list1,j)
                bb = int(list1[1])
                if  aa+1 < n1:
                    if obstacleGrid[aa+1][bb] != 1:
                        str1 = str(aa+1)
                        str1 = str1+","+list1[1]
                        if str1 not in zidian2:
                            zidian2[str1] = zidian1[j]
                        else:
                            zidian2[str1] = zidian2[str1] + zidian1[j]
                if bb+1 < n2:
                    if  obstacleGrid[aa][bb+1] != 1:
                        str1 = str(bb+1)
                        str2 = list1[0] +","+ str1
                        #print(str2)
                        if str2 not in zidian2:
                            zidian2[str2] = zidian1[j]
                        else:
                            zidian2[str2] = zidian2[str2] + zidian1[j]
            #print(zidian2,"###")
            zidian1 = zidian2
        if zidian2 != {}:
            return(list(zidian2.values())[0])
        else:
            return(0)

        
```
![image.png](https://pic.leetcode-cn.com/fd108f6b20e2770f7294f81c119c80f710af09dd061ade02ff9bee90a6e9c01f-image.png)

![image.png](https://pic.leetcode-cn.com/e7f8af6938b052eef55e3e056d62e7ae6df172dd06fa4a869b0a12ded050e640-image.png)

这就是锲而不舍吧
笔者思来想去，发现此题并没有规律可循，只需要从(0,0)出发进行遍历即可，但需要使用字典来保存遍历过程中的相同坐标，前期笔者想使用列表，发现超时了