直接上代码，带备忘录方法和动态规范的参考其他大神。
第一个数字可以加，也可以减，所以直接new一个数组，从0开始，对后面的数字进行加减。

public int findTargetSumWays(int[] nums, int S) {
        int[] numsS = new int[nums.length + 1];
        numsS[0] = 0;
        for (int i = 0; i < nums.length; i++) {
            numsS[i + 1] = nums[i];
        }
        List<String> count = new ArrayList<>();
        dfs(numsS, 0, S, 0, count, true);
        return count.size();
    }

    public int dfs(int[] numsS, int sum, int S, int i, List count , boolean add){
        if(i >= numsS.length){
            return 0;
        }
        if(add){
            sum += numsS[i];
        }else {
            sum -= numsS[i];
        }
        dfs(numsS, sum, S, i + 1, count, true);
        dfs(numsS, sum, S, i + 1, count, false);
        if(i == numsS.length - 1 && sum == S){
            count.add("1");
        }
        return sum;
    }