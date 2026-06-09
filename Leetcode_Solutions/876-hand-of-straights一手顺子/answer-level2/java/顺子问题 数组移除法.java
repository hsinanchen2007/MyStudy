思路：
     * 1.先将数组排序，然后加到list中
	 * 2.从list头部开始取出连续的W个数
	 * 3.如果上一步数组长度不够，或者取不出W个连续的数，返回false
	 * 4.重复2操作
```
class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        
		  Arrays.sort(hand);
		  int len = hand.length;
		  if(len % W != 0){
			  return false;
		  }
		  
		  List<Integer> list = new ArrayList<Integer>();
		  for(int i = 0; i < len; i++){
			  list.add(hand[i]);
		  }

		  while(list.size() > 0){
			  
			  Integer curVal = list.get(0);
			  for(int i = 0; i < W; i++){
				  if(list.size() == 0)
					  return false;
				  if(! list.remove(curVal) )
					  return false;
				  curVal++;
			  }
		  }
		  
	        return true;
	    
    }
}
```
