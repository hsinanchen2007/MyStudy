```
class Solution {
    public String largestNumber(int[] nums) {
        List<String> tmp = sort(nums,0,nums.length-1);
        StringBuilder sb = new StringBuilder();
        if(tmp.get(0).equals("0")) return "0";  ///防止全是0！！！！是个坑！！！！
        for(String s:tmp) sb.append(s);
        return sb.toString();
    }
    /*
    **归并排序。。。不解释了！！！！
    */
    private List<String> sort(int[] nums, int s, int e){
        ArrayList<String> res = new ArrayList();
        if(e==s) res.add(String.valueOf(nums[s]));
        else if(e-s==1){
            String s1 = String.valueOf(nums[s]);
            String s2 = String.valueOf(nums[e]);
            if(ok(s1,s2)>=1){
                res.add(s1);res.add(s2);
            }else{
                res.add(s2);res.add(s1);
            }
        }else{
            List<String> l1 = sort(nums,s,(s+e)/2);
            List<String> l2 = sort(nums,(s+e)/2+1,e);
            int i1=0,i2=0;
            while( i1<l1.size() && i2<l2.size() ){
                if(ok(l1.get(i1),l2.get(i2))>0){
                    res.add(l1.get(i1));i1++;
                }else if(ok(l1.get(i1),l2.get(i2))<0){
                    res.add(l2.get(i2));i2++;
                }else{
                    res.add(l1.get(i1));i1++;
                    res.add(l2.get(i2));i2++;
                }
            }
            while(i1<l1.size()) {
                res.add(l1.get(i1));i1++;
            }
            while(i2<l2.size()){
                res.add(l2.get(i2));i2++;
            } 
        }
        return res;
    }
    /*
    **定义了一种比较器！！！
    **返回1时 n1>n2
    **返回-1时 n1<n2
    **返回0时 n1==n2
    **n1和n2哪个大哪个排在前面
    */
    private int ok(String n1, String n2){
        char[] c1 = n1.toCharArray();
        char[] c2 = n2.toCharArray();
        for(int i=0;i<c1.length+c2.length;i++){
            if( (i<c1.length?c1[i]:c2[i-c1.length]) < (i<c2.length?c2[i]:c1[i-c2.length]) ) return -1;
            if(  (i<c1.length?c1[i]:c2[i-c1.length]) > (i<c2.length?c2[i]:c1[i-c2.length])  ) return 1;
        }
        return 0;
    }
}
```
