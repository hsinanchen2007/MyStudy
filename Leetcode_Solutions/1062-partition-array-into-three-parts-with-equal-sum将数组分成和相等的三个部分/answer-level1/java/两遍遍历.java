```
    public boolean canThreePartsEqualSum(int[] A) {
        //先计算所有元素之和，如果结果不能被3整除，则返回false；
        int sum = 0;
        for(int i : A) sum+=i;
        if(sum % 3 > 0) return false;
        //计算每部分的和，验证是否能正确划分
        sum /= 3;
        int section = 0, secSum = 0,max = A.length -1;
        for(int i = 0; i <= max; i++){
            secSum += A[i];
            //如当前部分和等于目标值，则当前部分能被正确划分，继续验证剩余部分
            if(secSum == sum){
                section++;
                //如果已正确划分2部分，且当前没有遍历完，则剩余部分一定可以正确划分，可以提前结束遍历
                if(section == 2 && i < max) return true;
                secSum = 0;
            }
        }
        return section == 3;
    }
```
