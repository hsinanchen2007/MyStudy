很菜的写法，居然通过了，解法写在注释中，大家帮看看。
```
	/**
	 * 首先要说明的是，取最大值，只有6转9，没有9转6。所以从
	 * 高位判断，是9就跳过，是6就转一次。
	 * 首先用把数字转化为List集合,低位在前，高位在后。
	 * 然后从高位开始遍历集合，也就是从后往前遍历，
	 * 如果取出的数是9，则res乘10进位再加9，
	 * 如果取出的数是6，判断一下标志位，标位为0，则6转9，
	 * 否则，res乘10进位再加6
	 * @param num
	 * @return
	 */
    public int maximum69Number (int num) {
    	int res = 0;
    	int flag = 0;
    	List<Integer> list = new ArrayList<Integer>();
    	int cur = num;
    	while(cur>0) {
    		list.add(cur%10);
    		cur = cur/10;
    	}
    	for (int i = list.size()-1; i >=0; i--) {
    		if(9==list.get(i)) {
    			res = res*10+9;
    		}else {
    			if(flag==0) {
    				res = res*10+9;
    				flag = 1;
    			}else {
    				res = res*10+6;
    			}
    		}
		}
    	return res;
    }
```
