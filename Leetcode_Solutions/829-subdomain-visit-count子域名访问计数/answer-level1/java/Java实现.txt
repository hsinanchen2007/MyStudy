![图片.png](https://pic.leetcode-cn.com/42ce9a314f5a49c83fdcca75c701cf9d1e909dee4b642dda8a20ac9a766044e0-%E5%9B%BE%E7%89%87.png)
```
class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
     List<String> list=new ArrayList<>();
		int times=0;
		String site="";
		String secsite="";
		Map<String,Integer> map=new HashMap<>();
		for(int i=0;i<cpdomains.length;i++)
		{
			String[] arr=cpdomains[i].split(" ");
			times=Integer.parseInt(arr[0]);
			site=arr[1];
			String[] temp=site.split("\\.");
			
			
			put(map,site,times);
			
			if(temp.length==3){
				secsite=temp[1]+"."+temp[2];
				put(map,temp[2],times);
				put(map,secsite,times);
				
			
		}
			if(temp.length==2)
			{
				put(map,temp[1],times);
			}
		}
		for(Map.Entry<String, Integer> entry:map.entrySet()){
			list.add(entry.getValue()+" "+entry.getKey());
		}
		return list;
	}
	 private static void put(Map<String,Integer> map,String key,Integer val) {
	        if (map.containsKey(key)) {
	            map.put(key,map.get(key) + val);
	        } else {
	            map.put(key,val);
	        }
	    
    }
}
```


