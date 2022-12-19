```
public int majorityElement(int[] nums) {
    int c=0,v=-1;
    for(int num:nums){
        v=c==0?num:v;
        c+=v==num?1:-1;
    }
    return v;
}
```
