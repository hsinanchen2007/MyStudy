class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        int len=nums.length;
        int count=1;
        ArrayList<Integer> a=new ArrayList<Integer>();
        for(int i=0;i<len;i++){
            if(nums[i]%2==1){
                a.add(count);
                count=1;
            }
            else{
                count++;
            }
        }
        //加一个结尾距离
        a.add(count);
        int res=0;
        for(int i=0;i<a.size()-k;i++){
            res+=a.get(i) * a.get(i+k);
            
        }
        return res;

    }
}