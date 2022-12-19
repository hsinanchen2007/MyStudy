```
class Solution {
    public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
       List<Integer>  list = new ArrayList<Integer>();  
        //没有原料的情况
	     if(tomatoSlices==0 && cheeseSlices==0){
	    	 list.add(tomatoSlices);
	    	 list.add(cheeseSlices);
	    	 return list;
	     }
        //有原料的情况
	     for (int i1 = 0; i1 <= cheeseSlices; i1++) {
	    	int i2 = cheeseSlices- i1;
			if(4*i1+2*i2==tomatoSlices){
				list.add(i1);
				list.add(i2);
				return list;
			}
		}
		 return list;
    }
}
```
