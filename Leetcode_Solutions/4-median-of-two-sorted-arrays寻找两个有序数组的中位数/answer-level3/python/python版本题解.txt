#参考java代码，思想就是二分法递归两个数组较大的部分，并记录第k-1小与第k小的元素，最后再根据奇偶性，选择返回k还是两者一半。




    def findMedianSortedArrays(self, nums1, nums2):
        m = len(nums1)
        n = len(nums2)
        k = (m+n)/2
        st1 = 0
        st2 = 0
        res = self.doFind(nums1,st1,m,nums2,st2,n,k)
        if (m+n)%2==0:
            return 1.0*(res[0]+res[1])/2
        else:
            return res[1]
        
    def doFind(self,nums1,st1,m,nums2,st2,n,k):
        if m==0:
            return (nums2[st2+k-1],nums2[st2+k]) 
        if n==0:
            return (nums1[st1+k-1],nums1[st1+k])
        if k==1:
            left = nums1[st1]
            right = nums2[st2]
            if nums1[st1]<nums2[st2]:
                left = nums1[st1]
                if m>=2:
                    right = min(nums2[st2],nums1[st1+1])
                else:
                    right = nums2[st2]
            elif nums1[st1]>nums2[st2]:
                left = nums2[st2]
                if n>=2:
                    right = min(nums1[st1],nums2[st2+1])
                else:
                    right = nums1[st1]

            return (left,right)
        kk = k/2
        if kk<m:
            k1 = st1+kk-1
            x = kk
        else:
            k1 = st1+m-1
            x = m
        if kk<n:
            k2 = st2+kk-1
            y = kk
        else:
            k2 = st2+n-1
            y = n
        mid_a = nums1[k1]
        mid_b = nums2[k2]
        
        if mid_a>=mid_b:
            k = k-y
            st2 = k2+1
            n = max(n-kk,0)
        else:
            k = k-x
            st1 = k1+1
            m = max(m-kk,0)
        return self.doFind(nums1,st1,m,nums2,st2,n,k)
            
            
        
        
        