执行用时 :18 ms, 击败了47.83%的用户。
内存消耗 :53.1 MB, 击败了33.33%的用户。
```
class Solution {
    public int[] threeEqualParts(int[] A) {
        int[] res = new int[]{-1,-1};
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < A.length; i++){
            if(A[i]==1){
                list.add(i);
            }
        }
        //整个数组都为0，任意位置都行
        if(list.size()==0){
            res[0] = 0;
            res[1] = 2;
            return res;
        }
        //1的个数不是3的倍数，肯定无法实现
        if(list.size()%3 != 0){
            return res;
        }
        int size = list.size()/3;
        for(int i = 1; i < size; i++){
            int t = list.get(i) - list.get(i-1);
            //分成3部分的数字中，1的间隔有不同的情况，肯定无法实现
            if((list.get(i + size) - list.get(i + size-1) != t) || (list.get(i + 2*size) - list.get(i + 2*size-1) !=t)){
                return res;       
            }
        }
        if(A[A.length-1] == 0){
            //末尾为0，需要判断三个部分之间的0是否足够，比如0，1，0，1，0，0，1，0，1，0，0，1，0，1，0
            //第三组数为1，0，1，0 ；所以要判断前两组数0，1，0，1，0，0和1，0，1，0，0末尾是否至少有一个0
            int z = A.length - 1 - list.get(list.size()-1);
            if((z <= list.get(2*size) - 1 - list.get(2*size-1)) && (z <= list.get(size) - 1 - list.get(size-1))){
                res[0] = list.get(size-1) + z;
                res[1] = list.get(2*size - 1) + z + 1;
            }
        }else{
            //末尾为1，肯定能实现，比如0，0，1，0，1，0，0，0，1，0，1，0，1，0，1 
            //只要把除了1，0，1之外的0全部当作前导0，无论它们之间有多少个0，都能分开成3个1，0，1
            res[0] = list.get(size-1);
            res[1] = list.get(2*size-1)+1;
        }
        return res;
               
    }
}
```
