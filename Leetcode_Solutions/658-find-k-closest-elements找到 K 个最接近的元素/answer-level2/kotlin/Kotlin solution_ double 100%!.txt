执行用时 :492 ms, 在所有 Kotlin 提交中击败了100.00%的用户
内存消耗 :39.4 MB, 在所有 Kotlin 提交中击败了100.00%的用户


```
    fun findClosestElements(arr: IntArray, k: Int, x: Int): List<Int> {
        val res = ArrayList<Int>(k)
        if (x < arr.first()) {
            for (i in 0 until k) {
                res.add(arr[i])
            }
        } else if (x > arr.last()) {
            for (i in arr.size - k until arr.size) {
                res.add(arr[i])
            }
        } else {
            var low = 0
            var high = arr.size - 1
            var mid = 0
            while (low < high) {
                mid = low + (high - low) / 2
                if (arr[mid] < x) {
                    low = mid + 1
                } else {
                    high = mid
                }
            }
            if (arr[low] == x) {
                res.add(arr[low])
                high = low + 1
                low--
                var newK = k - 1
                while (newK > 0) {
                    if (low > -1 && high < arr.size) {
                        if (Math.abs(arr[low] - x) <= Math.abs(arr[high] - x)) {
                            res.add(0, arr[low])
                            low--
                        } else {
                            res.add(arr[high])
                            high++
                        }
                    } else if (low > -1) {
                        res.add(0, arr[low])
                        low--
                    } else if (high < arr.size) {
                        res.add(arr[high])
                        high++
                    }
                    newK--
                }
            } else {
                high = low
                low--
                var newK = k
                while (newK > 0) {
                    if (low > -1 && high < arr.size) {
                        if (Math.abs(arr[low] - x) <= Math.abs(arr[high] - x)) {
                            res.add(0, arr[low])
                            low--
                        } else {
                            res.add(arr[high])
                            high++
                        }
                    } else if (low > -1) {
                        res.add(0, arr[low])
                        low--
                    } else if (high < arr.size) {
                        res.add(arr[high])
                        high++
                    }
                    newK--
                }
            }
        }
        return res
    }
```
