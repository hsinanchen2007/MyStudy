### 解题思路
双指针的思想

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        # 可以分成相等的三个部分，那么sum(A)一定能被3整除
        # i，j停留到任意一个等于sum(A)/3的位置，
        # 挪动其余的指针
        # 越界条件是i==j，或者i+1==j
        # 停止条件是i的区域等于j的区域，此时判断中间区域是否相等
        if sum(A)%3!=0:
            return False
        i,j=0,len(A)-1
        left,right=A[i],A[j]
        tar=sum(A)//3
        while i < j :
            # 必须要走到两个都等于target才退出
            if right==tar and left==tar:
                break
            # 更新j
            while right!=tar and i<j:
                j-=1
                right+=A[j]
            # 更新i
            while left!=tar and i<j:
                i+=1
                left+=A[i]
        # 三种情况都返回false
        if i==j or i+1==j:
            return False
        # print(i,j,left,right,A[i+1:j])
        mid=sum(A[i+1:j])
        return True if left==mid and mid==right else False

```