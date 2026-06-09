class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        
        List<List<String>> result = new ArrayList<>();
        
        boolean isequal = false;
        boolean iszero = true;
        
        int[] count = new int[26];
        
        for(int i=0;i<strs.length;i++)
        {
            for(int j=0;j<result.size();j++)
            {
                String str = result.get(j).get(0);
                if(str.length()==strs[i].length())
                {   
                    for(char c:str.toCharArray())
                    {
                        count[c-'a']++;
                    }
                    for(char c:strs[i].toCharArray())
                    {
                        count[c-'a']--;
                    }
                    for(int b=0;b<count.length;b++)
                    {
                        if(count[b]!=0)
                        {
                            iszero = false;
                            break;
                        }
                    }
                    if(iszero)
                    {
                        isequal = true;
                        result.get(j).add(strs[i]);
                        break;
                    }
                    iszero=true;
                    Arrays.fill(count,0);     
                }
            }
            
            if(!isequal)
            {
                List<String> temp = new ArrayList<>();
                temp.add(strs[i]);
                result.add(temp);
            }
            
            isequal=false;
        }
        
        return result;
    }
}