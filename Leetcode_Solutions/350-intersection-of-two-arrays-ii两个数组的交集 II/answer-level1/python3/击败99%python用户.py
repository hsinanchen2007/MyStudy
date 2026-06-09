class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        hash1={}
        hash2={}
        list=[]
        for i in nums1:
            if i in hash1:
                hash1[i]+=1
            else:
                hash1[i]=1
        for j in nums2:
            if j in hash1:
                if j in hash2:
                    hash2[j]+=1
                else:
                    hash2[j]=1

        for k in hash2:
            m=min(hash1[k],hash2[k])
            for _ in range(m):
                list.append(k)

        return list