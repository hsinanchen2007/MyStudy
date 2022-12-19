这个代码是我根据306一位大佬的题解改编的，那个题目正好用来解决这一题，只要注意几个地方就行了。
由于是判断能否拆成斐波那契数列,所以只要有一个结果就返回。
还有就是中间判断的时候题目说了只有数组的值不会超过Integer.MaxValue,所以我们遍历的时候最大遍历
10位数字就行了。还有就是将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
代码如下:
```
public List<Integer> splitIntoFibonacci(String S) {

        //字符串长度小于3直接返回
        if (S.length() < 3) return new ArrayList<>();
        int n = S.length();
        //第一个数字的长度不超过数组的一半和10两者的最小值
        for (int i = 1; i <= Math.min((n - 1) / 2, 10); i++) {
            //遇到00112这种
            if (i > 1 && S.charAt(0) == '0') {
                break;
            }
            //斐波那契数列中第一个数字的长度和第二个数字的长度都小于等于第三个数字的长度
            for (int j = i + 1; n - j >= i && n - j >= j - i; j++) {
                //遇到199001200这种
                if (S.charAt(i) == '0' && j - i > 1) {
                    break;
                }
                Long num1 = Long.valueOf(S.substring(0, i));
                Long num2 = Long.valueOf(S.substring(i, j));
                //大于int型最大值直接跳过
                if (num1 > Integer.MAX_VALUE || num2 > Integer.MAX_VALUE) {
                    break;
                }
                //用中间数组来保存中间值
                List<Integer> tempList = new ArrayList<>();
                tempList.add(Math.toIntExact(num1));
                tempList.add(Math.toIntExact(num2));
                if (canSplitIntoFibonacci(tempList, S.substring(j), Math.toIntExact(num1), Math.toIntExact(num2))) {
                    return tempList;
                }
            }
        }
        return new ArrayList<>();
    }

    private boolean canSplitIntoFibonacci(List<Integer> tempList, String str, Integer num1, Integer num2) {
        if (str.equals("")) {
            return true;
        }
        Integer sum = num1 + num2;
        String next = String.valueOf(sum);
        //剩下的部分一定要包含前两个数的结果
        if (!str.startsWith(next)) {
            return false;
        }
        tempList.add(sum);
        //将第二个数作为第一个数,结果作为第二个数,继续回溯
        return canSplitIntoFibonacci(tempList, str.substring(next.length()), num2, Integer.valueOf(sum));
    }
```
