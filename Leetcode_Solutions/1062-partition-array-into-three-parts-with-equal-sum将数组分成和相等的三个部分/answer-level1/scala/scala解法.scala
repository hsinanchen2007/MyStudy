object Solution {
    def canThreePartsEqualSum(A: Array[Int]): Boolean = {
        var addUp = 0;
        //便利这个数组
        for (i <- 0 until A.length) {
            addUp += A(i);
            A(i) = addUp;
        }

        if (addUp % 3 != 0) {
            return false;
        }

        var middleValue = addUp / 3
        var left = 0;
        var middle = 0;

        //判断整个序列是否存在 递增
        for (i <- 0 until A.length - 1) {
            if (A(i) == middleValue) {
                left = 1
            } else if (left == 1 && (A(i) == middleValue * 2)) {
                middle = 1
            }
        }
        return left == 1 && middle == 1;
    }
}