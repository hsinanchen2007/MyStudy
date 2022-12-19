```kotlin
class Solution {
    fun climbStairs(n: Int): Int =
        (FIBONACCI_MATRIX pow n).a22

    data class TwoTimesTwoSymmetricMatrix(val a11: Int, val a12AndA21: Int, val a22: Int) {
        // 两个对称矩阵的乘积为对称矩阵当且仅当它们乘法可交换。
        infix fun timesCommutatively(other: TwoTimesTwoSymmetricMatrix): TwoTimesTwoSymmetricMatrix =
            TwoTimesTwoSymmetricMatrix(
                a11 * other.a11 + a12AndA21 * other.a12AndA21,
                a11 * other.a12AndA21 + a12AndA21 * other.a22,
                a12AndA21 * other.a12AndA21 + a22 * other.a22
            )

        infix fun pow(exponent: Int): TwoTimesTwoSymmetricMatrix =
            if (exponent == 1) this
            else pow(exponent / 2).let { it timesCommutatively it }.let { if (exponent % 2 == 0) it else it timesCommutatively this }
    }

    companion object {
        val FIBONACCI_MATRIX = TwoTimesTwoSymmetricMatrix(0, 1, 1)
    }
}
```