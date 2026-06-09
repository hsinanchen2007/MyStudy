执行结果：
通过
显示详情
执行用时 :
130 ms
, 在所有 Java 提交中击败了
5.06%
的用户
内存消耗 :
38.4 MB
, 在所有 Java 提交中击败了
23.22%
的用户
```
class Solution {
	    Map<Integer,Set<Character>> map = new HashMap<>();
	     Set<Character> full = full();
	    //possiblity left
	        Map<String,Set<Character>> lmap = new HashMap<>();
	    //pos not sure
	        Map<Integer,Set<String>> todoMap = new TreeMap<>();
	    //pos,value
	     Map<String,Character> tempMap = new TreeMap<>();
	    public void solveSudoku(char[]
	                            [] board) {
	       
	        for(int i=0; i<9; i++){
	           for(int j=0; j<9; j++){
	                if(map.get(i)==null){
	                    Set<Character> set = new HashSet<>();
	                    map.put(i,set);
	                }
	               if(map.get(10+j)==null){
	                    Set<Character> set = new HashSet<>();
	                    map.put(10+j,set);
	                }
	               if(map.get(20+block(i,j))==null){
	                    Set<Character> set = new HashSet<>();
	                    map.put(20+block(i,j),set);
	                }
	               if(board[i][j]=='.')continue;
	               map.get(i).add(board[i][j]);
	               map.get(10+j).add(board[i][j]);
	               map.get(20+block(i,j)).add(board[i][j]);
	               
	            } 
	        }
	        calc(board);
	        while(todoMap.size()>0){
	            if(todoMap.get(1)!=null){
	                todoMap.get(1).forEach((String s)->{
	                int i = s.charAt(0)-'0';
	                int j = s.charAt(1)-'0';
	                Character[] ccs=lmap.get(""+i+j).toArray(new Character[0]);
	                board[i][j]= ccs[0];
	                   map.get(i).add(board[i][j]);
	                   map.get(10+j).add(board[i][j]);
	                   map.get(20+block(i,j)).add(board[i][j]);
	                }); 
	                todoMap.clear();
	                calc(board);
	            }else{
	                List<String> todoList = new ArrayList<>();
	                for(Set<String> ss:todoMap.values()){
	                    todoList.addAll(ss);
	                }
	                protodo(todoList,0);
	                for(Map.Entry<String,Character> entry:tempMap.entrySet()){
	                    String s = entry.getKey();
	                      int i = s.charAt(0)-'0';
	                      int j = s.charAt(1)-'0';
	                      board[i][j]= entry.getValue();
	                }
	                
	                break;
	            }
	        }
	    }
	    private boolean protodo(List<String> list, int i ){
	        String pos = list.get(i);
	        if(lmap.get(pos)==null||lmap.get(pos).isEmpty()){
	            return false;
	        }
	        if(i==list.size()-1){
	        	if(lmap.get(pos).size()==1) {
	        		Character[] ccs=lmap.get(pos).toArray(new Character[0]);
		            tempMap.put(pos,ccs[0]);
		            return true;
	        	}else {
	        		return false;
	        	}
	            
	        }
	        for(Character c:lmap.get(pos)){
	            tempMap.put(pos,c);
	            boolean conti = true;
	            Set<String> removed = new HashSet<String>();
	            
	            for(int j=i+1;j<list.size();j++){
	                String posj=list.get(j);
	                if(posRel(pos,posj)){
	                    boolean bb = lmap.get(posj).remove(c);
	                    if(bb)removed.add(posj);
	                    if(lmap.get(posj).isEmpty()) {
	                    	conti = false;
	                    }
	                }
	            }
	            if(conti&&protodo(list,i+1)){
	                return true;
	            }
	             for(int j=i+1;j<list.size();j++){
	                String posj=list.get(j);
	                if(posRel(pos,posj)&&removed.contains(posj)){
	                    lmap.get(posj).add(c);
	                }
	            }
	            
	        }
	        return false;
	        
	    }
	    private boolean posRel(String s1, String s2){
	         int i1 = s1.charAt(0)-'0';
	         int j1 = s1.charAt(1)-'0';
	         int i2 = s2.charAt(0)-'0';
	         int j2 = s2.charAt(1)-'0';
	        if(i1==i2||j1==j2||block(i1,j1)==block(i2,j2)){
	            return true;
	        }
	        return false;
	    }
	    private void calc(char[][] board){
	         for(int i=0; i<9; i++){
	           for(int j=0; j<9; j++){
	                if(board[i][j]=='.'){
	                    if(lmap.get(""+i+j)==null){
	                        Set<Character> set = new HashSet<>(full);
	                        lmap.put(""+i+j,set);
	                    }
	                    lmap.get(""+i+j).removeAll(map.get(i));
	                    lmap.get(""+i+j).removeAll(map.get(10+j));
	                    lmap.get(""+i+j).removeAll(map.get(20+block(i,j)));
	                    
	                    if(todoMap.get(lmap.get(""+i+j).size())==null){
	                        Set<String> set = new HashSet<>();
	                        todoMap.put(lmap.get(""+i+j).size(),set);
	                    }
	                    todoMap.get(lmap.get(""+i+j).size()).add(""+i+j);
	                }
	           }
	         }
	    }
	    private int block(int i, int j){
	        int x = i/3;
	        int y = j/3;
	        return x*3+y;
	    }
	    private Set<Character> full(){
	        Set<Character> set = new HashSet<>();
	        for(int i=1; i<10; i++){
	            set.add(Character.valueOf((char)(i+'0')));
	        }
	        return set;
	    }
	    
}
```
