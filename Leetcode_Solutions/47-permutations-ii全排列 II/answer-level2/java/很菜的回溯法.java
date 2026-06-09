### 解题思路
朴实无华的回溯法
### 代码

```java
class Solution {
    private List<List<Integer>>res;
    public List<List<Integer>> permuteUnique(int[] nums) {
        this.res=new ArrayList<>();
        List<Integer>tmp=new ArrayList<>();
        boolean[] Mask0=new boolean[nums.length];
        Arrays.fill(Mask0,false);
        _Work(tmp,nums,Mask0,0);
        return res;
    }
    private void _Work(List<Integer> tmp, int[] nums, boolean[] Mask0,int lever) {
        Map<Integer,Boolean> Mask=new HashMap<Integer, Boolean>();
        if(lever==nums.length){
            this.res.add(new ArrayList<>(tmp));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(Mask0[i]==true||Mask.get(nums[i])!=null)
                continue;
            tmp.add(nums[i]);
            Mask0[i]=true;
            Mask.put(nums[i],true);
            _Work(tmp,nums,Mask0,lever+1);
            Mask0[i]=false;
            tmp.remove(lever);
        }
    }
}
```