执行结果：
通过
显示详情
执行用时 :
7 ms
, 在所有 java 提交中击败了
54.19%
的用户
内存消耗 :
40.6 MB
, 在所有 java 提交中击败了
69.94%
的用户
```
class Solution {
    int maxlen = 0; 
    public String largestNumber(int[] nums) {
        int len = nums.length;
        if(len==0)return "";
        StringBuffer sb = new StringBuffer();
        
        int max = 0; 
        for(int i = 0; i < len ; i++) {
            if(nums[i] > max) max = nums[i];
        }
        maxlen = String.valueOf(max).length();
         

        List<String> strs = new ArrayList<>();
        for(int i=0 ; i < len ; i++) {
            strs.add(String.valueOf(nums[i]));
        }

        process(strs,0).forEach(sb::append);
        //处理00001
        while(sb.charAt(0)=='0' && sb.length()>1){
            sb = new StringBuffer(sb.substring(1,sb.length()));
        }
        return sb.toString();
    
     }
     public List<String> process(List<String> list, int index){
         //处理1，1，1
        if(index > maxlen) return list;
        //处理12，121
        if (list.size() <=1 ) {
            return list;
        }
        int indexp1 = index + 1;
        Map<Integer,List<String>> map = new HashMap<>();
        for(int i = 0 ; i < 10 ; i++){
            map.put(Integer.valueOf(i),new ArrayList<String>());
        }
        //9,95,954,9548,993,9594
        for(String str : list) {
            if(str.length() >= indexp1) {
                map.get(str.charAt(index)-48).add(str);
            } else {
                //map.get(str.charAt(0)-48).add(str);
                map.get(str.charAt(index%str.length())-48).add(str);
            }
        }

        List<String> res = new ArrayList<>();
        for(int i = 9 ; i >=0 ; i--) {
            res.addAll(process(map.get(i),indexp1));
        }
        return res;
     }
}
```
