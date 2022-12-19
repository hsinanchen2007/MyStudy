 
 执行用时 :420 ms, 在所有 Swift 提交中击败了100.00%的用户内存消耗 :21.4 MB, 在所有 Swift 提交中击败了100.00%的用户
优化效率要区分数组数量远大于k和跟k差不多的情况
 **大于k一定程度要先二分找到最接近x的数字然后取左右包含该数字的各k个数缩小比较到剩下k个数
 如果没有大于k一定的程度则二分查找消耗的时间比节省的时间要多可以直接从最左最右向下缩小到只剩下k个数**

通过数组长度和k可以判断是否需要二分
二分查找然后从中间取的总运算量是 log2n + k - 1 
不二分直接从两边向内查找的总运算量是 n - k 
题目给出了最大值小于10^4 也就是log2n < 15 
二者比较后决定是不是要做二分就行了
 ```
class Solution {
    func findClosestElements(_ arr: [Int], _ k: Int, _ x: Int) -> [Int] {
        var result = [Int]()
        var start = 0
        var end = arr.count - 1 

        if(arr.count - k + 1 > 15 + k - 1){

            var mid = (end - start) / 2 + start
            if mid > 1{
            while arr[mid - 1] == arr[mid]{
                 mid = mid - 1
            }
            }
         
             while end - start > 2 {
                 if arr[mid] > x {
                    end = mid
                }else{
                   start = mid
                  }
             mid = (end - start) / 2 + start
             }
            start = mid - k - 1 
            end = mid + k - 1
              if start < 0 {start = 0}
              if end > arr.count - 1 {end = arr.count - 1}
          }      
  

   

        while end - start > k - 1{
            
            if abs(arr[end] - x) < abs(arr[start] - x) {
                start += 1
            }else{
                 end -= 1
            }
         }
        var j = start
        while j <= end {
            result.append(arr[j])
            j += 1
         }
    
        return result

    }
}
```
