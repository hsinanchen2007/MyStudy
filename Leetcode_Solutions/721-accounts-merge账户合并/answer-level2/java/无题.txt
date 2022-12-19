其实这道题我用了n^4的复杂度，结果在第48个用例时超时了。自己也没什么思路，然后在网上看别人题解才知道的。需要用到的算法是`深度优先搜索`，还有`Map`、`Set`两个数据结构。

________________________________________________________________________________

`HashMap<String , ArrayList<Integer > > table`用来存储每个邮箱的主人的下标
```
 for(int i = 0; i < accounts.size(); ++i) {
        	for(int j = 1; j < accounts.get(i).size(); ++j) {
        		ArrayList<Integer > e;
        		if(table.containsKey(accounts.get(i).get(j))) {
        			e = table.get(accounts.get(i).get(j));
        		}
        		else {
        			e = new ArrayList<Integer >();
        		}
        		e.add(i);
    			table.put(accounts.get(i).get(j), e);
        	}
        }
```

______________________________________________________________________________

第二步，开始合并账户。先用一个`boolean[] book`数组来标记哪些以访问过，创建一个`HashSet<String > temp`来存储邮箱。开始遍历，取出第一个邮箱加入HashSet，然后在HashMap查找哪些用户有这个邮箱，通过HashMap里ArrayList<Integer >的值去遍历accounts，ArrayList<Integer >里的人都要合并。注意要判断这个人是否已经遍历过。
```
public void dfs(List<List<String > > accounts, boolean[] book, HashSet<String > temp, int now) {
    	if(book[now]) return ;
    	book[now] = true;
    	for(int i = 0; i < accounts.get(now).size(); ++i) {
    		temp.add(accounts.get(now).get(i));
    		for(int j : table.get(accounts.get(now).get(i))) {
    			if(book[j] == false) dfs(accounts, book, temp, i); 
    		}
    	}
    }
```

______________________________________________________________________________________________________

最后，把HashSet里的邮箱复制给List<String >,在对每一个用户排一些序就可以了。


```
class Solution {
	
	HashMap<String , ArrayList<Integer > > table = new HashMap<String , ArrayList<Integer > >();
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        List<List<String > > ans = new ArrayList<List<String > >();
        
        
        for(int i = 0; i < accounts.size(); ++i) {
        	for(int j = 1; j < accounts.get(i).size(); ++j) {
        		ArrayList<Integer > e;
        		if(table.containsKey(accounts.get(i).get(j))) {
        			e = table.get(accounts.get(i).get(j));
        		}
        		else {
        			e = new ArrayList<Integer >();
        		}
        		e.add(i);
    			table.put(accounts.get(i).get(j), e);
        	}
        }
       
        
        boolean[] book = new boolean[accounts.size()];
        Arrays.fill(book, false);
        
        for(int i = 0; i < accounts.size(); ++i) {
        	if(!book[i]) {
        		HashSet<String > temp = new HashSet<String >();
        		dfs(accounts, book, temp, i);
        		ArrayList<String > e = new ArrayList<String >();
        		e.add(accounts.get(i).get(0));
        		for(String j : temp) {
        			e.add(j);
        		}
        		ans.add(e);
        	}
        }
        
        
         for(int i = 0; i < ans.size(); ++i)
        	Collections.sort(ans.get(i));
        
        return ans;
    }
    
    public void dfs(List<List<String > > accounts, boolean[] book, HashSet<String > temp, int now) {
    	if(book[now]) return ;
    	book[now] = true;
    	for(int i = 1; i < accounts.get(now).size(); ++i) {
    		temp.add(accounts.get(now).get(i));
    		for(int j : table.get(accounts.get(now).get(i))) {
    			if(book[j] == false) dfs(accounts, book, temp, j); 
    		}
    	}
    }
    
    
}

```


