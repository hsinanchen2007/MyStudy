有点像高斯小学数据题的解题思路
```
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
    	for(int i = 0;i<16;i++){
    		//取右边
    		int right = (n>>i)&1;
    		//取左边
    		int left = (n>>(31-i))&1;
    		//相同不操作
    		if(left==right)
    			continue;
    		//不同 则变换   
    		n = n ^ (1<<(31-i));
    		n = n ^ (1<<i);
    	}
    	return n;
    }
}
```
