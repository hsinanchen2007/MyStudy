```
/*
     * 题目：1291. 顺次数
     * 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
     * 内存消耗 :33.4 MB, 在所有 Java 提交中击败了100.00%的用户
     * */
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> resList = new LinkedList<Integer>();
        char[] lowArr = String.valueOf(low).toCharArray();
        int lowA = lowArr[0] - '0';
        final int len = lowArr.length;
        int minNum = lowA;
        int key = 1;
        boolean b = false;
        int pre = 12;
        int p = 2;
        for (int i = 1; i < len; i++) {
            lowA++;
            p++;
            key = key * 10 + 1;
            pre = pre * 10 + p;
            minNum = minNum * 10 + lowA;
            if (lowA > 9) {
                b = true;
            }
            if (p > 9) {
                return resList;
            }
        }
        if (!b) {
            if (minNum < low) {
                minNum += key;
                if (minNum%10 == 0){
                    minNum = pre;
                    p++;
                    pre = pre * 10 + p;
                    key = key * 10 + 1;
                }
            }
        } else {
            minNum = pre;
            key = key * 10 + 1;
        }
        while (minNum < high) {
            resList.add(minNum);
            minNum += key;
            if (minNum % 10 == 0) {
                p++;
                minNum = pre > minNum ? pre : pre * 10 + p;
                pre = pre * 10 + p;
                key = key * 10 + 1;
                if (minNum % 10 == 0) {
                    return resList;
                }
            }
        }
        return resList;
    }
```
