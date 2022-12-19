正常思路，从后往前循环，末位+1，然后判断是否大于9，如果大于9，说明有进位1，加个缓存，下次循环加上这个缓存就行了。
返回之前判断缓存是不是1，如果是1就返回长度+1的数组，否则返回原数组

```
fun plusOne(digits: IntArray): IntArray {
            if (digits[0] == 0) return intArrayOf(1)
            var d2 = IntArray(digits.size + 1)
            var i = digits.size - 1
            var temp = 0
            while (i >= 0){
                if (i ==digits.size - 1)
                    digits[i] = digits[i] + 1
                else
                    digits[i] = digits[i] + temp
                if (digits[i] > 9) {
                    temp = 1
                    digits[i] = digits[i] % 10
                }
                else
                    temp = 0
                d2[i + 1] = digits[i]
                i--
            }
            if (temp == 1) {
                d2[0] = 1
                return d2
            }else{
                return digits
            }
        }

```