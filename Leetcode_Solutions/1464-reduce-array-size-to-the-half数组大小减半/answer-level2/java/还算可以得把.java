![微信截图_20200222222154.png](https://pic.leetcode-cn.com/b4237209effade2cdd60504f2cd780af20697e0e9d8fdab8b9c301efbaa333ca-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200222222154.png) 
public int minSetSize(int[] arr) {

    	List<Integer> list = new ArrayList<Integer>();
    	Map<Integer,Integer> map = new HashMap<Integer, Integer>();
    	for(int i:arr) {
    		map.put(i, map.getOrDefault(i, 0)+1);
    	}
    	for(int i:map.keySet()) {
    		list.add(map.get(i));
    	}
    	Collections.sort(list);
    	int leng = arr.length;
    	int count=0;
    	int sum = 0;
    	for(int i=list.size()-1;i>=0;i--) {
    		sum+=list.get(i);
    		if(sum<leng/2) {
    			count++;
    		}else {
    			return count;
    		}
    	}
    	return count;
    }