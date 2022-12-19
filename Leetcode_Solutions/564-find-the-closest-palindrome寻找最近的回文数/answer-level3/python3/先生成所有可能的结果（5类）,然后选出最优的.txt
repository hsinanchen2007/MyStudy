![image.png](https://pic.leetcode-cn.com/845c4f7333a4de7a122898fe3c1acc9f8fabf42c98efa9b3af6d71f3db26a43d-image.png)

class Solution:
    def nearestPalindromic(self, n: str) -> str:
        if len(n) == 1:
            if n == "0":
                return "1"
            else:
                return str(int(n)-1)
        tmp = str(n)
        L = len(tmp)
        if L%2 == 0:
            new = []
            left = (tmp[0:L//2])
            #按照从小到大的顺序添加到new中，方便在有相同接近的时候，取最小值
            #长度为L-1的最大回文数
            tmp_a = ""
            for i in range(L-1):
                tmp_a += '9'
            new.append(tmp_a)
            #长度为L-1的最大回文数
            left_down = str(int(left) - 1)
            new.append(left_down + left_down[::-1])
            left = (tmp[0:L//2])
            new.append(left + left[::-1])
            left_up = str(int(left) + 1)
            new.append(left_up + left_up[::-1])
            #再添加两个比较特殊的，数的位数发生变化了
            #长度为L+1的最小回文数
            tmp_b = "1"
            for i in range(L-1):
                tmp_b += '0'
            tmp_b += '1'
            new.append(tmp_b)
            #长度为L+1的最小回文数
            #如果自身也是回文数，按照具体要求，应该去除
            if n in new:
                new.remove(n)
            error = [abs(int(a)-int(n)) for a in new]
            return new[error.index(min(error))]
        else:
            new = []
            left = (tmp[0:L//2+1])
            #长度为L-1的最大回文数
            tmp_a = ""
            for i in range(L-1):
                tmp_a += '9'
            new.append(tmp_a)
            #长度为L-1的最大回文数
            left_down = str(int(left) - 1)
            new.append(left_down + left_down[0:len(left_down)-1][::-1])
            left = (tmp[0:L//2+1])
            new.append(left + left[0:len(left)-1][::-1])
            left_up = str(int(left) + 1)
            new.append(left_up + left_up[0:len(left_up)-1][::-1])
            #长度为L+1的最小回文数
            tmp_b = "1"
            for i in range(L-1):
                tmp_b += '0'
            tmp_b += '1'
            new.append(tmp_b)
            #长度为L+1的最小回文数
            #如果自身也是回文数，按照具体要求，应该去除
            if n in new:
                new.remove(n)
            error = [abs(int(a)-int(n)) for a in new]
            return new[error.index(min(error))]
        return new

