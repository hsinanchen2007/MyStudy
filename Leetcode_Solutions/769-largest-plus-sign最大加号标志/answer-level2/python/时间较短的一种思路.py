分别先生成两个矩阵，记录十字架行、列最长长度（其实就是离空点最近距离），然后取较小值就好，时间打败90%，就是内存耗得比较多。

class Solution(object):
    def orderOfLargestPlusSign(self, N, mines):
        """
        :type N: int
        :type mines: List[List[int]]
        :rtype: int
        """
        if len(mines)==0:
            if N%2==0:
                return N/2
            else:
                return N/2+1
        
        
        #row
        row_dic=collections.defaultdict(lambda :[])
        
        for ii in range(len(mines)):
            row_dic[mines[ii][0]].append(mines[ii][1])
        for ii in row_dic.keys():
            row_dic[ii]=sorted(row_dic[ii])
        
        row_matrix=[[0 for _ in range(N)] for _ in range(N)]
        
        if N%2==0:
            d=list(range(1,N/2+1))+list(range(N/2,0,-1))
        else:
            d=list(range(1,N/2+1))+[N/2+1]+list(range(N/2,0,-1))
            
        for ii in range(N):
            if len(row_dic[ii])==0:
                row_matrix[ii]=d
                continue
            v=row_dic[ii][0]
            for jj in range(v):
                row_matrix[ii][jj]=min([jj+1,v-jj])
            
            for jj in range(len(row_dic[ii])-1):
                v1=row_dic[ii][jj]
                v2=row_dic[ii][jj+1]
                for kk in range(v1+1,v2):
                    row_matrix[ii][kk]=min([kk-v1,v2-kk])
            
            v=row_dic[ii][-1]
            for jj in range(v+1,N):
                row_matrix[ii][jj]=min([jj-v,N-jj])
        
            
        #col
        col_dic=collections.defaultdict(lambda :[])
        
        for ii in range(len(mines)):
            col_dic[mines[ii][1]].append(mines[ii][0])
        for ii in col_dic.keys():
            col_dic[ii]=sorted(col_dic[ii])
        
        col_matrix=[[0 for _ in range(N)] for _ in range(N)]
        
        
        for ii in range(N):
            if len(col_dic[ii])==0:
                for jj in range(N):
                    col_matrix[jj][ii]=d[jj]
                continue
            v=col_dic[ii][0]
            for jj in range(v):
                col_matrix[jj][ii]=min([jj+1,v-jj])
            
            for jj in range(len(col_dic[ii])-1):
                v1=col_dic[ii][jj]
                v2=col_dic[ii][jj+1]
                for kk in range(v1+1,v2):
                    col_matrix[kk][ii]=min([kk-v1,v2-kk])
            
            v=col_dic[ii][-1]
            for jj in range(v+1,N):
                col_matrix[jj][ii]=min([jj-v,N-jj])
        
        #
        
        r=0
        for ii in range(N):
            for jj in range(N):
                t=min([row_matrix[ii][jj],col_matrix[ii][jj]])
                if t>r:
                    r=t
        return r
        
        
                
                
                
                
                
                
            
                                               