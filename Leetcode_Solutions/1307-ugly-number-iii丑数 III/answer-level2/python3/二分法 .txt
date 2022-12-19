class Solution:
    #最大公约数
    def gcp(self,a, b):
        tmp_a,tmp_b = min(a,b),max(a,b)
        while(tmp_b%tmp_a!=0):
            tmp_a,tmp_b=tmp_b%tmp_a,tmp_a
        return tmp_a
    #最小公倍数
    def gcp_max(self,a, b):
        tmp = a*b/self.gcp(a,b)
        return tmp
    #计算数[0,X]区间存在多少个丑数
    """
    1.该数只能被a整除 (该数一定是a 的整数倍)

    2.该数只能被b整除 (该数一定是b 的整数倍)

    3.该数只能被c整除 (该数一定是c 的整数倍)

    4.该数只能被a和b同时整除 (该数一定是a、b最小公倍数的整数倍)

    5.该数只能被a和c同时整除 (该数一定是a、c最小公倍数的整数倍)

    6.该数只能被b和c同时整除 (该数一定是b、c最小公倍数的整数倍)

    7.该数只能被a和b和c同时整除（该数一定是a、b、c的最小公倍数的整数倍）

    所以，我们只需要分别计算以上七项就能得到结果了！让我们分别来看（用MCM+下标表示最小公倍数）：

    情况1 = X/a - 情况4 - 情况5 - 情况7
    情况2 = X/b - 情况4 - 情况6 - 情况7
    情况3 = X/c - 情况5 - 情况6 - 情况7
    情况4 = X/MCM_a_b - 情况7
    情况5 = X/MCM_a_c - 情况7
    情况6 = X/MCM_b_c - 情况7
    情况7 = X/MCM_a_b_c

    让我们整理上述方程后也就得到：

    sum(情况) = X/a + X/b + X/c - X/MCM_a_b - X/MCM_a_c - X/MCM_b_c + X/MCM_a_b_c

    作者：Alfeim
    链接：https://leetcode-cn.com/problems/ugly-number-iii/solution/er-fen-fa-si-lu-pou-xi-by-alfeim/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    """
    def preprocess(self,a,b,c):
        #计算4类最小公倍数
        MCM_a_b = self.gcp_max(a,b)
        MCM_a_c = self.gcp_max(a,c)
        MCM_b_c = self.gcp_max(b,c)
        #a,b,c最小公倍数
        tmp_a_b = self.gcp(a,b)
        tmp_b_c = self.gcp(b,c)
        tmp_a_c = self.gcp(a,c)
        tmp_a_b_c = self.gcp(tmp_a_b,c)
        MCM_a_b_c = a*b*c/tmp_a_b/tmp_b_c/tmp_a_c*tmp_a_b_c
        return int(MCM_a_b),int(MCM_a_c),int(MCM_b_c),int(MCM_a_b_c)
    def getnum_X(self,X,a,b,c,MCM_a_b,MCM_a_c,MCM_b_c,MCM_a_b_c):
        return X//a + X//b + X//c - X//MCM_a_b - X//MCM_a_c - X//MCM_b_c + X//MCM_a_b_c
    def nthUglyNumber(self, n: int, a: int, b: int, c: int) -> int:
        MCM_a_b,MCM_a_c,MCM_b_c,MCM_a_b_c = self.preprocess(a,b,c)
        left = min(a,b,c)
        right = left*(n+1)
        while left < right:
            mid = (left + right) // 2
            num = self.getnum_X(mid,a,b,c,MCM_a_b,MCM_a_c,MCM_b_c,MCM_a_b_c)
            if num == n:
                return mid - min(mid%a,mid%b,mid%c)
                """
                注意，通过二分法计算的答案并非是最终答案，因为可以有很多数同时包含有n个丑数因子！

                比如第n个丑数是X，那么[X,X + min(a,b,c))这个半开区间内的所有数都同时包含n个丑数因子，我们通过二分法得到的答案也随机分布于这个                 区间中。而实际上我们只需要得到该区间的左端即可。处理方法很简单：假设我们得到的临时答案是K(K∈[X,X + min(a,b,c))),那么K -                     min(K%a,K%b,K%c) = X.也就是只需要把临时答案减去其与a、b、c三者中取余的最小值即可！

                作者：Alfeim
                链接：https://leetcode-cn.com/problems/ugly-number-iii/solution/er-fen-fa-si-lu-pou-xi-by-alfeim/
                来源：力扣（LeetCode）
                著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
                """
            elif num > n:
                right = mid
            else:
                left = mid
            