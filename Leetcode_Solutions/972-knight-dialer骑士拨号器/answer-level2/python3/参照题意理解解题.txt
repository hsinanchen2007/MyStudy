```
class Solution:
    def knightDialer(self, N: int) -> int:
        nextnum=[[4,6],[8,6],[7,9],[4,8],[3,9,0],[],[1,7,0],[2,6],[1,3],[2,4]] 
        MOD=10**9+7
        dia=[1,1,1,1,1,1,1,1,1,1]
        if N==1:
            return (sum(dia))
        else:
            for i in range(N-1):
                # print('jump 1')
                diac=dia.copy()
                for j in range(len(dia)):
                    cnt=diac[j]
                    # print(j,'cnt',cnt)
                    for k in nextnum[j]:
                        dia[k]+=cnt
                for k in range(len(dia)):
                    dia[k]=dia[k]-diac[k]
                # print(dia)
            return (sum(dia)%MOD)
                
```

nextnum[i] 表示当前为i号键，如果进行一跳，可以到达的键位
    nextnum[0] 0->4 或0->6

dia 表示当前状态下，获得的所有拨号号码的尾数个数
dia[0]==1 表示末尾为0的号码有一个

每进行一跳，都先获取当前状态不同尾数对应的个数，然后找到下一条可到达的数字，更新尾数的个数

返回尾数个数求和取余