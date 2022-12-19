```
public static String getPermutation(int n, int k) {
        StringBuilder ans = new StringBuilder();
        //下面求阶乘时默认n至少为2
        if(n == 1)
            return ans.append((char)(1+'0')).toString();
        //第一步，求1~n-1的阶乘
        int [] factorial = new int[n];
        factorial[1] = 1;
        for (int i = 2; i < n; i++) {
            factorial[i] = i * factorial[i-1];
        }
        //此处为了方便索引，故创建n+1的used数组
        boolean[] used = new boolean[n + 1];
        //求前n-1个数的排列
        int i = 0;
        while (i < n - 1){
            //模拟直接取数的思路
            int index = (k-1)/factorial[n-i-1] + 1;
            k = k - (index - 1) * factorial[n-i-1];
            //选择数字
            int num = 1;
            //选取第index个未使用的数
            while (num < index || used[num]) {
                if (used[num]){
                    index++;
                }
                num ++;
            }
            ans.append((char) (num + '0'));
            used[num] = true;
            i++;
        }
        //求最后一个数的索引
        int index = 1;
        while (used[index]) index++;
        ans.append(index);
        return ans.toString();
    }
```
