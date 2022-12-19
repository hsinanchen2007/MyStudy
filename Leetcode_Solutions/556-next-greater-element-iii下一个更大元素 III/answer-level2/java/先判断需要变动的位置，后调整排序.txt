```
class Solution {
public int nextGreaterElement(int n) {
        HashMap<Integer,Integer> hm=new HashMap<>();
        char[] chars=(""+n).toCharArray();
        hm.put(Integer.valueOf(""+chars[chars.length-1]),chars.length-1);
        for(int i=chars.length-2;i>=0;i--){
            if(chars[i]-chars[i+1]<0){//递减检查到了
                for(int j=Integer.valueOf(""+chars[i])+1;j<10;j++){
                    if(hm.containsKey(j)){
                        chars[hm.get(j)]=chars[i];
                        chars[i]=(char) (j+'0');
                        break;
                    }
                }
                Arrays.sort(chars,i+1,chars.length);
                String str="";
                for(char sin:chars){
                    str+=sin;
                }
                long num=Long.valueOf(str);
                return (num>Integer.MAX_VALUE?-1:(int)num);
            }else if(chars[i]-chars[i+1]>0){
                hm.put(Integer.valueOf(""+chars[i]),i);
            }
        }
        return -1;
    }
}
```
