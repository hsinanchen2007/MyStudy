```
 public int findLucky(int[] arr) {
        int lucky = -1;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i = 0 ; i < arr.length ; i++){
         if(map.containsKey(arr[i])) 
         map.put(arr[i],map.get(arr[i]) + 1);
         else map.put(arr[i],1);
                                             }
 for(Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator() ; it.hasNext();) {
				Map.Entry<Integer, Integer> eit = it.next();
                Integer key = eit.getKey();
                Integer value = eit.getValue();
                if(key == value && key > lucky) lucky = key;
                  }
                    return lucky;
                                   } 
```
