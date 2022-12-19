    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {


        int sum=0;
        
        Map<Integer,Integer> map1=calculate(A,B);
        Map<Integer,Integer> map2=calculate(C,D);
        
        for(int x: map1.keySet()){
            
            if(map2.containsKey(-x)){
                
                
                sum=sum+map1.get(x)*map2.get(-x);
                
                
            }
   
        }
        
        return sum;




    }
    
    public Map<Integer,Integer> calculate(int[] a, int[] b){
        
        int k=a.length;

        Map<Integer,Integer> map=new HashMap<>();
        
        for(int i=0; i<k; i++){
            
            for(int j=0; j<k; j++){
                
                int x=a[i]+b[j];
                map.put(x,map.getOrDefault(x,0)+1);
                
            }
   
            
        }
        
        return map;
        
        
    }