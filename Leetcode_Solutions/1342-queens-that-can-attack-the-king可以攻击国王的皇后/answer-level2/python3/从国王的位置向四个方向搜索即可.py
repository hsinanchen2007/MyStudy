```
class Solution:
    def queensAttacktheKing(self, queens: List[List[int]], king: List[int]) -> List[List[int]]:
        ans = []
        king_x = king[0]
        king_y = king[1]
        #横向、纵向搜索
        i = 1
        while king_x + i <=7:
            if [king_x+i,king_y] in queens:
                ans.append([king_x+i,king_y])
                break
            i += 1
        i = 1
        while king_x - i >= 0:
            if [king_x-i,king_y] in queens:
                ans.append([king_x-i,king_y])
                break
            i += 1
        i = 1
        while king_y + i <= 7:
            if [king_x,king_y+i] in queens:
                ans.append([king_x,king_y+i])
                break
            i += 1
        i = 1
        while king_y - i >=0:
            if [king_x,king_y - i] in queens:
                ans.append([king_x,king_y-i])
                break
            i += 1
        #对角线搜索
        i = 1
        j = 1
        while king_x+i <= 7 and king_y + j <= 7 :
            if [king_x+i,king_y +j] in queens:
                ans.append([king_x+i,king_y+j])
                break
            i += 1
            j += 1

        i = 1
        j = 1
        while king_x - i>=0 and king_y - j>=0:
            if [king_x-i,king_y - j] in queens:
                ans.append([king_x-i,king_y-j])
                break
            i += 1
            j += 1

        i = 1
        j = 1
        while king_x - i>=0 and king_y + j<=7:
            if [king_x-i,king_y + j] in queens:
                ans.append([king_x-i,king_y+j])
                break
            i += 1
            j += 1

        i = 1
        j = 1
        while king_x + i<=7 and king_y - j>=0:
            if [king_x+i,king_y - j] in queens:
                ans.append([king_x+i,king_y-j])
                break
            i += 1
            j += 1
        return ans
        




```
