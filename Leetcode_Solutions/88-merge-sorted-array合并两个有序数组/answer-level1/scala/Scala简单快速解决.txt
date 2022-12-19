执行用时 :488 ms, 在所有 Scala 提交中击败了100.00%的用户
内存消耗 :50.3 MB, 在所有 Scala 提交中击败了100.00%的用户

取nums1的前m个元素和num2的前n个元素合并再排序得到临时数组tmp，最后将tmp对应位置的值赋给num1就行，非常简洁高效

def merge(nums1: Array[Int], m: Int, nums2: Array[Int], n: Int): Unit = {
    val tmp = Array.concat(nums1.dropRight(nums1.length-m),nums2.dropRight(nums2.length-n)).sorted
    for(i <- tmp.indices){
      nums1(i) = tmp(i)
    }
  }