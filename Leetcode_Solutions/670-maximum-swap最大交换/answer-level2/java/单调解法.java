```
class Solution {
    public int maximumSwap(int num) {
        //交换位置使最大
        //找到一位数字 存在 后面的比它大
        //后面比它大的数字 越靠后越好
        String s=num+"";
        char[] ss=s.toCharArray();
        int max=0,index=0;
        for(int i=0;i<s.length();i++){
            int res=i;
            while(res<s.length()){
                if(ss[res]>ss[i] && ss[res]>=max){
                    if(ss[res]==max && res>index){//添加条件 如果后面的两位相等 也列入并传下去
                        max=ss[res];
                        index=res;
                    }
                    max=ss[res];
                    index=res;
                }
                res++;
            }
            if(max!=0){
                char x=ss[index];
                ss[index]=ss[i];
                ss[i]=x;
                break;
            }
        }
        return Integer.parseInt(new String(ss));
    }
}
```
