        // 逆序查找，分别从当前丑数的list中最大的开始计算，分别乘以2,3,5
        // 直到计算出下一个丑数比当前list中最后一个数小（分别走到list的i，j，k的位置）
        // 则停止此次查找，然后计算min（2*list（i+1）， 3*list(j+1)， 5*list（k+1））
        List<BigInteger> uglyList = new ArrayList<>();
        // 第一个丑数是1
        uglyList.add(BigInteger.ONE);
        for (int i = 1; i < n; i++) {
            int j = uglyList.size() - 1;
            int k = uglyList.size() - 1;
            int m = uglyList.size() - 1;
            BigInteger lastNumber = uglyList.get(uglyList.size() - 1);
            BigInteger two = BigInteger.ONE.add(BigInteger.ONE);
            BigInteger three = two.add(BigInteger.ONE);
            BigInteger five = three.add(two);
            // 需要考虑数据运算越界，在1407时已经越界
            while (j >= 0 && uglyList.get(j).multiply(two).compareTo(lastNumber) == 1) {
                j--;
            }
            while (k >= 0 && uglyList.get(k).multiply(three).compareTo(lastNumber) == 1) {
                k--;
            }
            while (m >= 0 && uglyList.get(m).multiply(five).compareTo(lastNumber) == 1) {
                m--;
            }
            BigInteger result;
            if (uglyList.get(j + 1).multiply(two).compareTo(uglyList.get(k + 1).multiply(three)) == 1) {
                if (uglyList.get(k + 1).multiply(three).compareTo(uglyList.get(m + 1).multiply(five)) == 1) {
                    result = uglyList.get(m + 1).multiply(five);
                } else {
                    result = uglyList.get(k + 1).multiply(three);
                }
            } else {
                if (uglyList.get(j + 1).multiply(two).compareTo(uglyList.get(m + 1).multiply(five)) == 1) {
                    result = uglyList.get(m + 1).multiply(five);
                } else {
                    result = uglyList.get(j + 1).multiply(two);
                }
            }

            uglyList.add(result);
        }
        return uglyList.get(uglyList.size() - 1).intValue();