成功
显示详情 
执行用时 : 167 ms, 在IPO的Java提交中击败了15.28% 的用户
内存消耗 : 45.8 MB, 在IPO的Java提交中击败了93.94% 的用户

```
class Solution {
     int ww;
    int prev=0;
    boolean all=false;
    int maxinv=0;
   
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
       System.out.println(Profits.length);
        if(k>=Profits.length)all=true;
        Map<Integer,Queue<Integer>> map = new TreeMap<Integer,Queue<Integer>>();
        
        for(int i=0 ; i<Profits.length; i++){
            if(map.get(Capital[i])==null){
                    PriorityQueue<Integer> pq = new PriorityQueue<Integer>(11,new Comparator<Integer>(){

                @Override
                public int compare(Integer o1, Integer o2) {
                    return o2.compareTo(o1);
                }

            });
                map.put(Capital[i],pq);
            }
            if(Capital[i]>maxinv)maxinv=Capital[i];
            map.get(Capital[i]).offer(Profits[i]);
            
        }
        
        int max= 0;
        
       
        ww=W;
        
       
        System.out.println("maxinv"+maxinv);
        
        while(k>0){
            k--;
             if(k%10==0){
                  System.out.println("k"+k+"ww="+ww);
             }
            if(all&&ww>=maxinv){
                sum(map);
                break;
            }else{
                 rec(Capital,map);
            }
           
        }    
        return ww;
    }
    
    public void rec(int[] CC, Map<Integer,Queue<Integer>> map){
          Set<Integer> set = map.keySet();
        Integer[] C = set.toArray(new Integer[0]);
        int x = findMax(ww,C);
        prev=x-1>0?x-1:0;
        if(x==-1){
            return;
        }
        x = findMaxVal(x,C,map);
         if(x==-1){
            return;
        }
        ww=ww+map.get(C[x]).poll();
       // System.out.println(ww+"--"+x+"--"+C[x]);
        
    }
    
      public void sum(Map<Integer,Queue<Integer>> map){
         
        for(Queue<Integer> q: map.values()){
            while(q.peek()!=null){
                  ww=ww+q.poll();
            }
        }
    }
    
    public int findMaxVal(int x,Integer[] CC, Map<Integer,Queue<Integer>> map){
        Set<Integer> set = map.keySet();
        Integer[] C = set.toArray(new Integer[0]);
        
           boolean found=false;
        int max = -1;
        int maxv=-1;
            while(x>=0){
                
                if(map.get(C[x]).peek()!=null && map.get(C[x]).peek()>maxv){
                    found=true;
                    maxv=map.get(C[x]).peek();
                    max=x;
                   
                   
                }else if(map.get(C[x]).peek()==null){
                    map.remove(C[x]);
                }
                x--;
                   
            }
            if(!found){
                return -1;
            }
        return max;
        
    }
    public int findMax(int W, Integer[] C){
       
         for(int i=prev ; i<C.length; i++){
             if(W==C[i]){
                 return i;
             }
             if(W<C[i]){
                 if(i==0)return -1;
                 return i-1;
             }
         }
        return C.length-1;
    }
     
}

public class MainClass {
    public static int[] stringToIntegerArray(String input) {
        input = input.trim();
        input = input.substring(1, input.length() - 1);
        if (input.length() == 0) {
          return new int[0];
        }
    
        String[] parts = input.split(",");
        int[] output = new int[parts.length];
        for(int index = 0; index < parts.length; index++) {
            String part = parts[index].trim();
            output[index] = Integer.parseInt(part);
        }
        return output;
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = in.readLine()) != null) {
            int k = Integer.parseInt(line);
            line = in.readLine();
            int W = Integer.parseInt(line);
            line = in.readLine();
            int[] Profits = stringToIntegerArray(line);
            line = in.readLine();
            int[] Capital = stringToIntegerArray(line);
            
            int ret = new Solution().findMaximizedCapital(k, W, Profits, Capital);
            
            String out = String.valueOf(ret);
            
            System.out.print(out);
        }
    }
}
```