```
class Solution {
  ArrayList<String> list;
	    public ArrayList<String> letterCasePermutation(String S) {
	        list= new ArrayList<String>();
	        S=S.toLowerCase();
	        char []word = S.toCharArray();
	        int size=S.length();
	        letter(word,0,size);
	        return list;
	    }
	    private void letter(char[] word,int i,int size)
	    {
	    	list.add(String.valueOf(word));
	        for(;i<size;i++)
	        {
	            if(Character.isDigit(word[i]))
	            {
	            	continue;
	            }
	            else if(Character.isLowerCase(word[i]))
	            {
	   
	            	word[i]=Character.toUpperCase(word[i]);
	            	letter(word,i+1,size);
	            	word[i]=Character.toLowerCase(word[i]);
	            }
	        }
	        return;
	    }
}
```
