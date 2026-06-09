
'''
1.广搜：对当前位置四个方向进行判断，确定是否进行搜索；
2.分治法：若当前位置可访问，当前位置能访问的位置数即为当前位置四个方向可访问数 + 1（本身），如此递归；
搜索和判断过程中修改A, B值，其中A记录该位置是否合法，B记录该位置是否已访问；

'''
#%%
#import time
#%%
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        A = [[-1 for i in range(n)] for j in range(m)]
        B = [[0 for i in range(n)] for j in range(m)]
        counter = [0]
        def isAccessible(i, j):
            if A[i][j] == 1:
                return True
            elif A[i][j] == 0:
                return False
            else:
                bit_sum, i_t, j_t = 0, i, j
                while i_t > 0:
                    bit_sum += i_t % 10
                    i_t //= 10
                while j_t > 0:
                    bit_sum += j_t % 10
                    j_t //= 10
                if bit_sum <= k:
                    A[i][j] = 1
                    return True
                else:
                    A[i][j] = 0
                    return False
            pass
        def search(i, j):
            '''
            #分治法版本
            if i >=0 and j >= 0 and i < m and j < n and isAccessible(i, j) == True and B[i][j] == 0:
                B[i][j] = 1
                return search(i + 1, j) + search(i - 1, j) + search(i, j + 1) + search(i, j - 1) + 1
            else: 
                return 0
            ''' 
            #广搜版本
            #改变当前位置引起的相关参数变化
            counter [0] += 1
            B[i][j] = 1
            if i - 1 >= 0 and B[i - 1][j] == 0 and isAccessible(i - 1, j) == True:
                search(i - 1, j)
            if i + 1 < m and B[i + 1][j] == 0 and isAccessible(i + 1, j) == True:
                search(i + 1, j)
            if j - 1 >= 0 and B[i][j - 1] == 0 and isAccessible(i, j - 1) == True:
                search(i, j - 1)
            if j + 1 < n and B[i][j + 1] == 0 and isAccessible(i, j + 1) == True:
                search(i, j + 1)
            return 
        #s = time.time()
        #counter[0] = search(0, 0)
        search(0, 0)
        #print(time.time() - s)
        return counter[0]
        pass