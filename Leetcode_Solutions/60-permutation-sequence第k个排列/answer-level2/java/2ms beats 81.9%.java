```
class Solution {
    public String getPermutation(int n, int k) {
        String result = "";
        //0-9个数字情况下排列的个数
        int[] factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        //备选数字集合，放0占位后面取方便
        List<Integer> select = new ArrayList<>();
        select.add(0);
        for(int i = 0; i < n; i++){
            select.add(i + 1);
        }
        //如果n==1说明只剩下一个数字没取了，不用循环了
        //如果k==1说明剩下的数里面从小的开始取就够了，也不用循环了
        while(n > 1 && k > 1){
            //当前位后面有多少个排列
            int onePermutation = factorial[n - 1];            
            int nth = 0;
            //如果整除其实是取该位置后面的的最后一个排列，但是这个位置的数字不能再加了
            //如果有余数说明这个位置下一个数
            if(k % onePermutation == 0){
                nth = k / onePermutation;
            }else{
                nth = k / onePermutation + 1;
            }
            //取完数字之后把这个数字从备选集合中去掉
            result += select.get(nth);
            select.remove(nth);
            //k变成剩下的数字里面取第k个排列
            k = k - onePermutation * (nth - 1);
            n--;
        }
        //把剩下没取的数字都按顺序取出来排在后面
        for(int i = 1; i < select.size(); i++){          
            result += select.get(i);          
        }
        return result;
    }
    
}
```
