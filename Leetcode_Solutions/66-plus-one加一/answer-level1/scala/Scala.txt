object Solution {
    def plusOne(digits: Array[Int]): Array[Int] = {
var i = digits.length - 1
    while (i >= 0) {
      digits(i) += 1
      digits(i) %= 10
      if (digits(i) != 0)
        return digits
      i -= 1
    }
    val digit = new Array[Int](digits.length + 1)
    digit(0) = 1
    digit
    }
}