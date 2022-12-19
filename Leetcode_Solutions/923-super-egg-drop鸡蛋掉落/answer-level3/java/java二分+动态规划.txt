```
    public int eggDrop(int K, int N, int[][] memory) {
        /*这种方法可能会超时，所以我们要有一个二维数组记录所有结果防止重复计算*/
        if(memory[K-1][N-1] != 0) return memory[K-1][N-1];
        if(N <= 2 || K == 1) return N;
        int left=1,right=0,bias=0;

        /**
         * 如果我们在二分处扔一个蛋，无非是碎或不碎两种可能。
         * 如果碎了，那我们面对的是K-1，N/2的情况，如果没碎，
         * 面对的是K，N/2的情况（当然这两种的层数可能会差一大家不用计较）
         * 所以说，蛋碎面对的输出结果肯定是相对于不碎的输出结果更坏的，
         * 也就是尝试次数相对更多。为了找到最少的尝试次数，我们就要"偏向"一下坏情况。
         * 在二分的基础上偏向下扔一层，这样相当于是蛋碎面对的是K-1，N/2-1。不碎面对的是K，N/2+1。
         * 这样好情况输出的结果会更"坏"一些，坏情况输出的结果会更"好"一些。但如果还是坏情况次数更多，我们就要把偏向调的更高。
         * 直到坏情况的次数不大于好情况。这样我们的解才能是全局最优的。
         */
        while(left > right) {
            /*偶数的话二分不能均分所以做一下处理*/
            if(N % 2 == 0) left = eggDrop(K-1,N/2-1-bias,memory);
            else left = eggDrop(K-1,N/2-bias,memory);
            right = eggDrop(K,N/2+bias,memory);
            bias++;
        }

        memory[K-1][N-1] = right+1;
        return right+1;
    }

    public int superEggDrop(int K, int N) {
        int[][] memory = new int[K][N];
        return eggDrop(K,N,memory);
    }
