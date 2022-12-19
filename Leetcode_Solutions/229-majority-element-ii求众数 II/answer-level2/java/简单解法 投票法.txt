
```
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        List<Integer> res = new ArrayList<>();

        
        int c1 = 0;
        int c2 = 0;
        Integer res1 = null;
        Integer res2 = null;
        
        for(int i : nums) {
            if(c1 == 0 && c2 == 0) {
                res1 = i;
                c1 = 1;
            }else if(c1 != 0 && c2 != 0) {
                if(i == res1) {
                    c1++;
                }else if(i == res2) {
                    c2++;
                }else {
                    c1--;
                    c2--;
                }
            }else if (c1 != 0) {//意味着c2 == 0
                if(i == res1) {
                    c1++;
                }else {
                    res2 = i;
                    c2 = 1;
                }
                
            }else if(c2 != 0) {//意味着c1 == 0
                if(i == res2) {
                    c2++;
                }else {
                    res1 = i;
                    c1 = 1;
                }
            }
            
            
        }
        
        //验证
        c1 = 0;
        c2 = 0;
        for(int i : nums) {
            if(i == res1) {
                c1++;
            }else if(i == res2) {
                c2++;
            }
        }
        
        if(c1 > n / 3) {
            res.add(res1);
        }
        if(c2 > n / 3) {
            res.add(res2);
        }
        return res;
        
    }
}
```
优化写法: 
```
for(int i : nums) {
    if((c1 == 0 || res1 == i) && i != res2) {
        c1++;
        res1 = i;
    }else if(c2 == 0 || res2 == i) {
        c2++;
        res2 = i;
    }else {
        c1--;
        c2--;
    }
}
```
