### 解题思路
此处撰写解题思路

### 代码

```python3
# method 1
# class Solution:
#     def countNegatives(self, grid: List[List[int]]) -> int:
#         res = 0
#         for row in grid:
#             for j in row:
#                 if j<0:
#                     res+=1
#         return res

# method 2 
# class Solution: 
#     def countNegatives(self, grid: List[List[int]]) -> int:
#         res = 0
#         for x in grid:
#             l,r,pos = 0,len(x)-1,-1
#             while l<=r:
#                 mid = l+(r-l)//2
#                 if x[mid]<0:
#                     pos = mid
#                     r=mid-1
#                 else: l=mid+1
#             if pos !=-1:
#                 res+=len(x)-pos
#         return res
        
#method 3
# class Solution:
#     def solve(self,l, r, L, R, grid):
#         if l>r: return 0
#         mid,pos=l+(r-l)//2, -1
#         for i in range(L,R+1):
#             if grid[mid][i]<0:
#                 pos=i
#                 break
#         ans = 0
#         if pos!=-1:
#             ans += len(grid[0])-pos
#             ans+=self.solve(l,mid-1,pos,R,grid)
#             ans+=self.solve(mid+1,r,L,pos,grid)
#         else:
#             ans+=self.solve(mid+1,r,L,R,grid)
#         return ans
#     def countNegatives(self, grid: List[List[int]]) -> int:
#         return self.solve(0,len(grid)-1,0,len(grid[0])-1,grid)

# method 4
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        num,m,pos=0,len(grid[0]),len(grid[0])-1
        for x in grid:
            i = -1
            for i in range(pos,-1,-1):
                if x[i]>=0:
                    if i+1<m:
                        pos=i+1
                        num+=m-pos
                    break
            if i==0 and x[0]<0:
                num+=m
        return num
        

```