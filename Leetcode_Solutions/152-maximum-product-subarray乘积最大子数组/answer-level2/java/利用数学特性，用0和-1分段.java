执行结果：
通过
显示详情
执行用时 :
4 ms
, 在所有 Java 提交中击败了
72.21%
的用户
内存消耗 :
36.6 MB
, 在所有 Java 提交中击败了
44.15%
的用户
```
class Solution {
    public int maxProduct(int[] nums) {
        int len = nums.length;
        if(len==0)return 0;
       
        int max = Integer.MIN_VALUE;
        int lastZero=0;
        List<Integer> set = new ArrayList<Integer>();
        for(int i=0;i<len;i++){
            if(nums[i]==0){
                if(i>lastZero){
                    int val = get(nums,lastZero,i-1,set);
                    if(val>max)max=val;
                    lastZero=i+1;
                    set = new ArrayList<Integer>();
                }else if(i==lastZero){
                     lastZero=i+1; 
                }
            }else if(nums[i]<0){
                  set.add(i);
            }
            if(max<nums[i])max=nums[i];
        }
        int v = get(nums,lastZero,len-1,set);
        if(v>max)max=v;
        return max;
    }
    private int get(int[] nums, int s, int e,List<Integer> set){
        if(s>e)return Integer.MIN_VALUE;
        int res = 1;
        if(set==null||set.size()%2==0){
            for(int i=s; i<=e; i++){
                res*=nums[i];
            }
            return res;
        }else if(set.size()>2){
            int h1= get(nums,s,set.get(set.size()-1)-1,null);
            int h2 = get(nums,set.get(0)+1,e,null);
            return h1>h2?h1:h2;
        }else if(set.size()==1){
            int h1= get(nums,s,set.get(0)-1,null);
            int h2 = get(nums,set.get(0)+1,e,null);
            return h1>h2?h1:h2;
        }
        return Integer.MIN_VALUE;
    }
}
```
