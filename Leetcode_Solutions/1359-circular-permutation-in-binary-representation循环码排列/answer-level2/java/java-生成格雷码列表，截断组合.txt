执行结果：
执行用时 :21 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :46.1 MB, 在所有 java 提交中击败了100.00%的用户

思路：
1.生成格雷码列表
2.截断列表，从start开始，生成结果

1)什么是格雷码
在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同，则称这种编码为格雷码（Gray Code）,
另外由于最大数与最小数之间也仅一位数不同，即“首尾相连”，因此又称循环码或反射码。

2) 如何求解格雷码
生成格雷码的方法: n+1位格雷码G(n+1)总数 等于 n位格雷码G(n)总数的2倍。只需将n位格雷码G(n)最高位添加0作为G(n+1)的前一半数据(符合格雷码要求)，然后G(n)逆序排,并在最高位加1,作为G(n+1)的后一半数据(也符合格雷码要求),即G(n)每一位加上1<<(n)。
两种方法：递归和循环。
循环方法更优, 计算G(n+1)时不需要多次复制G(n)。
```
    /**
     * 递归生成格雷码
     * @param n
     * @return
     */
    public static List<Integer> genGrayCode(int n) {
        if(n <= 0) {
            return Collections.emptyList();
        }
        if(n == 1) {
            return Lists.newArrayList(0,1);
        }
        List<Integer> pre = genGrayCode(n-1);
        int temp = pre.size();
        List<Integer> result = Lists.newArrayList();
        result.addAll(pre);
        for(int i=temp-1; i>=0; i--) {
            result.add(pre.get(i) + (1<<n-1));
        }
        return result;
    }


    /**
     * 循环生成格雷码
     * @param n
     * @return
     */
    public static List<Integer> genGrayCodeCircle(int n) {
        if(n <= 0) {
            return Collections.emptyList();
        }
        if(n == 1) {
            return Lists.newArrayList(0,1);
        }
        List<Integer> result = new ArrayList<>();
        result.add(0);
        result.add(1);
        for(int i=2; i<=n; i++) {
            int temp = result.size();
            for(int j=temp-1; j>=0; j--) {
                result.add(result.get(j) + (1<<(i-1)));
            }
        }
        return result;
    }
```
所以本题答案：
```
    public List<Integer> circularPermutation(int n, int start) {
        if(n <= 0 || start < 0 || start >=(int)Math.pow(2,n)) {
            return Collections.emptyList();
        }
        
        List<Integer> list = new ArrayList<>();
        if(n == 1) {
            list.add(start);
            list.add(1-start);
            return list;
        }
        //生成格雷码
        list.add(0);
        list.add(1);
        int index = start == 1 ? 1:0;
        for(int i=2; i<=n; i++) {
            int temp = list.size();
            for(int j=temp-1; j>=0; j--) {
                int value = list.get(j) + (1<<(i-1));
                list.add(value);
                if(value == start) {
                    index = list.size()-1;
                }
            }
        }
        //截断格雷码，重排序
        List<Integer> result = new ArrayList<>();
        result.addAll(list.subList(index, list.size()));
        result.addAll(list.subList(0, index));
        return result;
    }
```
