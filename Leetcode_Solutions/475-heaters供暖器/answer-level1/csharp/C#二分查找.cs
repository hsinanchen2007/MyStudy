```c# []
 public int FindRadius(int[] houses, int[] heaters) {
        int near=0;
        Array.Sort(heaters);
        
        for(var i=0;i<houses.Length;i++){
            var pos=houses[i];
            var minLen=int.MaxValue;
            
            var t1=BS(heaters,0,heaters.Length-1,pos);
            
            var v1=heaters[t1];
        
            int v3=0;
            
            if(t1-1>=0){
                v3=heaters[t1-1];
            }else{
                v3=heaters[0];
            }
            
            if(Math.Abs(pos-v1)<minLen){
                minLen=Math.Abs(pos-v1);
            }
            
            if(Math.Abs(pos-v3)<minLen){
                minLen=Math.Abs(pos-v3);
            }
            
           if(minLen>near){
               near=minLen;
           }
        }
       
        return near;
    }
    
    int BS(int[] h,int l,int r,int t){
        if(r-l<=1){
            return r;
        }
        var mid=(l+r)/2;
        if(h[mid]>t){
            return BS(h,l,mid,t);
        }
        else{
            return BS(h,mid,r,t);
        }
    }
```

