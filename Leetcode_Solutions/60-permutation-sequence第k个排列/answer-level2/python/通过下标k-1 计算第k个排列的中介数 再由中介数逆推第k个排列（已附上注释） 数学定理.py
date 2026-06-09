```
class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        # k-1为第k个排列的下标
        # 通过下标找到中介数
        # 再找到第k个排列
        def getFactorial(n):
            if n==0 or n==1:
                return 1
            else:
                return n*getFactorial(n-1)
        # 8=1*3！+1*2！+0*1！
        m=k-1
        s=n-1
        res=[]
        # 找中介数
        while m!=0:
            b=getFactorial(s)
            # print(m,b)
            # 当前阶乘的系数是a
            a=m//b
            res.append(a)
            # m小于b a==0 继续下一轮操作
            if m<b:
                s-=1
            # m==b 给res后面补s-1个0 然后跳出循环
            elif m==b:
                for j in range(s-1):
                    res.append(0)
                break
            # m>b 继续下一轮循环
            else:
                m-=a*b
                s-=1

        # 通过中阶数 复原第k个排列
        r=[]
        # 当前使用过的数字
        tmp=[]
        # 遍历res 还原第k个排列前n-1位
        # 还原出现bug
        for i in range(len(res)):
            # print(r)
            # tmp空 随便用
            if len(tmp)==0:
                r.append(res[i]+1)
                tmp.append(res[i]+1)
            # tmp不空
            else:
                #不会写！！！
                count=0
                m=res[i]+1
                p=[]
                for j in range(len(tmp)):
                    if tmp[j]<=m:
                        count+=1
                        m+=1
                        continue
                    else:
                        # 暂存最后m可能大于的数字
                        p.append(tmp[j])
                # 对存放于p的数字进行判断 看m是否大于其中的某个元素
                # 对p排序 让暂存的元素从小到大排序
                p.sort()
                for g in range(len(p)):
                    # p[g]小于等于m 说明m原来是可以大于p[g]的
                    if p[g]<=m:
                        #再对m+1
                        m+=1
                # 此时的m便是需要的排列的某一位
                r.append(m)
                tmp.append(m)
                    
        s1=''
        # 加上最后一位
        for i in range(1,n+1):
            if i not in r:
                r.append(i)
        print(r)

        # 转换成字符串输出
        for i in r:
            s1+=str(i)
        return s1
```
