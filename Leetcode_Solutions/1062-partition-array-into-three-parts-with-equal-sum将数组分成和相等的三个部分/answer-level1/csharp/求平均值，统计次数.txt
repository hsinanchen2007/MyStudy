```
public bool CanThreePartsEqualSum(int[] A) {
        var sum=0;
        foreach(var n in A){
            sum+=n;
        }
        if(sum%3!=0){
            return false;
        }
        sum/=3;
        int t=0,count=0;
        foreach(var n in A){
            t+=n;
            if(t==sum){
                count++;
                t=0;
            }
        }
        return count==3;
    }
```
