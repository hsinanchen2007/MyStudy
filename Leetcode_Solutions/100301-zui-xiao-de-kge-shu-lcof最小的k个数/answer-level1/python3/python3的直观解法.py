class Solution:


    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:

        arr.sort()
        a=[]
        for i in range(k):
            a.append(arr[i])

        return a

因为python本身有排序函数，所以占了个便宜
![leetcode.png](https://pic.leetcode-cn.com/8ae07a1c95cd6c047ab2ace1e2e3066582c1dbd918cca1cc7364598f2d5d8ab9-leetcode.png)
