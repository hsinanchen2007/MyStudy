### 解题思路
for word in words;
遍历word大小的循环，每次遍历整个s，维持窗口左索引,窗口最大 size=word.length * words.length

处理窗口匹配的三种情况。。
完全匹配，去除第一个word
无法匹配，清除，更新窗口左索引到当前窗口右索引
word次数超出，while循环依次去除窗口左边的word，直到次数等于dict中的次数


### 代码

```java
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        //处理边界条件


         List<Integer> ans=new ArrayList();

         if(s.length()==0 || words.length==0) return ans;

        //获取word的长度
        int wl=words[0].length();
        int len=words.length;
        int sl=s.length();


        if(s.length()<len*wl){
            return ans;
        }

        Map<String,Integer> dict=new HashMap();
        Map<String,Integer> count=new HashMap();
        for(String word:words){
            dict.put(word,dict.getOrDefault(word,0)+1);
        }
       
        String t="",tmp="";
        //总共遍历wl次，每次遍历s字符串全部
        for(int i=0;i<wl;i++){
            //左索引
            int l=i;
            //窗口区间匹配次数
            int match=0;
            count.clear();
            //采用滑动窗口，j为右索引
            for(int j=i;j<=sl-wl;j+=wl){
                t=s.substring(j,j+wl);
                //三种情况
                if(dict.containsKey(t)){
                    count.put(t,count.getOrDefault(t,0)+1);
                    match++;
                    // 3. 某word次数超出
                    if(count.get(t)>dict.get(t)){
                        while(count.get(t)>dict.get(t)){
                            tmp=s.substring(l,l+wl);
                            count.put(tmp,count.get(tmp)-1);
                            l+=wl;
                            match--;
                        }
                    }
                    //System.out.println(match+"   "+l+"   "+i+"   "+j);
                   // 1.完全匹配
                    if(match==len){
                        match-=1;
                        tmp=s.substring(l,l+wl);
                        count.put(tmp,count.get(tmp)-1);
                        //添加结果
                        ans.add(l);
                        l+=wl;
                    }

                }else{
                  //2. 无法匹配
                  match=0;
                  count.clear();
                  l=j+wl;
                }
            }          
        }
        return ans;





    }
}
```