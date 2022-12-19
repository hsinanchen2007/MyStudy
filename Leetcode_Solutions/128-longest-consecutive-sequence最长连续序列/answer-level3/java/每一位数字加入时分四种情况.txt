执行结果：
通过
显示详情
执行用时 :
38 ms
, 在所有 Java 提交中击败了
13.38%
的用户
内存消耗 :
41.4 MB
, 在所有 Java 提交中击败了
16.95%
的用户
```
class Solution {
   	public int longestConsecutive(int[] nums) {
        int len = nums.length;
        if(len==0)return 0;
        Map<Integer,Integer> map = new HashMap<>();
        Map<Integer,Integer> map1 = new HashMap<>();
        int max=0;
        for(int i=0;i<len;i++){
            if(map.get(nums[i])!=null)continue;
            Integer x1 = map.get(nums[i]+1);
            Integer x2 = map.get(nums[i]-1);
            if(x1!=null&&x2!=null&&x1>0&&(x2<0||x2==1)){
                int nx = x1-x2+1;
                if(x2==1)nx=x1+x2+1;
                 
                if(nx>max)max=nx;
                int end=map1.get(nums[i]+1);
                map.put(end,nx*-1);
                if(x1!=1){
                    map.remove(nums[i]+1);
                     map1.remove(nums[i]+1);
                }
               
                int start = map1.get(nums[i]-1);
                map.put(start,nx);
                if(x2!=1){
                    map.remove(nums[i]-1);
                     map1.remove(nums[i]-1);
                }
                map1.put(start,end);
                map1.put(end,start);
                
            }else if(x1!=null&&x1>0){
                int nx = 1+x1;
                if(nx>max)max=nx;
                int end=map1.get(nums[i]+1);
                map.put(end,nx*-1);
                map.put(nums[i],nx);
                if(x1!=1){
                    map.remove(nums[i]+1);
                    map1.remove(nums[i]+1);
                }
                map1.put(nums[i],end);
                map1.put(end,nums[i]);
            }else if(x2!=null&&(x2<0||x2==1)){
                int nx = 1-x2;
                 if(x2==1)nx=2;
                if(nx>max)max=nx;
                int start = map1.get(nums[i]-1);
                map.put(start,nx);
                map.put(nums[i],nx*-1);
                if(x2!=1){
                    map.remove(nums[i]-1);
                    map1.remove(nums[i]-1);
                }
                map1.put(start,nums[i]);
                map1.put(nums[i],start);
            }else if(x1==null&&x2==null){
                map.put(nums[i],1);
                map1.put(nums[i],nums[i]);
                if(max==0)max=1;
            }
        }
        return max;
    }
}
```
