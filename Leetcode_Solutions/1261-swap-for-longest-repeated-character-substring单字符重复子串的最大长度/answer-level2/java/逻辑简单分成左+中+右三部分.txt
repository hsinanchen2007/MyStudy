首先，将字符串转换成数字数组。
初始定以left=0,right=0；
例如，对于‘c,c,a,b,a,b,a,a’这样的一个数组，可以从左往右遍历，找到第一个a并计数,left++，第一次遇到不同字母后，若下一位是相同字母，则给right计数。这里left=1后，对right计数，right=1;
从第二次遇到不同字母开始，不断left=right，right=0；并重新对不同字母后的right进行计数。
即,left=right=1;right=0;第二个b之后，有2个a,因此right=2;
并且a的总数为4，大于left+right,因此，最终max=left+right+1=4；
注意：
（1）中间连续两次遇到不同字母，left与right都会变0；
（2）计算是否有剩余的字母填充，若有，结果为left+right+1；否则left+right
```
class Solution {
    public int maxRepOpt1(String text) {
        if(text.length()==1) return 1;
        int[] res=new int[26];
        int[] ans=new int[text.length()];
        for(int i=0;i<text.length();i++){
            ans[i]=text.charAt(i)-'a';
            res[ans[i]]++;
        }
        int max=0;
        for(int i=0;i<26;i++){
            boolean re=true;
            if(res[i]>0){
                int start=0;
                while(ans[start]!=i) start++;
                int left=0;
                int right=0;
                for(int j=start;j<ans.length;j++){
                    if(ans[j]==i&&re==true){
                        left++;
                    }else if(ans[j]==i&&re==false){
                        right++;
                    }else if(re==true){
                        re=false;
                    }else{
                        if(res[i]-left-right>=1){
                            max=Math.max(max,left+right+1);
                            left=right;
                            right=0;
                        }else{
                            max=Math.max(max,left+right);
                            break;
                        }
                    }
                }
                if(res[i]-left-right>=1){
                    max=Math.max(max,left+right+1);
                }else{
                    max=Math.max(max,left+right);
                }
            }
        }
        return max;
    }
}
```
