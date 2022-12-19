### 解题思路
此处撰写解题思路
主要是构造了字典树，将字符串按字典树组织起来，value值存储在叶子结点里；
在求和时，走到前缀对应的那个结点，再深搜一下就好了！
### 代码

```java
class MapSum {

    /** Initialize your data structure here. */
    public static final int  MAX_NUM=26;
	boolean isleaf;
	int value;
	List<MapSum> children= null;
	
	
    public MapSum() {
        isleaf=false;
        value=0;
        children =new ArrayList();
        for(int i=0;i<MAX_NUM;i++) {
        	children.add(null);
        }
        
    }
    
    public void insert(String key, int val) {
        MapSum cur=this;
        for(int i=0;i<key.length();i++)
        {
        	 if(cur.children.get(key.charAt(i)-'a')==null) {
        		 cur.children.set(key.charAt(i)-'a',new MapSum());
        	 }
        	 cur=cur.children.get(key.charAt(i)-'a');
        }
        cur.isleaf=true;
        cur.value=val;
    }
    
    public int sum(String prefix) {
        MapSum cur=this;
        for(int i=0;i<prefix.length();i++)
        {
        	if(cur.children.get(prefix.charAt(i)-'a')!=null)
        		cur=cur.children.get(prefix.charAt(i)-'a');
        	else if(i<prefix.length())
        	{
        		return 0;
        	}
        }
        int s=0;
        s=new Sum().sum(cur);
        return s;
    }
}
class Sum
{
	int res=0;
	int sum(MapSum m)
	{
		if(m==null) return 0;
		if(m.isleaf==true) res+=m.value;
		
		for(int i=0;i<26;i++)
		{
			sum(m.children.get(i));
		}
		return res;
	}
}
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
```