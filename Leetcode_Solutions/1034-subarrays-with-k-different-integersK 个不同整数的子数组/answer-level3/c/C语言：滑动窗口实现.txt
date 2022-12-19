```

int subarraysWithKDistinct(int* A, int ASize, int K){
    int left = 0;
    int right = 0;
    int diff = 0;//统计不同整数的个数
    int res = 0;//最终返回的个数
    int* hash = (int*)malloc(sizeof(int) * (ASize + 1));//辅助计算不同整数的个数
    memset(hash,0,sizeof(int) * (ASize + 1));
    
    while(right < ASize) {
        //如果哈希数组是0，证明是一个新的数
        if(hash[A[right]] == 0) {
            diff++;
        }
        hash[A[right]]++;
        
        while(diff > K) {//如果不同整数的个数大于K，缩小左边窗口，直到满足限制条件：不同整数的个数等于K
            hash[A[left]]--;//error:缩小的是A【left】，而不是hash【left】
            if(hash[A[left]] == 0) {//判断：如果哈希个数等于0，证明减去了一个数
                diff--;
            }
            left++;
        }
        int temp_left = left;
        //如果不同整数的个数等于K，计算个数，并扩大窗口
        if(diff == K) {
            //计算K个不同整数数组的个数：统计方法是，从后面算起，慢慢减少，比如1，2，1，是从【1,2,1】，【2,1】这样计算的；同时要知道每次新进来的一个已有的数字，都会与上次新增的子数组进行一次组合，并且新增一个长度加1的更大的数组
            while(diff == K) {
                hash[A[temp_left]]--;
                if(hash[A[temp_left]] == 0) {
                    diff--;
                }
                temp_left++;
                res++;
            }
            //复原之前的状态，并且退出
            for(int j = left;j < temp_left;j++) {
                if(hash[A[j]]++ == 0) {
                    diff++;
                }
            }
        }
        right++;
    }
    
    return res;
}


```

