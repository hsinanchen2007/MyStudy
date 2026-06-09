```java []
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
            List<Integer> res = new ArrayList<Integer>();
            for(int i = left;i<=right;i++){
                //数字转化成字符数字
                char[] chars = String.valueOf(i).toCharArray();
                //System.out.println(Arrays.toString(chars));
                boolean sign = true;
                for(char e:chars){
                    //字符数字转化成数字
                    int temp =(e-48);
                    if(temp ==0 || i%(temp)!=0){
                        sign = false;
                        break;
                    }
                }
                if(sign){
                 res.add(i);
                }
                
            }
        return res;
    }
}
```

