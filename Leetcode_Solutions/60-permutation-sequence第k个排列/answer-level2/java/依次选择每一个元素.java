```   
    import java.util.TreeSet;
    /**
    * 假如n=4、k=7,那么可以形成的排列为1***、2***、3***、4***，且1*** < 2*** < 3*** < 4***.
    * 再观察1***中的排列包含12**,13**,14**且12** < 13** < 14**...
    * 所以我们可以逐个选择元素，选择第一个元素时，因为总共可以排列出4*3*2*1=24中结果
    * 且以1***, 2***, 3***, 4***可以排列出3*2*1=6种结果。计算7/6=1 且 7%6=1,故我们应该选择以2***开头
    * 的元素，依次类推，可以计算得n=4,k=7时结果为2134
    */
    class Solution {
        public String getPermutation(int n, int k) {
            if (n <= 0 || k <= 0 || k > computePermutationNum(n)) {
                return null;
            }

            // 使用TreeSet存储1~n的元素，保证元素始终有序
            TreeSet<Integer> set = new TreeSet<>();
            for (int i = 1; i <= n; i++) {
                set.add(i);
            }

            //
            StringBuilder resBuilder = new StringBuilder();
            int permutationNum;
            while(k != 0 && (permutationNum = computePermutationNum(set.size() - 1)) != 0) {
                /**
                * 确定当前该选什么元素，通过确定k与剩余元素所能组成的排列总数进行比较
                */
                int quotient = k / permutationNum;
                int remainder = k % permutationNum;
                Integer choosedNum;
                if (remainder == 0) {
                    // 余数为0，应该选择quotient-1行
                    choosedNum = getNumberInTreeSet(set, quotient - 1);
                    k = k - (quotient - 1) * permutationNum;
                } else {
                    choosedNum = getNumberInTreeSet(set, quotient);
                    k = k - quotient * permutationNum;
                }

                resBuilder.append(choosedNum);
                set.remove(choosedNum);
            }
            resBuilder.append(set.last());
            return resBuilder.toString();
        }

        /**
        * 计算n个元素的排列总和
        */
        private int computePermutationNum(int n) {
            if (n == 0)
                return 0;

            int res = 1;
            for (int i = 2; i <= n; i++) {
                res *= i;
            }
            return res;
        }

        /**
        * 获取TreeSet中第i个元素，TreeSet没有提供获取第i个元素的接口
        */
        private Integer getNumberInTreeSet(TreeSet<Integer> set, int i) {
            int j = 0;
            for (Integer ele : set) {
                if (j == i) {
                    return ele;
                }
                j++;
            }
            return null;
        }

        public static void main(String[] args) {
            String res = new Solution().getPermutation(3, 2);
            System.out.println(res);
        }
}
```