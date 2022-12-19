执行用时 : 2 ms, 在Pascal's Triangle II的Java提交中击败了73.43% 的用户
内存消耗 : 32.7 MB, 在Pascal's Triangle II的Java提交中击败了83.65% 的用户
```Java []
    public List<Integer> getRow(int rowIndex) {
        List<Integer> result = new ArrayList<>();
        if (rowIndex == 0) {
            result.add(1);
            return result;
        }
        if (rowIndex == 1) {
            result.add(1);
            result.add(1);
            return result;
        }

        result.add(1);
        result.add(1);

        for (int i = 1; i < rowIndex; i++) {
            result.add(1);
            for (int j = 0; j < i; j++) {
                result.add(result.get(0) + result.get(1));
                result.remove(0);
            }
            result.add(1);
            result.remove(0);
        }

        return result;


    }
```