方法就是另外一个题解的方法，这里给出时间效率比较高的一种python实现
class Solution(object):
    def catMouseGame(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        nodenum=len(graph)
        g=[[[None for _ in range(2)] for _ in range(nodenum)] for _ in range(nodenum)]
        
        '''
        假设status是一个三维矩阵，表示状态转移。这里按照所有可能情况给出基本情况判断：

status[i][j][0]表示鼠在节点i，猫在节点j，且此时轮到鼠行动的状态；
status[i][j][1]表示鼠在节点i，猫在节点j，且此时轮到猫行动的状态；
status[i][j][k]如果值为0，表示默认值，平局；
如果status[i][j][k]值为1表示鼠胜；如果值为2表示猫胜
由规则可知，初始状态下可以确定的非平局状态有：

status[0][j][k] = 1；此刻鼠在洞里，必胜
status[i][i][k] = 2, i~=0；此刻猫鼠同位，猫必胜
status[i][0][k]不能被访问。
由最终状态倒推之前的可能性：

对于节点status[i][j][0]来说，此时轮到鼠行动，上一步轮到猫行动：
1.1 如果status[i][j][0]=1，即此步鼠胜。则对于能一步到达该状态的每一个可能的上一步状态status[i][graph[j]][1]来说，如果该“上一步状态”的所有下一步状态（包括status[i][j][0]）都是鼠胜，则该“上一步状态”一定是鼠胜。
1.2 如果status[i][j][0]=2，即此步猫胜。则由于上一步轮到猫行动，鼠不能动，所以对于能一步到达该状态的所有可能的上一步状态status[i][graph[j]][1]都为2，即上一步猫已经完全锁定胜局。
1.3 如果status[i][j][0]=0，即此步未知（平局），则无法对上一步状态进行判断。


'''
        '''
            对于节点status[i][j][1]来说，此时轮到猫行动，上一步轮到鼠行动：
2.1 如果status[i][j][1]=1，即此步鼠胜。由于上一步轮到鼠行动，所以对于能一步到达该状态的所有可能的上一步状态status[graph[i]][j][0]来说，值都为1，即上一步鼠已经完全锁定胜局。
2.2 如果status[i][j][1]=2，即此步猫胜。则对于能一步到达该状态的每一个可能的上一步状态status[graph[i]][j][0]来说，如果该“上一步状态”的所有下一步状态（包括status[i][j][1]）都是猫胜，则该“上一步状态”一定是猫胜。
2.3 如果status[i][j][1]=0，即此步未知（平局），则无法对上一步状态进行判断。
'''
        #initial
        status=[]
        for jj in range(1,nodenum):
            for kk in range(2):
                g[0][jj][kk]=1
                status.append([0,jj,kk])
                g[jj][jj][kk]=2
                status.append([jj,jj,kk])
        
        while len(status)>0:
            v=status.pop()
            s=g[v[0]][v[1]][v[2]]
            if v[2]==0:
                if s==2:
                    for jj in graph[v[1]]:
                        if jj!=0:
                            if g[v[0]][jj][1]==None:
                                g[v[0]][jj][1]=2
                                status=[[v[0],jj,1]]+status
                else:
                    for jj in graph[v[1]]:
                        if jj!=0:
                            if g[v[0]][jj][1]==None:
                                sig=True
                                for kk in graph[jj]:
                                    if kk!=0:
                                        if g[v[0]][kk][0]!=1:
                                            sig=False
                                            break
                                if sig:
                                    g[v[0]][jj][1]=1
                                    status=[[v[0],jj,1]]+status            
            else:
                if s==1:
                    for jj in graph[v[0]]:
                        if g[jj][v[1]][0]==None:
                            g[jj][v[1]][0]=1
                            status=[[jj,v[1],0]]+status
                else:
                    for jj in graph[v[0]]:
                        if g[jj][v[1]][0]==None:
                            sig=True
                            for kk in graph[jj]:
                                if g[kk][v[1]][1]!=2:
                                    sig=False
                                    break
                            if sig:
                                g[jj][v[1]][0]=2
                                status=[[jj,v[1],0]]+status
            if g[1][2][0]!=None:
                return g[1][2][0]
        return 0
                                    
                                    
                                    
                                
                                
                                
                                
                                
                                
                                
                    
            
            
            
            
            
            
        
                               
        
        
        