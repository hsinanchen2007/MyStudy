```
class Solution {
    private int find(int p,int[]parent) {
		if(p!=parent[p]) {
			parent[p]=find(parent[p], parent);
		}
		return parent[p];
	}
	private void union(int[]parent,int p,int q) {
		int pRoot=find(p,parent);
		int qRoot=find(q,parent);
		if(pRoot==qRoot) {
			return;
		}
		parent[pRoot]=qRoot;
	}
	public List<List<String>> accountsMerge(List<List<String>> accounts) {
        /*
         * 这道题的思路就是我刚开始想的那样，每一次去一个账户，如果发现该账户中有和前一个
         * 账户相同的电子邮箱的地址，那就将这两个账户合并
         */
		int[]parent=new int[accounts.size()];//声明一个并查集
		for(int i=0;i<parent.length;i++) {
			parent[i]=i;
		}//初始化并查集
		//初始化一个散列表，是邮箱指向用户(用户这里用数字来表示)
		Map<String,Integer> map=new HashMap<String, Integer>();
		for(int i=0;i<accounts.size();i++) {
			for(int j=1;j<accounts.get(i).size();j++) {
				if(!map.containsKey(accounts.get(i).get(j))) {
					map.put(accounts.get(i).get(j),i);
				}//如果散列表中没有这个电子邮箱，那就将它指向它的老大就好了
				else {
					union(parent,map.get(accounts.get(i).get(j)),i);
				}//如果有这个电子邮箱，那就合并两个账户
			}
		}//遍历这个账户集合
	    //虽然在散列表中进行了合并，但是实际上没有将根相同的用户放到一块
		Map<Integer,List<String>> fuzhu=new HashMap<Integer, List<String>>();
		for(Map.Entry<String, Integer> entry:map.entrySet()) {
			int user=find(map.get(entry.getKey()),parent);//找到当前的这个邮箱对应的user
			if(!fuzhu.containsKey(user)) {
				List<String> cur=new ArrayList<String>();
				cur.add(accounts.get(user).get(0));
				cur.add(entry.getKey());
				fuzhu.put(user,cur);
			}else {
				fuzhu.get(user).add(entry.getKey());
			}
		}
		List<List<String>> res=new ArrayList<List<String>>();
		for(Integer i:fuzhu.keySet()) {
			List<String> cur=new ArrayList<String>();
			cur=fuzhu.get(i);
			Collections.sort(cur);
			res.add(cur);
		}
		return res;
    }
}
```
