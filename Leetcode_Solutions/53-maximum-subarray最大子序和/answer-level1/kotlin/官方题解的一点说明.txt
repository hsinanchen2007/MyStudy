/**
 * 这里把sum当作当前数字前面的所有数字组合成的一个数就好了，比如：
 * 2，3，4，-6，1
 * 走到-6 以后，sum等与2+3+4 = 9，这个时候  可以把列表看作9，-6，1来看
 * 只有合成的这个数字(在这里就是9)大于0的时候才会增大sum，
 * 小于0的时候直接扔掉将-6当作sum值从头开始，这也是为什么answer一开始
 * 等于array[0]的原因。
 */
```
fun maximumSubArray(array: IntArray): Int {
    var answer = array[0]
    var sum = 0
    for (i in array) {
        if (sum > 0) {
            sum += i
        } else {
            sum = i
        }
        answer = max(answer, sum)
    }
    return answer
}
```