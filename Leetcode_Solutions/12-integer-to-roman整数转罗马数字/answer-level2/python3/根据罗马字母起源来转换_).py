# ### 解题思路
# 罗马字母的4eN、5eN和9eN的出现肯定在简单的1eN之后，所以先找出多少个1eN，然后在I、X、C、M中总结出剩下的字母
# 在1-9999之间，罗马字母只有['I', 'V', 'X', 'L', 'C', 'D', 'M']，4eN和9eN都和自己的取值范围有关，并且一个范围，例如100-999之间，如果有一个900就不可能有400和500，反之亦然，所以每次只需要在1eN的个数中排出9、5或者4，最后循环三次把各个罗马字母接到一起

# 但这个算法并不优秀😅，大佬们太强了
# 如果还可以改进尽情留言😆

# ### 代码

# ```python3
class Solution:
    def intToRoman(self, num: int) -> str:
        # M -> 1000
        # CM -> 900 * 1 // D -> 500 * 1 // CD -> 400 * 1 // C -> 100 * 3
        # XC->90 * 1 // L -> 50 * 1 // XL -> 40 * 1 // X -> 10 * 3
        # IX -> 9 * 1 // V -> 5 * 1 // IV -> 4 * 1 // I -> 1 * 3
        roma = ['M', 'D', 'C', 'L', 'X', 'V', 'I']
        arab = [1000, 500, 100, 50, 10, 5, 1]
        res = [[], [0, 0, 0], [0, 0, 0], [0, 0, 0]]
        for i in range(4):
            res[0].append(num//arab[2*i])
            num -= num//arab[2*i] * arab[2*i]
        #[m, n, i, j] -> [1000, 100, 10, 1]
        for i in range(3):
            if res[0][i+1]==9:
                res[1][i] = 1
                res[0][i+1] -= 9
            elif res[0][i+1]>=5:
                res[2][i] = 1
                res[0][i+1] -= 5
            elif res[0][i+1]==4:
                res[3][i] = 1
                res[0][i+1] -= 4
        #[[m, n, i, j], [m, n, k], [m, n, k], [m, n, k]] -> [100, 10, 1] : [900, 500, 400]
        real_res = 'M' * res[0][0]
        for i in range(3):
            buf = (i+1)*2
            real_res += res[1][i] * (roma[buf]+roma[buf-2]) + res[2][i] * roma[buf-1] + res[3][i] * (roma[buf]+roma[buf-1]) + res[0][i+1] * roma[buf]
        return real_res