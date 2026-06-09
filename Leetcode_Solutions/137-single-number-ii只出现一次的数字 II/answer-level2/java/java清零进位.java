public int singleNumber(int[] nums) {
		int one = 0;
		int two = 0;
		int three = -1;
        for(int num:nums) {
        	int carry3 = three&num;//3向1的进位
        	int carry2 = two&num;//2向3的进位
        	int carry1 = one&num;//1向2的进位
        	one = (one&~carry1)|carry3;//先算清零再算进位
        	two = (two&~carry2)|carry1;//先算清零再算进位
        	three = (three&~carry3)|carry2;//先算清零再算进位
        }
        return one;
    }