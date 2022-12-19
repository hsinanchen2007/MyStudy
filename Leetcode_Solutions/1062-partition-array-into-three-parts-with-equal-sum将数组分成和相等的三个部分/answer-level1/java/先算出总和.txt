```
    public boolean canThreePartsEqualSum(int[] A) {
        int totol = 0;
        for (int i : A){
            totol += i;
        }
        if (totol % 3 != 0){
            return false;
        }
        int subTotal = totol / 3;
        int sum = 0;
        int count = 0;
        for (int i : A){
            sum += i;
            if (sum == subTotal){
                sum = 0;
                count ++;
            }
        }
        return sum==0 && count==3;
    }
```
