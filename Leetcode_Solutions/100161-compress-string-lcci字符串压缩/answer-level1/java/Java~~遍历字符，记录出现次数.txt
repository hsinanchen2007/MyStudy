```
class Solution {
    public String compressString(String S) {
        char[] cs = S.toCharArray();

        StringBuilder sb = new StringBuilder();
        char last = ' ';
        int nums = 0;

        for(int i=0;i<cs.length;i++){
            char ch = cs[i];

            if(i==0){
                sb.append(String.valueOf(ch));
                nums++;
            }else if(i==cs.length-1){
                if(last==ch){
                    nums++;
                    sb.append(String.valueOf(nums));
                }else{
                    sb.append(String.valueOf(nums));
                    sb.append(String.valueOf(ch));
                    sb.append("1");
                }
            }else{
                if(ch == last){
                    nums++;
                }else{
                    sb.append(String.valueOf(nums));
                    sb.append(String.valueOf(ch));
                    nums=1;
                }
            }

            last=ch;
        }

        return sb.toString().length()<S.length()?sb.toString():S;
    }
}
```