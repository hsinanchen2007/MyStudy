    public int numberOfSteps (int num) {
        int step = 0;
        while (num != 1) {
            if ((num & 1) == 0) {
                step++;
            } else {
                step += 2;
            }
            num = num >> 1;
        }
        return step + 1;
    }
 

奇数除以2相当于执行了两步，偶数除以2执行了一步
最后补一个1是因为计算到1需要走多少步，最后还需要执行一次(1-1)才等于0