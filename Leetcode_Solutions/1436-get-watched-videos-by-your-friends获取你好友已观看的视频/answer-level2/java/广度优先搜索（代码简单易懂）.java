题解：将所有第一次遍历到的点加入队列，并记录当前level即可。
```
class Solution {
	
	class node{
		int x,y;
		public node(int x,int y) {
			this.x=x;
			this.y=y;
		}
	}
	
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        
    	boolean[] flag=new boolean[watchedVideos.size()];
    	List<String> ans=new ArrayList<>();
    	Queue<node> q=new LinkedList<>();
    	Map<String,Integer> map=new HashMap<>();
    	
    	flag[id]=true;
    	q.add(new node(id,0));
    	while(!q.isEmpty()) {
    		node now=q.poll();
    		if(now.y==level) {
    			for(int i=0;i<watchedVideos.get(now.x).size();i++) {
    				if(!map.containsKey(watchedVideos.get(now.x).get(i)))
    					ans.add(watchedVideos.get(now.x).get(i));
    				map.put(watchedVideos.get(now.x).get(i), 
    						map.getOrDefault(watchedVideos.get(now.x).get(i), 0)+1);
    			}
    			continue;
    		}
    		for(int i=0;i<friends[now.x].length;i++) {
    			if(flag[friends[now.x][i]]) continue;
    			flag[friends[now.x][i]]=true;
    			q.add(new node(friends[now.x][i],now.y+1));
    		}
    	}
    	
    	String[] res=new String[ans.size()];
    	for(int i=0;i<ans.size();i++) {
    		res[i]=ans.get(i);
    		//System.out.println(map.get(ans.get(i)));
    	}
    	//System.out.println(ans);
    	for(int i=0;i<res.length;i++)
    		for(int j=0;j<i;j++)
    			if(map.get(res[i])<map.get(res[j]) ||
    					map.get(res[i])==map.get(res[j]) && res[j].compareTo(res[i])>0)
    			{
    				String tmp=res[i];
    				res[i]=res[j];
    				res[j]=tmp;
    			}
    	ans.clear();
    	for(int i=0;i<res.length;i++) ans.add(res[i]);
    	return ans;
    }
}
```
