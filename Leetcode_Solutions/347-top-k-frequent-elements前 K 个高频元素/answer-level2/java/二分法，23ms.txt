class Solution {

    public List<Integer> topKFrequent(int[] nums, int k) {
        List<Integer> list = new ArrayList<>(); 
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(map.containsKey(nums[i])){
                map.put(nums[i],map.get(nums[i])+1);
            }else{
                map.put(nums[i],1);
            }
        }
        //System.out.println(map.toString());
        for(int key:map.keySet()){
            int begin=0;
            int end=list.size()-1;
            if(end==-1){
                list.add(key);
                continue;
            }
            //System.out.println(list.toString());
            while(end-begin>1){
                int times=map.get(list.get((begin+end)/2));
                if(times>=map.get(key)){
                    begin=(begin+end)/2;
                }else if(times<map.get(key)){
                    end=(begin+end)/2;
                }
            }
            if(map.get(key)>map.get(list.get(0))){
                list.add(0,key);
            }else if(map.get(key)<map.get(list.get(list.size()-1))){
                list.add(key);
            }else{
                list.add(begin+1,key); 
            }
            if(list.size()>k)list.remove(list.size()-1);
        }
        return list;
    }

}