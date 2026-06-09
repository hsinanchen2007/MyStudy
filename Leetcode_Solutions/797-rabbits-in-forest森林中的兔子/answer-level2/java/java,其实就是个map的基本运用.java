class Solution {
    public int numRabbits(int[] answers) {
        //报的数量小于等于 
        HashMap<Integer,Integer> map = new HashMap<>();
        int result=0;
        
        for(int rabit: answers){
            if(map.get(rabit)!=null){
                map.put(rabit,map.get(rabit)+1);
            }else{
                map.put(rabit,1);
            }
        }
        
        //构建好map后开始遍历map
        //开始遍历map，分两种情形，当map.get(rabit)<=rabit+1,return rabit+1
        //当map.get(rabit)>rabit+1,递归的解决
        
        for(Map.Entry<Integer, Integer> entry: map.entrySet())
            {
                if(entry.getValue()<=entry.getKey()+1){
                    
                    result += (entry.getKey()+1); 
                }else{
                    // 1,1,1,1,1
                    result += (entry.getValue()/(entry.getKey()+1)*(entry.getKey()+1));
                    if((entry.getValue()%(entry.getKey()+1))!=0){
                         result += (entry.getKey()+1);
                        }   
                    }
            }
        return result;
    }
}