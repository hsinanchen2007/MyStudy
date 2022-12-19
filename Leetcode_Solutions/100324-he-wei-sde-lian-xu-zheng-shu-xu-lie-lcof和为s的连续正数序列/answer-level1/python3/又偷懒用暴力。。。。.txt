#暴力搜索，其实应该可以用2*n-x这种方法做。偏数学的。要考虑边界之类的。
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        lt=[]
        mark=0
        for i in range(1,int(target/2)+1):
            x=target
            init=i
            mark=0
            while(x>0):
                x-=init
                if(x==0):
                    mark=1
                    break
                init+=1
            if(mark==1):
                lt.append(list(range(i,init+1)))
        return lt

