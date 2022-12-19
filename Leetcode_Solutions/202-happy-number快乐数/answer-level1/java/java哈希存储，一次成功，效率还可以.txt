```
class Solution {
    public boolean isHappy(int n) {
        Map<Integer, Integer> map = new HashMap<>();
        int index =0;
        int nextSum=0;
        while(nextSum !=1) {
        	nextSum =addSum(n);//求解下一个和
        	if(map.containsKey(nextSum))//之前求解过就返回false，不可能出现1了
            	return false;
            map.put(nextSum, index++);//没求就添加进去
            n=nextSum;//更新n为当前求解的和
        } 
        return true;
    }
    
	private int addSum(int n) {//求和函数
        int sum =0;
        while(n>0) {
        	int last = n%10;
        	sum+=last *last;
        	n/=10;
        }		
        return sum;
	}
}

```
