你们都太聪明了，打死我也想不到位运算。。。

来个二分干了吧 

    public boolean isPowerOfTwo(int n) {
        if (n<=0) return false;

        int left = 1, right = n/2;

        while (left+1<right){
            int mid = (right-left)/2 + left;
            double temp = Math.pow(2,mid);

            if (temp == n) return true;
            else if (temp>n) right = mid;
            else left = mid;
        }

        if (Math.pow(2,left) == n) return true;
        if (Math.pow(2,right) == n) return true;

        return false;
    }
