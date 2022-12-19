  
```
    public List<Integer> countSteppingNumbers(int low, int high) {
        List<Integer> result = new ArrayList<>();
        if (low > high) {
            return result;
        }
        // 对0取对数无解，故单独处理
        if (low == 0) {
            result.add(0);
            low++;
        }
        // 用对数获取10进制的位数
        int lowLen = (int) Math.floor(Math.log10(low) + 1);
        int highLen = (int) Math.floor(Math.log10(high) + 1);

        for (int i = lowLen; i <= highLen; i++) {
            for (int j = 1; j < 10; j++) {
                countSteppingNumber(result, low, high, i, j);
            }
        }
        result.sort(Integer::compareTo);
        return result;
    }

    // 注意位数0和9，递归，长度为1时候结束
    // num要使用long，不然会溢出
    public void countSteppingNumber(List<Integer> res, int low, int high, int length, long num) {
        if (length - 1 == 0) {
            if (low <= num && num <= high) {
                res.add((int) num);
            }
            return;
        }
        int lastDigit = (int) (num % 10);
        if (lastDigit == 0) {
            countSteppingNumber(res, low, high, length - 1, num * 10 + 1);
        } else if (lastDigit == 9) {
            countSteppingNumber(res, low, high, length - 1, num * 10 + 8);
        } else {
            countSteppingNumber(res, low, high, length - 1, num * 10 + lastDigit + 1);
            countSteppingNumber(res, low, high, length - 1, num * 10 + lastDigit - 1);
        }
    }
```