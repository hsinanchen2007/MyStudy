重写Comparator接口的compare方法，实现2个字符串的比较大小，Arrays类中sort()方法支持Comparator组合运用，底层基于归并排序实现。
```
class Solution {
    
    private class LargerNumberComparator implements Comparator<String>{
        @Override
        public int compare(String a,String b){
            String str1 = a + b;
            String str2 = b + a;
            return str2.compareTo(str1);
        }
    }
    
    public String largestNumber(int[] nums) {
        String[] asStr = new String[nums.length];
        for(int i=0;i<nums.length;i++){
            asStr[i] = String.valueOf(nums[i]);
        }
        
        Arrays.sort(asStr,new LargerNumberComparator());
        
        if(asStr[0].equals("0"))
            return "0";
        
        String largestNumberStr = "";
        for(int i=0;i<asStr.length;i++){
            largestNumberStr += asStr[i];
        }
        return largestNumberStr;
    }
}
```
