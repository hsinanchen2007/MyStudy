class Solution {
    
    List<List<Integer>> l = new ArrayList();
    public List<List<Integer>> subsets(int[] nums) { 
        helper(0,nums);
        return l;
    }

    public void helper(int begin,int[] nums){
        if(begin==nums.length){
            l.add(new ArrayList());
            return;
        }
        helper(begin+1,nums);
        List<List<Integer>> ll = new ArrayList();
        for(int i=0;i<l.size();i++){
            List<Integer> x =  l.get(i);
            x.add(nums[begin]);
            ll.add(new ArrayList<>(x));//用x构造新的list作为参数
            x.remove(x.size()-1); //这一步很关键  
        }
        l.addAll(ll); 
    }

}