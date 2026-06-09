```
class Solution:
    def isEscapePossible(self, blocked: List[List[int]], source: List[int], target: List[int]) -> bool:
    
        #判断一个点是不是在source为中心的300*300范围，在的话返回True
        def isin(node:list)->bool:
            if node[0]>=0 and node[0]<300 and node[1]>=0 and node[1]<300:
                return True
            return False        


        #判断一个给定点有没有被blocked围住,没围住或遍历到了目标点返回True
        #200个block最大围住格子19900个，只要从一个点出发走出了超过这个数目的，即为没围住
        def isNotBlocked(blocked:list,source:list,target:list)->bool:
            if not blocked or source == target:
                return True
            if source in blocked or target in blocked:
                return False

            
            #降维,id=X*MAX(Y)+Y，用0，1来表示是否可以访问，并用blocked初始化
            nodeValue=[1]*(300*300)

            x_0=max(0,source[0]-150)-max(0,source[0]+150-10**6)
            y_0=max(0,source[1]-150)-max(0,source[1]+150-10**6)


            for block in blocked:
                x=block[0]-x_0
                y=block[1]-y_0
                if isin([x,y]):
                    nodeValue[x*300+y]=0


            #开始计数，将已经数过的结点从stack里拿出来放到blocked里,刚数过的结点放stack里，递归
            count = 1   #source
            queue = [source]
            nodeValue[(source[0]-x_0)*300+source[1]-y_0]=0

            while(queue):

                node = queue.pop(0)
                node_nextList = [ [node[0]+1,node[1]], [node[0]-1,node[1]], [node[0],node[1]+1], [node[0],node[1]-1] ]

                for nextNode in node_nextList:
                    x_n = nextNode[0]-x_0
                    y_n = nextNode[1]-y_0

                    if nextNode == target:
                        return True
                    if isin([x_n,y_n]) and nodeValue[x_n*300+y_n]:
                        queue.append(nextNode)
                        count += 1
                        if count>19900:
                            return True
                        nodeValue[x_n*300+y_n]=0

            return False

        #source和target都没被围住则能连通

        if isNotBlocked(blocked,source,target) and isNotBlocked(blocked,target,source):
            return True
        return False

```