```

public boolean canThreePartsEqualSum(int[] A) {
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    for(int i:A){   //求出数组和
        sum +=i;
    }
    if(sum%3!=0){   //和必须为3的倍数
        return false;
    }

    int k1 = 0;     //第一组末位下标
    for(int i =0;i<A.length;i++){
        sum1+=A[i];
        if(sum1==sum/3){
            k1 = i; 
            break;
        }
            
    }
    for(int j =0;j<A.length-1;j++){
        sum2+=A[j];
        if(sum2==(sum/3)*2&&j>k1){
            return true;
        }
    }
    return false;
}

```
