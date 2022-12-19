1,最直观,最初级的解法,合并到一个数组
```
object Solution {
  def findMedianSortedArrays(nums1: Array[Int], nums2: Array[Int]): Double = {
    var num: Array[Int] = null
    var d = 0.0
    if (nums1 == null) {
      num = nums2
    } else if (nums2 == null) {
      num = nums1
    }
    if (num != null) {
      val len = num.length
      val a = len / 2
      val b = (len - 1) / 2
      val sum = num(a) + num(b)
      d = sum / 2.0
    } else {
      val len = nums1.length + nums2.length
      val a = len / 2
      val b = (len - 1) / 2
      val c = new scala.collection.mutable.ArrayBuffer[Int]()
      nums1.copyToBuffer(c)
      nums2.copyToBuffer(c)
      val cc=c.toArray
      scala.util.Sorting.quickSort(cc)
      val sum = cc(a) + cc(b)
      d = sum / 2.0
    }
    d
  }
}


```
2,高级一点的解法,其实就是求解第k大元素的变形
```

object Solution {
  def findMedianSortedArrays(nums1: Array[Int], nums2: Array[Int]): Double = {
    var len = 0
    var k1 = 0
    var k2 = 0
    if(nums1.length==0){
      len=nums2.length
      k1 = (len+1)/2
      k2 = (len+2)/2
      return (nums2(k1-1)+nums2(k2-1))/2.0
    }
    if(nums2.length==0){
      len=nums1.length
      k1 = (len+1)/2
      k2 = (len+2)/2
      return (nums1(k1-1)+nums1(k2-1))/2.0
    }

   len = nums1.length+nums2.length
     k1 = (len+1)/2
     k2 = (len+2)/2
    val m1=findk(nums1,nums2,k1)
    val m2=findk(nums1,nums2,k2)
    return (m1+m2)/2.0
  }
  def findk(nums1: Array[Int], nums2: Array[Int], k: Int): Int = {

    //前k个元素都在nums1上
    if (nums1.length >= k && nums1(k - 1) <= nums2(0)) {
      return nums1(k - 1)
    }

    //前k个元素都在nums2上
    if (nums2.length >= k && nums2(k - 1) <= nums1(0)) {
      return nums2(k - 1)
    }

    //前k个元素，nums1和nums2上都有
    var start = 0
    var end = nums1.length - 1
    var k1 = 0
    var k2 = 0
    while (start <= end) {
      k1 = start + (end - start) / 2
      if (k1 + 1 >= k) {
        //nums1元素太多
        end = k1-1
      } else if (k1 + 1 + nums2.length < k) {
        //nums1元素太少
        start = k1+1
      } else {
        k2 = k - 1 - k1 - 1
        var flag1 = false
        var flag2 = false
        if (k2 + 1 >= nums2.length || k2 + 1 < nums2.length && nums1(k1) <= nums2(k2 + 1)) {
          flag1 = true
        }
        if (k1 + 1 >= nums1.length || k1 + 1 < nums1.length && nums2(k2) <= nums1(k1 + 1)) {
          flag2 = true
        }
        if (flag1 && flag2) {
          return nums1(k1).max(nums2(k2))
        }
        if (flag1) {
          start = k1+1
        }
        if (flag2) {
          end = k1-1
        }

      }

    }
    1
  }


}

```
