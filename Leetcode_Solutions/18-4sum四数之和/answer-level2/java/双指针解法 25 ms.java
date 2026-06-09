class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
       List<List<Integer>> listl = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for(int i = 0;i<=nums.length-4;i++){
            int i1 = i+1,i3=nums.length-1,i2 = i3-1;
            while(i1<i2&&i3>=3){
                if(nums[i]+nums[i1]+nums[i2]+nums[i3]<target){
                    if(i2==i1+1){
                        i2=i3-1;
                    }
                    i1++;
                }else if(nums[i]+nums[i1]+nums[i2]+nums[i3]>target){
                    if(i2==i1+1){
                        i3--;
                        i2=i3-1;
                        i1 = i+1;
                    }else {
                        i2--;
                    }
                }else if(nums[i]+nums[i1]+nums[i2]+nums[i3]==target){
                    List<Integer> listi = new ArrayList<Integer>();
                    listi.add(nums[i]);
                    listi.add(nums[i1]);
                    listi.add(nums[i2]);
                    listi.add(nums[i3]);
                    if(!listl.contains(listi)) {
                        listl.add(listi);
                    }
                    i1++;
                    i2=i3-1;
                }
            }
        }
        return listl;
    }
}