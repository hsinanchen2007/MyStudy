/*
用进制 11111... 表示 
假设数字n最好进制是k 则存在整数i 使得(Math.pow(k,i)-1)/(k-1)=n成立
(等比数列求和公式)
而所有的k一定能被 n-1 整除

*/
class Solution {
    public String smallestGoodBase(String n) {
        Long num = Long.valueOf(n);
        List<Long> nums = find(num-1);//求出所有能被n-1整除的数
        A: for (Long nu : nums) {
            if (nu <= 1) {continue A;}//1过滤掉
            Long i = 1L, max;
            while (true){
                max = (long) (Math.pow(nu,i)-1)/(nu-1);
                if (max.longValue() == num.longValue()){
                    System.out.println(nu);
                    return String.valueOf(nu);}
                if (max > num){continue A;}
                i++;
            }
        }
      return String.valueOf(num);
    }
  private static List<Long> find(Long num){
        List<Long> nums = new LinkedList<>();
        for(long i = 1; i <= Math.sqrt(num); i++){
            if (num%i == 0) {
                nums.add(i);
                nums.add(num/i);
            }
        }
        nums.sort(Comparator.comparing(Long::longValue));//排序从小到大
        return nums;
    }
}