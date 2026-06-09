好几种case 一开始没考虑到= =...
```
class Solution {
    public List<String> removeComments(String[] source) {
        List<String> res = new ArrayList<>();
        for(int i=0; i<source.length; i++){
            
            int startBlock = source[i].indexOf("/*");
            int startLine = source[i].indexOf("//");
            
            if(startBlock>=0 && (startLine<0 || startBlock < startLine)){
                
                String s = source[i].substring(0, startBlock);
                source[i] = source[i].substring(startBlock+2);  
                while(source[i].indexOf("*/") == -1){
                    i++;
                }
                int blockEnd = source[i].indexOf("*/");
                source[i]= s + source[i].substring(blockEnd+2);
                i--;
            }


            else if(startLine>=0 && (startBlock<0 || startLine < startBlock)){
                source[i] = source[i].substring(0, startLine);  
                i--; 
            }
            
            else{
                if(!source[i].isEmpty()){  
                    res.add(source[i]);
                }
            }
        }
        return res;   
    }
}
```