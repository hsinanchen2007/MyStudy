类似的还有力扣179题
思路
1将输入的数组按照某个顺序排序，然后按顺序组合就是最大数。

2这个顺序的目的是实现组合后较小的数字在前面。

3所以排序的比较算法应该是对组合后的数字进行比较。

```java []
class Solution {
    public String minNumber(int[] nums) {
        String[] str = new String[nums.length];
        for(int i = 0; i < nums.length; i++){
            str[i] = String.valueOf(nums[i]);
        }

        //o1在前为从小到大
        Arrays.sort(str, new Comparator<String>(){
            @Override
            public int compare(String o1, String o2){
                return (o1 + o2).compareTo(o2 + o1);
            }
        });
        StringBuilder sb = new StringBuilder();
        for(String num : str){
            sb.append(num);
        }
        return sb.toString();

    }
}