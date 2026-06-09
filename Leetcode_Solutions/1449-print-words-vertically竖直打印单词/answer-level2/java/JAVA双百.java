### 解题思路
边界问题处理好即可

### 代码

```java
class Solution {
public List<String> printVertically(String s) {
		List<String> list = new ArrayList<String>();
		int index=-1;
		int wordNum=0;
        for(int i =0; i<s.length() ; i++) {
        	char c = s.charAt(i);
        	if(c==' ') {
        		if(list.size()==0)continue;
        		while(c==' ') {
        			i++;
        			if(i==s.length())return list;
        			c = s.charAt(i);
        		}
        		
        		index=0;
        		wordNum++;

        	}
        	if(index==-1)
        		list.add(c+"");
        	else {
        		if(index>=list.size()) {
        			String string="";
        			for(int j=0;j<wordNum;j++)
        				string+=" ";
        			list.add(string+c);
        		}else {
        			String string = "";
        			for(int j=0 ; j<wordNum-list.get(index).length();j++)
        				string+=" ";
        			list.set(index,list.get(index)+string+c);
    				
        		}
        		index++;
				
			}
        	
        }
        return list;
    }
}
```