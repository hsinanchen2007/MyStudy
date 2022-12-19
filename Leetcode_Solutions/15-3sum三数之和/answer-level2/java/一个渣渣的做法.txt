![2020011701.PNG](https://pic.leetcode-cn.com/49ffac11febd358339b04d82638d0c672d4eb424245019eb375c17bd1b361b9e-2020011701.PNG)
### 解题思路
这个做法太渣了,改天来改进;
哈哈哈！！
### 代码

```java
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
    	List<List<Integer>> out = new ArrayList<>();//声明一个二维的List
    	List<Integer> neg = new ArrayList<>();
    	List<Integer> pos = new ArrayList<>();
    	int count = 0;
    	if(nums.length<3) {
    		return out;
    	}else {
    		for(int i=0;i<nums.length;i++) {
        		if(nums[i]<0) {
        			neg.add(nums[i]);
        		}else if(nums[i]==0){
        			count ++;
        		}else {
        			pos.add(nums[i]);
        		}
        	}
        	List<Integer> rec = new ArrayList<>();
    		if(count>=3) {
    			rec.add(0);
    			rec.add(0);
    			rec.add(0);
    			out.add(rec);
    			rec = new ArrayList<>();
    		}
        	Object[] negArr = neg.toArray();
        	Object[] posArr = pos.toArray();
        	Arrays.sort(negArr);
        	Arrays.sort(posArr);
        	List<Integer> dupNegList = new ArrayList<>();
        	List<Integer> dupPosList = new ArrayList<>();
        	Map<Integer,Integer> negMap = new HashMap<>();
        	Map<Integer,Integer> posMap = new HashMap<>();
        	for(int i =0;i<negArr.length;i++) {
        		if(!negMap.containsKey(negArr[i])) {
        			negMap.put((int)negArr[i],1);
        			dupNegList.add((int)negArr[i]);
        		}else {
        			negMap.put((int)negArr[i],negMap.get((int)negArr[i])+1);
        		}
        	}
        	
        	for(int i =0;i<posArr.length;i++) {
        		if(!posMap.containsKey(posArr[i])) {
        			posMap.put((int)posArr[i],1);
        			dupPosList.add((int)posArr[i]);
        		}else {
        			posMap.put((int)posArr[i],posMap.get((int)posArr[i])+1);
        		}
        	}
        	if(count>0) {
        		for(int i :negMap.keySet()) {
        			if(posMap.containsKey((-1)*(int)i)){
        				rec.add((int)i);
        				rec.add(0);
        				rec.add((-1)*(int)i);
        				out.add(rec);
        				rec = new ArrayList<>();
        			}
        		}
        	}
        	
    		MyNeg negative = new MyNeg();
    		List<List<Integer>> neg1 = negative.myNeg(dupPosList, negMap);
    		for(int i=0;i<neg1.size();i++) {
    			out.add(neg1.get(i));
    		}

    		List<List<Integer>> neg2 = negative.myNeg(dupNegList, posMap);
    		for(int i=0;i<neg2.size();i++) {
    			out.add(neg2.get(i));
    		}
    		
        	MyPos positive = new MyPos();
        	List<List<Integer>> pos1 = positive.myPos(dupPosList, posMap, negMap);
        	for(int i=0;i<pos1.size();i++) {
        		out.add(pos1.get(i));
        	}
        	List<List<Integer>> pos2 = positive.myPos(dupNegList, negMap, posMap);
        	for(int i=0;i<pos2.size();i++) {
        		out.add(pos2.get(i));
        	}
        	
    	}
    	return out;
    }
}
class MyPos{
    public List<List<Integer>> myPos(List<Integer> nums, Map<Integer, Integer> posMap1, Map<Integer, Integer> negMap1){
    	List<List<Integer>> out1 = new ArrayList<>();
    	List<Integer> rec = new ArrayList<>();
    	List<Integer> dupPosList = nums;
    	Map<Integer,Integer> posMap = posMap1;
    	Map<Integer,Integer> negMap = negMap1;
    	for(int i =0;i<dupPosList.size();i++) {
    		if(posMap.get((int)dupPosList.get(i))>=2){
    			int s = 2*(-1)*(int)dupPosList.get(i);
    			if(negMap.containsKey(s)) {
    				rec.add(s);
    				rec.add((int)dupPosList.get(i));
    				rec.add((int)dupPosList.get(i));
    				out1.add(rec);
    				rec = new ArrayList<>();
    			}
    		}
    	}
    	return out1;
    }
}

class MyNeg{
    public List<List<Integer>> myNeg(List<Integer> nums, Map<Integer, Integer> posMap1){
    	List<List<Integer>> out1 = new ArrayList<>();
    	List<Integer> dupPosList = nums;
    	List<Integer> rec = new ArrayList<>();
    	Map<Integer,Integer> negMap = posMap1;
    	for(int i =0;i<dupPosList.size()-1;i++) {
    		for(int j=i+1;j<dupPosList.size();j++) {
    			int sum = (int)dupPosList.get(i)+(int)dupPosList.get(j);
    			sum *= (-1);
    			if(negMap.containsKey(sum)) {
    				rec.add(sum);
    				rec.add((int)dupPosList.get(i));
    				rec.add((int)dupPosList.get(j));
    				out1.add(rec);
    				rec = new ArrayList<>();
    			}
    		}
    	}
    	return out1;
    }
}
```