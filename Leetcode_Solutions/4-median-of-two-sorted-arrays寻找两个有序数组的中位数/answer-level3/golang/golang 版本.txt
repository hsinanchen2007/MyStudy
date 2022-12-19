此题关键在于通过时间复杂度Log(M+N)的限制想到二分法求解,但二分两个数组是不可能的因此想到通过发现某种关系将两个二分转换为一个数组的二分。
`j = (M+N+1)/2`  至于为啥,可以看官方题解,将两个数组转换为一个数组去思考,本质上是一种线性代数的思想,既然在一维上有序数组左小于右的中点处是中位数,那么只要在二维的空间上也满足这个规律不也就找到中位数了吗？基于此,想到了二分的策略,然后跟所有二分法一样要靠仔细考察边界情况。
事实上所有的二分问题,都要考虑的是:`在什么上进行二分?`,`二分的策略是什么?`,`边界条件有哪些?`
对于此题,在两个数组上通过一个数学关系进行二分,对于两个数组皆满足左小于右处即是中位点,边界条件就是划分时若其中一个点在数组边缘的情况。
那么回答这三个问题的处理方法即可形成此题的解,算法如下:


``` 
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    m,n := len(nums1),len(nums2)
    if m>n{
        return findMedianSortedArrays(nums2,nums1)
    }
    iMin ,iMax,laftLen := 0,m,(n+m+1)/2
    for iMin <= iMax{
        i := iMin + (iMax-iMin)/2
        j := laftLen - i
        if i > iMin && nums1[i-1] > nums2[j]{
            iMax = i - 1
        }else if i < iMax && nums2[j-1] > nums1[i]{
            iMin = i + 1
        }else{
            leftMax := 0
            if i == 0{
                leftMax = nums2[j-1]
            }else if j == 0{
                leftMax = nums1[i-1]
            }else{
                leftMax = max(nums1[i-1],nums2[j-1])
            }
            if (m+n)%2 != 0{
                return float64(leftMax)
            }
            rightMin := 0
            if i == m {
                rightMin = nums2[j]
            }else if j == n{
                rightMin = nums1[i]
            }else{
                rightMin = min(nums1[i],nums2[j])
            }
            return float64(leftMax+rightMin)/2.0
        }
    }
  return 0.0
}
func max(a,b int)int{
    if a > b{
        return a
    }else{
        return b
    }
}

func min(a,b int )int{
    if a > b{
        return b
    }else{
        return a
    }
}

```