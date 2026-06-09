添加一个字典记录合并为1堆的结果，可以节省大量计算时间（时间击败70%）
class Solution(object):
    def mergeStones(self, stones, K):
        """
        :type stones: List[int]
        :type K: int
        :rtype: int
        """
        if len(stones)==1:
            return 0
        if (len(stones)-1)%(K-1)!=0:
            return -1
    
        
        cumsum=[0 for _ in range(len(stones)+1)]
        cumsum[1]=stones[0]
        for ii in range(1,len(stones)):
            cumsum[ii+1]=cumsum[ii]+stones[ii]
        
        inf=cumsum[-1]*len(stones)
        
        dic=collections.defaultdict(lambda :collections.defaultdict(lambda :None))
        
        def f(ii,jj,k):
            if (jj-ii+1)==k:
                return 0
            if jj<=ii:
                return inf
            if (jj-ii+1)%(K-1)!=(k%(K-1)):
                return inf    
            if k==1:
                if dic[ii][jj]==None:
                    dic[ii][jj]=f(ii,jj,K)+cumsum[jj+1]-cumsum[ii]
                return dic[ii][jj] 
            minv=inf
            for dd in range(1,jj-ii+1,K-1):
                temp=f(ii,ii+dd-1,1)
                if temp>=minv:
                    continue
                temp+=f(ii+dd,jj,k-1)
                if temp<minv:
                    minv=temp
            return minv
        return f(0,len(stones)-1,1)
            
        
            
            
            
            
                
        