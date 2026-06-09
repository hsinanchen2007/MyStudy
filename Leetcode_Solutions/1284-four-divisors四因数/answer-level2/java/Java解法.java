主要是注意完全平方数肯定不能分解成4个因子的，比如16这个数字，这个判断不能放在获取因子的循环里，而是在求和的地方，我也是在这里卡住了10几分钟
```
public int sumFourDivisors(int[] nums) {
        int sum=0;
        for (int i=0;i<nums.length;i++) {
            int cnt=1;
            List<Integer> list= new ArrayList<>();
            int s=(int)Math.sqrt(nums[i]);
            for (int j=2;j<=s;j++) {
                if (nums[i]%j==0) {
                    cnt++;
                    list.add(j);
                }
            }
            //完全平方数肯定不符合条件的，比赛的时候确实没考虑全面
            if (cnt==2&&s*s!=nums[i]) {
                sum+=(nums[i]+1);
                for (int n:list) {
                    sum+=(n+nums[i]/n);                    
                }
            }
        }
        return sum;
    }
```
