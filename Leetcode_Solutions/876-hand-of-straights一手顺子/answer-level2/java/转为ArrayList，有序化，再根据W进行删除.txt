### 解题思路
1.array->arraylist并排序 2.用循环选出每一组数[min,min+1,...,min+W-1]并将他们从列表中删除（若找不到则false，若最后列表非空则false）

### 代码

```java
class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        //hand不能被w整除
		if(hand.length % W != 0 || W>hand.length || W<1){
		    return false;
		}

		Arrays.sort(hand);
		ArrayList<Integer> h = new ArrayList<>();
		for(int e:hand){
		    h.add(e);
		}
		        
		while(!h.isEmpty()) {
		    int first = h.get(0);
		    h.remove((Integer)first);

		            
		    for(int j = 1; j<W; j++){
		        if(h.contains(first+j)){
		            h.remove((Integer)(first+j));
		        else{
		            return false;
		        }
		        }		        
		    }
		}        
		if(h.isEmpty()) return true;
		return false;
    	
}
```