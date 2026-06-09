如数组内包含 [4,5,1,2,3],n1 = 4,n2 = 5,n3 = 1,当遇到2时转换即可
```
int len = nums.length;
int n1 = Integer.MAX_VALUE;
int n2 = Integer.MAX_VALUE;
int n3 = Integer.MAX_VALUE;   //待用
for(int i=0;i<len;i++){
    int v = nums[i];
    if(v< n1){
        if(n2 == Integer.MAX_VALUE)
            n1 = v;
        else if(v < n3)
            n3 = v;
        else{
            n1 = n3;
            n2 = v;
            n3 = Integer.MAX_VALUE;
        } 
    }else if(v > n1){
        if(v < n2)
            n2 = v;
        else if(v > n2)
            return true;
    }
}
return false;
```
