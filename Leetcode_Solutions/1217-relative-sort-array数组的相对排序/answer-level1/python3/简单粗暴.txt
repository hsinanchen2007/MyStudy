![4Q(EU\])QL}C_RUVY}H5UF@J.png](https://pic.leetcode-cn.com/ec9594370be87ee1c3087645dc03b0b2f700a33178c771886f307267d22acfcc-4Q\(EU%5D\)QL%7DC_RUVY%7DH5UF@J.png)

class Solution(object):
    def relativeSortArray(self, arr1, arr2):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :rtype: List[int]
        """
        res = []
        for i in arr2:
            while i in arr1:
                res.append(i)
                arr1.remove(i)
        return res + sorted(arr1)