执行结果：
通过
显示详情
执行用时 :
47 ms
, 在所有 Java 提交中击败了
80.33%
的用户
内存消耗 :
38.6 MB
, 在所有 Java 提交中击败了
89.26%
的用户
```
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
       Arrays.sort(nums);
        if(nums==null||nums.length==0)return res;
        int len = nums.length;
        long tt = target;
        for(int i=0 ; i<len-3; i++){
            boolean f1=false;
            for(int j=i+1 ; j<len-2; j++){
                boolean found = false;
                long ij = nums[i]+nums[j];
                int s=j+1;
                int e=len-1;
                while(s<e){
                    // System.out.print(nums[s]+"_"+nums[e]+"_"+tt);
                    // System.out.println(ij+nums[s]+nums[e]);
                    
                    if(ij+nums[s]+nums[e]==tt){
                        List<Integer> list = new ArrayList<Integer>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[s]);
                        list.add(nums[e]);
                      //  System.out.println(i+"_"+j+"_"+s+"_"+e);
                        res.add(list);
                        found=true;
                        f1=true;
                        s++;
                        e--;
                        while(s<e&&nums[s]==nums[s-1]){s++;}
                        while(s<e&&nums[e]==nums[e+1]){e--;}
                        
                    }else if(ij+nums[s]+nums[e]>tt){
                        // System.out.println("ddd");
                        e--;
                    }else if(ij+nums[s]+nums[e]<tt){
                        // System.out.println("eee");
                        s++;
                    }
                    
                }
                if(found){
                    
                    while(j<len-2&&nums[j]==nums[j+1]){
                        j++;
                    }
                }
            }
            if(f1){
                while(i<len-3&&nums[i]==nums[i+1]){
                    i++;
                }
            }
        }
        return res;
    }
}
```