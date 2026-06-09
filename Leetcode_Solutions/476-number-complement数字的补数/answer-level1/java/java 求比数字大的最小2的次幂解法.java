数字+他的补数=000011111111111 (位数输入数字的第一个1所在位置决定)
利用这个特性
```
    public int findComplement(int num) {
    	int sum = num;
    	sum|=sum>>1;
    	sum|=sum>>2;
    	sum|=sum>>4;
    	sum|=sum>>8;
    	sum|=sum>>16;
        return sum-num;
    }  
```
灵感来源:java hashmap源码中tableSizeFor();
