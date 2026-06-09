动态规划：
```
public int findLength(int[] numa, int[] numb) {
    	if(numa == null || numb ==null){
    		return 0;
    	}
    	int max = 0;
    	int aLen = numa.length, bLen = numb.length;
    	
    	int[][] result = new int[aLen][bLen];
    	for(int i=0; i<aLen; i++){
    		for(int j=0; j<bLen; j++){
    			if(numa[i] != numb[j]){
    				result[i][j] = 0;
    			}else{
    				if(i>0 && j>0){
    					result[i][j] = result[i-1][j-1]+1;
    				}else{
    					result[i][j] = 1;
    				}
    			}
    			if(max < result[i][j]){
    				max = result[i][j];
    			}
    		}
    	}
    	return max;
    }
```


暴力法：
```
public int findLength1(int[] numa, int[] numb) {
    	if(numa == null || numb ==null){
    		return 0;
    	}
    	int max = 0;
    	int aLen = numa.length, bLen = numb.length;
    	
    	int aIndex, bIndex, sameLen;
    	for(int i=0; i<aLen; i++){
    		for(int j=0; j<bLen; j++){
    			aIndex = i;
    			bIndex = j;
    			sameLen = 0;
    			while(aIndex<aLen && bIndex<bLen && numa[aIndex]==numb[bIndex] ){
    				sameLen++;
    				aIndex++;
    				bIndex++;
    			}
    			if(max < sameLen){
    				max = sameLen;
    			}
    		}
    	}
    	return max;
    }
    
```

hash：
 
	
    ```
public int findLength2(int[] A, int[] B) {
        if(A == null || B == null){
        	return 0;
        }
        Map<Integer, Set<Integer>> valueToIndex = new HashMap<>();
        for(int i=0; i<B.length; i++){
        	if(!valueToIndex.containsKey(B[i])){
        		Set<Integer> set = new HashSet<>();
        		set.add(i);
        		valueToIndex.put(B[i], set);
        	}else{
        		valueToIndex.get(B[i]).add(i);
        	}
        }
        
        int max = 1;
        int count = 0;
        int aIndex ,bIndex,alen=A.length,blen=B.length;
        for(int i=0; i<A.length; i++){
        	Set<Integer> indexSet = valueToIndex.get(A[i]);
        	if(indexSet != null){
            	for(int start : indexSet){
            		count =1;
            		bIndex=start+1;
            		aIndex=i+1;
            		while(aIndex<alen && bIndex<blen && A[aIndex]==B[bIndex]){
            			count++;
            			aIndex++;
            			bIndex++;
            		}
            		if(count>max){
            			max = count;
            		}
            	}
        	}
        }
        return max;
    }
```
