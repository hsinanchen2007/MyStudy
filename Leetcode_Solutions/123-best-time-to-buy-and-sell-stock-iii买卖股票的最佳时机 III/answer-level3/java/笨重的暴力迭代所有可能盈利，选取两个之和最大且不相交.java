执行结果：
通过
显示详情
执行用时 :
93 ms
, 在所有 Java 提交中击败了
11.72%
的用户
内存消耗 :
40.8 MB
, 在所有 Java 提交中击败了
12.08%
的用户
```
class Solution {
     
    Map<Integer,List<Integer>> map = new HashMap<>();
    Map<Integer,List<int[]>> segm = new HashMap<>();
    Map<Integer,Integer> ite = new HashMap<>();
    
    public int maxProfit(int[] prices) {
        int len=prices.length;
        if(len<=1)return 0;
        
        int min = prices[0];
        int mini=0;
        for(int i=1; i<len;i++){
            if(prices[i]>=prices[i-1]){
                if(i==len-1){
                    ite.put( mini,i);
                }
                continue;
            }else{
            	if(i-1>mini)ite.put(mini, i-1);
            	if(prices[i]<=min) {
            		min=prices[i];
            		mini=i;
            		continue;
            	}
            	
                List<Integer> list = new ArrayList<Integer>();
                
                for(int j=i+1;j<len;j++){
                    // if(prices[j]<=min)break;
                    if(prices[j]>prices[i-1]){
                    	if(!list.isEmpty()) {
                        	if(prices[j]>prices[list.get(list.size()-1)]){
                        		list.add(j);
                        	}
                        }else {
                        	list.add(j);
                        }
                    }
                }
                if(!list.isEmpty()){
                    map.put(i-1,list);
                }
                mini=i;
                min = prices[i];
            }
        }
        PriorityQueue<Integer> que = new PriorityQueue<>(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return o2.compareTo(o1);
			}
        	
        });
        if(ite.isEmpty())return 0;
        for(Map.Entry<Integer, Integer> entry: ite.entrySet()) {
        	int key = entry.getKey();
        	int value = entry.getValue();
        	int v= prices[value]-prices[key];
        	que.add(v);
        	if(segm.get(v)==null) {
        		List<int[]> list = new ArrayList<>();
        		segm.put(v, list);
        	}
        	int[] seg = new int[] {key,value};
        	segm.get(v).add(seg);
        	if(map.get(value)!=null){
                for(Integer i : map.get(value)){
                        int v2 = prices[i]-prices[key];
                        que.add(v2);
                    	if(segm.get(v2)==null) {
                    		List<int[]> list = new ArrayList<>();
                    		segm.put(v2, list);
                    	}
                    	int[] seg2 = new int[] {key,i};
                    	segm.get(v2).add(seg2);
                }
            }
        }
        int ultra=0;
        Map<int[],Integer> addedsegm = new LinkedHashMap<>();
        while(!que.isEmpty()) {
        	int v = que.poll();
        	if(segm.get(v)!=null) {
        		for(int[] seg: segm.get(v)) {
        			int re = canmerge(addedsegm,v,seg);
        			if(re>ultra) {
        				ultra=re;
        			}
        		}
        	}
        }
        return  ultra;
    }
    private int canmerge(Map<int[],Integer> addedsegm , int v, int[] seg) {
    	if(addedsegm.isEmpty()) {
    		addedsegm.put(seg,v);
    		return v;
    	}
    	int max=-1;
    	for(Map.Entry<int[], Integer> entry: addedsegm.entrySet()) {
    		int[] key = entry.getKey();
    		if(key[1]<seg[0]||seg[1]<key[0]) {
    			if( entry.getValue()+v>max)max=entry.getValue()+v;
    		}
    	}
    	addedsegm.put(seg,v);
		return max;
    	
    }
}
```
