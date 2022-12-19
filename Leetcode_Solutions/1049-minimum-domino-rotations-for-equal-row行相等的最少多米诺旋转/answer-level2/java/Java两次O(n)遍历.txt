第一次遍历先找到那个数字，数字出现的一定大于或等于数组长度。如果没有数组大于等于数组长度，则返回-1。
第二次遍历根据那个数字，找到最少需要的反转次数。需要注意的是最后要减去A，B两个数组同时出现这个数字的情况。
```
class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        int num = A.length;
        //第一次遍历，找到那个数字
        int[] six = new int[6];
        for(int i = 0; i < num; i++){
            six[A[i]-1]++;
            six[B[i]-1]++;
        }
        int flag = 0;
        int DomNum = 0;
        for(int i = 0 ;i < 6; i++){
            //如果那个数字出现的次数超过数组的次数，那就一定是那个数字，不然就找不到解法
            if(six[i] >= num){
                flag = 1;
                DomNum = i+1;
                break;
            }
        }
        if(flag == 0)
            return -1;
        //找到这个数字之后，一次遍历找到最少次数
        int Anum = 0, Bnum = 0, com = 0;
        for(int i = 0; i < num; i++){
            if(A[i] == DomNum && B[i] == DomNum){
                Anum++;
                Bnum++;
                com++;
            }
            else if(A[i] == DomNum)
                Anum++;
            else if(B[i] == DomNum)
                Bnum++;
            else   
                return -1;
        }
        return Math.min(Anum, Bnum)-com;
    }
}
```
