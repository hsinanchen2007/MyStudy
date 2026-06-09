### 解题思路
此处撰写解题思路
// * 1.首先，让我们在任一位置 i 将 A(长度为m) 划分成两个部分：
// *            leftA            |                rightA
// *   A[0],A[1],...      A[i-1] |  A[i],A[i+1],...A[m - 1]
// *
// * 由于A有m个元素，所以有m + 1中划分方式(i = 0 ~ m)
// *
// * 我们知道len(leftA) = i, len(rightA) = m - i;
// * 注意：当i = 0时，leftA是空集，而当i = m时，rightA为空集。
// *
// * 2.采用同样的方式，将B也划分为两部分：
// *            leftB            |                rightB
// *   B[0],B[1],...      B[j-1] |   B[j],B[j+1],...B[n - 1]
// *  我们知道len(leftA) = j, len(rightA) = n - j;
// *
// *  将leftA和leftB放入一个集合，将rightA和rightB放入一个集合。再把这两个集合分别命名为leftPart和rightPart。
// *
// *            leftPart         |                rightPart
// *   A[0],A[1],...      A[i-1] |  A[i],A[i+1],...A[m - 1]
// *   B[0],B[1],...      B[j-1] |  B[j],B[j+1],...B[n - 1]
// *
// *   如果我们可以确认,只要满足下面两个条件，就可以获取中位数：
// *   1.len(leftPart) = len(rightPart); or len(leftPart) = len(rightPart) 
//       <==> i + j = m - i + n -j   or   i + j = m - i + n -j + 1
//       <== j = (m+n+1)/2 - i , 当n>=m,且i = 0 ~ m时。
//       解释：当m+n是偶数时，j = (m+n)/2 - i + 0.5 = (m+n)/2 - i (因为计算机执行的取整操作)
//            当m+n是奇数时，j = (m+n+1)/2 - i (本该如此)
##  计算机int相除向下取整: 最终两种情况都可以总结为 j = (m+n+1)/2 -i
// *   2.max(leftPart) <= min(rightPart); <== A[i-1]<=B[j] && B[j-1]<=A[i]
//       假设max(leftPart) = A[i-1], 则必须满足A[i-1]<=B[j]
//       假设max(leftPart) = B[j-1]，则必须满足B[j-1]<=A[i]
// *
// *   median = (max(leftPart) + min(rightPart)) / 2;  目标结果
// *
// *   按照以下步骤进行二叉树搜索
// *   1.设imin = 0,imax = m，然后开始在[imin,imax]中进行搜索
// *   2.令i = (imin+imax) / 2, j = (m+n+1)/2-i
// *   3.现在我们有len(leftPart) = len(rightPart)。而我们只会遇到三种情况：
// *
// *      ①.B[j] >= A[i-1] 并且 A[i] >= B[j-1]  满足条件
// *      ②.B[j-1] > A[i]。此时应该把i增大。 即imin = i + 1;
// *      ③.A[i-1] > B[j]。此时应该把i减小。 即imax = i - 1;
// *
### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    m := len(nums1)
    n := len(nums2)
    if m > n {
        t := nums1
        nums1 = nums2
        nums2 = t
        m = len(nums1)
        n = len(nums2)
    }
    iMin,iMax,halfLen := 0,m, (m+n+1)/2
    for iMin <= iMax {
        i := (iMax +iMin)/2
        j := halfLen - i
        if i < iMax && nums2[j-1] > nums1[i] {
            iMin = i + 1
        }else if i > iMin && nums2[j] < nums1[i-1] {
            iMax = i -1
        } else {
            maxLeft := 0
            if i == 0 {
                maxLeft = nums2[j-1]
            }else if j ==0 {
                maxLeft = nums1[i-1]
            }else {
                maxLeft = max(nums2[j-1],nums1[i-1])
            }
            if (m + n) % 2 == 1 { //奇数，中位数正好是maxLeft
                    return float64(maxLeft)
            }
            minRight := 0
            if i == m {
                minRight = nums2[j]
            }else if j==n {
                minRight = nums1[i]
            }else {
                minRight = min(nums1[i],nums2[j])
            }
            return float64(minRight +maxLeft)/2.0

        }

    }
    return 0.0
}
func min (a,b int)int{
    if a > b {
        return b
    }
    return a
}
func max (a,b int)int{
    if a > b {
        return a
    }
    return b
}
```