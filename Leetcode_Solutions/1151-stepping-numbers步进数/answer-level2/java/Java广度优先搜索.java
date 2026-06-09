暴力的思路是遍历，然后判断是否为步进数，会超时。

基本思路：一点一点生成步进数，改变已经生成的步进数的最后一位（+1或者-1），生成新的步进数、

```Java
    private Set<Integer> set = new TreeSet<>();
    
    public List<Integer> countSteppingNumbers(int low, int high) {
        for (int i = 0; i <= 9; i++) {
            bfs(low, high, i);
        }
        return new ArrayList<>(set);
    }

    private void bfs(int n,int m, long num) {
        // 注意此处使用Long，使用Integer会出现溢出
        Queue<Long> q = new LinkedList<> ();
        q.add(num);
        while (!q.isEmpty())
        {
            Long stepNum = q.poll();
            // 满足要求的步进数
            if (stepNum <= m && stepNum >= n)
            {
                set.add(Math.toIntExact(stepNum));
            }
            // 不满足要求的步进数
            if (stepNum == 0 || stepNum > m) continue;
            // 获取最后一位
            int lastDigit = (int) (stepNum % 10);
            // 最后一位+1或者-1
            Long stepNumA = stepNum * 10 + (lastDigit- 1);
            Long stepNumB = stepNum * 10 + (lastDigit + 1);
            // 最后一位等于0的时候，新的步进数最后一位只能是1
            if (lastDigit == 0) q.add(stepNumB);
            else if (lastDigit == 9) q.add(stepNumA);
            else {
                q.add(stepNumA);
                q.add(stepNumB);
            }
        }
    }
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/AlgoEx/tree/master/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！