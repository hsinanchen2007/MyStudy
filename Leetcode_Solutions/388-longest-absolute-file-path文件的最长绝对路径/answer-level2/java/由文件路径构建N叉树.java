### 解题思路
由文件路径构建N叉树(或图),遍历每条路径找到含有文件的路径,计算路径的字符串长度,求出路径最长的就是答案。

### 代码

```java
class Solution {
     public int lengthLongestPath(String input) {
    	input = input.replace("\n    ","\n\t");
        StringBuilder sb = new StringBuilder(input);
        for(int i = 0;i < sb.length();i++) {
            if(sb.charAt(i) == '\n' || sb.charAt(i) =='\t') {
        	  sb.deleteCharAt(i);
        	  sb.insert(i, '&');
        	}
        }
        String match = "&";
        List<String> arr = Match(sb.toString(),match,0);
        List<List<String>> res = new ArrayList<List<String>>();
        int ans = 0;
        if(arr.size() == 0) {
            Nodestr rootstr = buildtree(sb.toString(),0);
            dfs(rootstr,new ArrayList<String>(),res);
            for(List<String> l : res) {
            	int cnt = 0;
            	boolean flag = true;
            	for(int i = l.size() - 1;i >= 0;i--) {
            	    if(i == l.size() - 1) {
            	       if(!l.get(i).contains(".")) {
            		      flag = false;
            		      break;
            		    }
            		 }
            		cnt += l.get(i).length();
            	}
            	if(flag)
             	    ans = Math.max(ans, cnt + l.size() - 1);
             	else
             	    flag = true;
            }
        }else {
        	for(int i = 0;i < arr.size();i++) {
        	    root.children.add(buildtree(arr.get(i),0));
        	}
        	dfs(root,new ArrayList<String>(),res);
        	for(List<String> l : res) {
             	    int cnt = 0;
             	    boolean flag = true;
             	    l.remove(0);
             	    for(int i = l.size() - 1;i >= 0;i--) {
             		if(i == l.size() - 1) {
             			if(!l.get(i).contains(".")) {
             				flag = false;
             				break;
             			}
             		}
             	      cnt += l.get(i).length();
             	}
             	if(flag)
             	    ans = Math.max(ans, cnt + l.size() - 1);
             	else
             	    flag = true;
             }
        }
        return ans;
    }
    Nodestr root = new Nodestr("");
    public void dfs(Nodestr root,List<String> ans,List<List<String>> res) {
    	if(root.children.size() == 0) {
    		ans.add(root.str);
    		res.add(new ArrayList<String>(ans));
    		ans.remove(ans.size() - 1);
    		return;
    	}
    	for(Nodestr n : root.children) {
    		ans.add(root.str);
    		dfs(n,ans,res);
    		ans.remove(ans.size() - 1);
    	}
    }
    public Nodestr buildtree(String s,int depth){
        if(s.length() == 0) return null;
        String match = "&&";
        int cnt = depth;
        while(cnt != 0){
            match += "&";
            cnt--;
        }
        Nodestr rootstr = null;
        List<String> matchnode = Match(s,match,depth);
        if(matchnode.size() > 0) {
        	 rootstr = new Nodestr(matchnode.get(0));
             for(int i = 1;i < matchnode.size();i++){
                 rootstr.children.add(buildtree(matchnode.get(i),depth + 1));
             }
        }
        return  rootstr;
    }
    public List<String> Match(String s,String match,int depth){
         List<String> ans = new ArrayList<>();
         if(!s.contains(match)){
             ans.add(s);
             return ans;
         }
         int i = 0;
         List<Integer> idx = new ArrayList<>();
         while(i < s.length()){
             if(i > 0 && i < s.length() && s.charAt(i - 1) != '&' && s.charAt(i) == '&'){
                  if(i + match.length() <= s.length() 
                     && match.equals(s.substring(i,i + match.length()))){
                      int index = i + match.length();
                      if(index < s.length() && s.charAt(index) != '&'){
                         idx.add(i);
                         }  
                        }
                       }
                    i++;
                }
          for(int j = 0;j < idx.size();j++){
              if(j == 0){
                  ans.add(s.substring(0,idx.get(j)));
              }else if(j > 0){
                  ans.add(s.substring(idx.get(j - 1) + match.length(),idx.get(j)));
              }
          }
          if(idx.size() > 0)
          ans.add(s.substring(idx.get(idx.size() - 1) + match.length(),s.length()));
          return ans;
         }
}
class Nodestr{
	    String str;
	    List<Nodestr> children;
	    public Nodestr(String val){
	        this.str = val;
	        this.children = new ArrayList<>();
	    }
	}
```