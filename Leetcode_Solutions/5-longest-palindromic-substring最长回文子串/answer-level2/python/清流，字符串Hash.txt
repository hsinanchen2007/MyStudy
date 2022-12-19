来一个清流题解（一样的解法发那么多真的没意思）
字符串Hash
即将字符串认为是个多进制数，不妨认为是K
那么一段字符串就可以换算成一个数了
然后问题就变成怎么O(1)求出一段字符串对应的数了
很简单，就是前缀和+逆元
也就是说先预处理出前缀和A[] (反过来就是后缀和)
那么A[L..R] = (A[R] - A[L-1]) / K^L
虽然说python自带高精度，但数太大会超时，所以就采用模意义下的值
模意义下需要涉及到求逆元，直接用费马小定理a^(p-1) = 1 (mod p), a^(p-2) = p^-1 (mod p)
由于取模速度很慢，所以跑出来速度差了不少，但这个方法可以扩展的地方很多


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        if (len(s) == 0):
            return s
        self.init(length)
        A = [0] * length
        B = [0] * length
        A[0] = ord(s[0])-97
        B[length-1] = ord(s[length-1])-97
        # 前缀和与后缀和
        for i in range(1, length):
            A[i] = (A[i-1] + (ord(s[i])-97) * self.a[i]) % self.Mod
        for i in range(length-2, -1,-1):
            B[i] = (B[i+1] + (ord(s[i])-97) * self.a[length-i-1]) % self.Mod
        for i in range(length-1, -1, -1):
            for j in range(0, length-i):
                L, R = j, j+i
                # 分别利用前后缀和求两个方向字符串hash
                if (L != 0):
                    l = (A[R]-A[L-1]+self.Mod) * self.b[L] % self.Mod
                else:
                    l = A[R]
                if (R != length-1):
                    r = (B[L]-B[R+1]+self.Mod) * self.b[length-1-R] % self.Mod
                else:
                    r = B[L]
                
                if (l == r):
                    # （PS：由于hash存在可hack性，倒数第二个样例就被卡了，所以加了一个特判）
                    flag = 1
                    for k in range(R-L+1):
                        if (s[L+k] != s[R-k]):
                            flag = 0
                            break
                    if (flag == 1):
                        return s[L:R+1]
    # 快速幂求费马小
    def pow(self, a, b, c):
        ans = 1
        
        while (b > 0):
            if (b & 1):
                ans = (ans * a) % c;
            a = (a * a) % c
            b = b >> 1
        
        return ans
    
    def init(self, Length):
        self.Mul = 29
        self.Mod = int(10e7+7)
        # 逆元，参考前文费马小定理
        self.inverse_Mul = pow(self.Mul, self.Mod-2, self.Mod)
        # 正向乘积
        self.a = [1]
        for i in range(Length):
            self.a.append(self.a[-1] * self.Mul)
            if (self.a[-1] >= self.Mod):
                self.a[-1] %= self.Mod
        # 逆向乘积
        self.b = [1]
        for i in range(Length):
            self.b.append(self.b[-1] * self.inverse_Mul)
            if (self.b[-1] >= self.Mod):
                self.b[-1] %= self.Mod