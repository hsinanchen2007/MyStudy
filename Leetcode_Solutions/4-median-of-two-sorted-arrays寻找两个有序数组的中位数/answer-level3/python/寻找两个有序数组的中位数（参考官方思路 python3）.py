### 解题思路
本题有算法的时间复杂度要求O(log(m + n))，因此不能采用将两个数组先排序，再根据总的个数取中位数。
首先看见log复杂度，可以想到二分法。其次，根据中位数的关系，如果所有数字分为两个部分，那么两边个数相同，或者再多出来一个，结合除法计算特点，将这一个放到左边部分。那么只需要找出左边部分的最大值，和右边部分的最小值。然后根据总的个数为奇数，中位数即左边最大值，如果为偶数，则为左边最大值和右边最小值的平均值。

关于自己做这种题，在循环内部总是不能很好的运用判断条件。

思路：
1. 假设A数组是长度较短的数组，B为较长数组。
2. 在A中进行划分，有m+1种可能。一旦确定A的划分，那么B的划分根据两边个数相同，即能确定。
    i+j = m-i+n-j 或  i+j = m-i+n-j
    根据除法取模的特点，可以统一为：i+j=(m+n+1)//2
3. 采用二分法，设置i的区间为[imin,imax]的中间值，然后j也确定了。对这种划分进行判断：
     (1) 如果A[i-1]>B[j],说明A左部分太大了，则左移i，设置区间为[imin,i-1]
     (2) 如果A[i]<B[j-1],说明A左部分划分太小了，则右移i，设置区间为[i+1,imax]
     (3) 如果以上两种都不存在，那么符合条件了，此时的划分符合条件的，接下来就应该确定左大和右小了。
      ---------- (3.1) 先确定左大，有两种情况可以直接确定左大，当i=0，和j=0的时候，左边部分唯一确定。
                而另外的情况则一定是左边既有A又有B，所以取max(A[i-1],B[j-1])即可。
      ---------- (3.2) 如果总个数为奇数，直接确定中位数为左大
      ---------- (3.3) 还要确定右小，当这两种情况，右边部分唯一确定，j=n,i=m时，剩下的情况则右边一定有A有B
      ---------- (3.4) 总个数为偶数，取左大和右小计算平均值即可


### 代码

```python3
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        # 采用官方给出的解题思路进行解答
        # 首先设置A数组的长度小于B

        A = nums1
        B= nums2
        if len(nums1)>len(nums2):
            A,B = nums2,nums1
        m = len(A) # 表示较短的那个list的长度
        n = len(B) 

        # 设置二分法的区间范围，只看A划分，B的划分也能确定，然后通过A是否满足当前划分后的条件，移动区间范围
        IMIN = 0
        IMAX = m 
        halflen = (m+n+1)//2

        while(IMIN<=IMAX):
            i = (IMIN+IMAX)//2   # 用i来表示在A数组中切分的位置
            j = halflen - i 
            if i>IMIN and A[i-1]>B[j]:
                IMAX = i-1
            elif i<IMAX and A[i]<B[j-1]:
                IMIN = i+1
            else:
                # 当划分的位置正确之后，需要确定左边部分的最大值和最大部分的最小值，
                # 然后根据两个数组总个数的奇偶数来确定是左边的最大还是两者的平均值
                # 确定左边的最大值的时候，跟各种临界值有关
                if i==0: maxleft = B[j-1]
                elif j==0: maxleft = A[i-1]
                else: maxleft = max(A[i-1],B[j-1])
                print(maxleft)

                if (m+n)%2==1: 
                    middle_num = maxleft
                    return middle_num

                if i ==m: minright= B[j]
                elif j==n: minright = A[i]
                else: minright = min(A[i],B[j])
                middle_num = (maxleft+minright)/2

                return middle_num
        
        return 0



```